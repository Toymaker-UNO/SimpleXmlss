#ifndef SIMPLE_XMLSS_WRITER_CELL_HPP
#define SIMPLE_XMLSS_WRITER_CELL_HPP

#include "simple_xmlss_model_cell.hpp"
#include "simple_xmlss_utility_inline_functions.hpp"
#include "simple_xmlss_builder_font.hpp"
#include "simple_xmlss_builder_style.hpp"

namespace simple_xmlss {

namespace writer {

class cell {
public:
  void print_xmlss(model::cell& a_cell,
                   FILE* a_file) {
    if (true == a_cell.configuration.merge_flag) {
      return;
    }

    if (false == a_cell.status_flag.string_flag &&
        false == a_cell.status_flag.number_flag &&
        false == a_cell.status_flag.date_time_flag &&
        false == a_cell.status_flag.formula_flag &&
        false == a_cell.status_flag.comment_flag &&
        false == a_cell.status_flag.hyperlink_flag &&
        false == a_cell.status_flag.style_flag) {
      return;
    }

    simple_xmlss_fprintf(a_file, "    <Cell ss:Index=\"%u\"", a_cell.configuration.coordinate.col );
    
    if (0 != a_cell.style_id) {
      simple_xmlss_fprintf(a_file, " ss:StyleID=\"%s\"", utility::get_style_id_string(a_cell.style_id).c_str());
    }
      
    if (true == a_cell.status_flag.hyperlink_flag) {
      simple_xmlss_fprintf(a_file, " ss:HRef=\"%s\"", utility::std_string2xml_string(a_cell.hyperlink).c_str());
    }

    if (0 < a_cell.configuration.merge_across) {
      simple_xmlss_fprintf(a_file, " ss:MergeAcross=\"%u\"", a_cell.configuration.merge_across);
    }

    if (0 < a_cell.configuration.merge_down) {
      simple_xmlss_fprintf(a_file, " ss:MergeDown=\"%u\"", a_cell.configuration.merge_down);
    }

    if (true == a_cell.status_flag.formula_flag) {
      simple_xmlss_fprintf(a_file, " ss:Formula=\"%s\"", utility::std_string2xml_string(a_cell.formula).c_str());
    }

    simple_xmlss_fprintf(a_file, ">");
    if (true == a_cell.status_flag.string_flag) {
      print_xmlss_cell_string(a_cell, a_file);
    }
    else if (true == a_cell.status_flag.number_flag) {
      simple_xmlss_fprintf(a_file, "<Data ss:Type=\"Number\">%s</Data>", a_cell.number.c_str()); 
    }
    else if (true == a_cell.status_flag.date_time_flag) {
      simple_xmlss_fprintf(a_file, "<Data ss:Type=\"DateTime\">%s</Data>", a_cell.date_time.c_str()); 
    }

    if (true == a_cell.status_flag.comment_flag) {
      print_node_comment(a_cell, a_file);
    }
    simple_xmlss_fprintf(a_file, "</Cell>\n");
  }

private:
  void print_xmlss_cell_string(model::cell& a_cell,
                               FILE* a_file) {
    if(false == is_valid_font(a_cell.string)) {
      simple_xmlss_fprintf(a_file, "<Data ss:Type=\"String\">%s</Data>", get_cell_string(a_cell.string).c_str());
    }
    else {
      simple_xmlss_fprintf(a_file, "<ss:Data ss:Type=\"String\" xmlns=\"http://www.w3.org/TR/REC-html40\">");
      unsigned int font_id_defined_in_the_style = builder::style::instance().get_font_id(a_cell.style_id);
      for(auto& iter : a_cell.string) {
        if(0==iter.font_id && 0==font_id_defined_in_the_style) {
          simple_xmlss_fprintf(a_file, "<Font>%s</Font>", iter.contents.c_str());
        }
        else {
          print_xmlss_cell_font_string(iter, font_id_defined_in_the_style, true, a_file);
        }
      }
      simple_xmlss_fprintf(a_file, "</ss:Data>");
    }
  }

  void print_xmlss_cell_font_string(const model::cell_font_string& a_cell_font_string,
                                    unsigned int a_font_id_defined_in_the_style,
                                    const bool a_accounting_flag,
                                    FILE* a_file) {
    unsigned int current_font_id = (0!=a_cell_font_string.font_id)?a_cell_font_string.font_id:a_font_id_defined_in_the_style;
    const model::font& current_font = builder::font::instance().get_font(current_font_id);
    print_xmlss_cell_font_string_open_bold(current_font, a_file);
    print_xmlss_cell_font_string_open_italic(current_font, a_file);
    print_xmlss_cell_font_string_open_underline(current_font, a_accounting_flag, a_file);
    print_xmlss_cell_font_string_open_strikethrough(current_font, a_file);
    print_xmlss_cell_font_string_open_superscript_subscript(current_font, a_file);
    print_xmlss_cell_font_string_open_font(current_font, a_file);
    simple_xmlss_fprintf(a_file, "%s", utility::std_string2xml_string(a_cell_font_string.contents).c_str());
    print_xmlss_cell_font_string_close_font(a_file);
    print_xmlss_cell_font_string_close_superscript_subscript(current_font, a_file);
    print_xmlss_cell_font_string_close_strikethrough(current_font, a_file);
    print_xmlss_cell_font_string_close_underline(current_font, a_file);
    print_xmlss_cell_font_string_close_italic(current_font, a_file);
    print_xmlss_cell_font_string_close_bold(current_font, a_file);
  }

  void print_xmlss_cell_font_string_open_bold(const model::font& a_font,
                                              FILE* a_file) {
    if(true == a_font.bold) {
      simple_xmlss_fprintf(a_file, "<B>");
    }
  }

  void print_xmlss_cell_font_string_close_bold(const model::font& a_font,
                                               FILE* a_file) {
    if(true == a_font.bold) {
      simple_xmlss_fprintf(a_file, "</B>");
    }
  }

  void print_xmlss_cell_font_string_open_italic(const model::font& a_font,
                                                FILE* a_file) {
    if(true == a_font.italic) {
      simple_xmlss_fprintf(a_file, "<I>");
    }
  }

  void print_xmlss_cell_font_string_close_italic(const model::font& a_font,
                                                 FILE* a_file) {
    if(true == a_font.italic) {
      simple_xmlss_fprintf(a_file, "</I>");
    }
  }

  void print_xmlss_cell_font_string_open_font(const model::font& a_font,
                                              FILE* a_file) {
    simple_xmlss_fprintf(a_file, "<Font");
    if(0 < a_font.name.size()) {
      simple_xmlss_fprintf(a_file, " html:Face=\"%s\"", a_font.name.c_str()); 
    }
    if(model::FONT_CHAR_SET::NONE != a_font.char_set) {
      simple_xmlss_fprintf(a_file, " x:CharSet=\"%d\"", (int)a_font.char_set);
    }
    if(0 < a_font.family_name.size()) {
      simple_xmlss_fprintf(a_file, " x:Family=\"%s\"", a_font.family_name.c_str());
    }
    if(0 < a_font.size) {
      simple_xmlss_fprintf(a_file, " html:Size=\"%u\"", a_font.size);
    }
    if(0 < a_font.color.size()) {
      simple_xmlss_fprintf(a_file, " html:Color=\"%s\"", a_font.color.c_str());
    }
    simple_xmlss_fprintf(a_file, ">");
  }

  void print_xmlss_cell_font_string_close_font(FILE* a_file) {
    simple_xmlss_fprintf(a_file, "</Font>");
  }

  void print_xmlss_cell_font_string_open_underline(const model::font& a_font,
                                                   const bool a_accounting_flag,
                                                  FILE* a_file) {
    if(model::FONT_UNDERLINE::NONE == a_font.underline) {
      return;
    }

    simple_xmlss_fprintf(a_file, "<U");
    if(model::FONT_UNDERLINE::SINGLE == a_font.underline);
    else if (model::FONT_UNDERLINE::DOUBLE == a_font.underline) {
      simple_xmlss_fprintf(a_file, " html:Style=\"text-underline:double\"");
    }
    else if (model::FONT_UNDERLINE::SINGLE_ACCOUNTING == a_font.underline && true == a_accounting_flag) {
      simple_xmlss_fprintf(a_file, " html:Style=\"text-underline:single-accounting\"");
    }
    else if (model::FONT_UNDERLINE::DOUBLE_ACCOUNTING == a_font.underline && true == a_accounting_flag) {
      simple_xmlss_fprintf(a_file, " html:Style=\"text-underline:double-accounting\"");
    }
    simple_xmlss_fprintf(a_file, ">");
  }

  void print_xmlss_cell_font_string_close_underline(const model::font& a_font,
                                                    FILE* a_file) {
    if(model::FONT_UNDERLINE::NONE == a_font.underline) {
      return;
    }

    simple_xmlss_fprintf(a_file, "</U>");
  }

  void print_xmlss_cell_font_string_open_strikethrough(const model::font& a_font,
                                                       FILE* a_file) {
    if(true == a_font.strikethrough) {
      simple_xmlss_fprintf(a_file, "<S>");
    }
  }

  void print_xmlss_cell_font_string_close_strikethrough(const model::font& a_font,
                                                        FILE* a_file) {
    if(true == a_font.strikethrough) {
      simple_xmlss_fprintf(a_file, "</S>");
    }
  }

  void print_xmlss_cell_font_string_open_superscript_subscript(const model::font& a_font,
                                                               FILE* a_file) {
    if(model::FONT_SUPERSCRIPT_SUBSCRIPT::NONE == a_font.superscript_subscript) {
      return;
    }
    else if(model::FONT_SUPERSCRIPT_SUBSCRIPT::SUPERSCRIPT == a_font.superscript_subscript) {
      simple_xmlss_fprintf(a_file, "<Sup>");
    }
    else if(model::FONT_SUPERSCRIPT_SUBSCRIPT::SUBSCRIPT == a_font.superscript_subscript) {
      simple_xmlss_fprintf(a_file, "<Sub>");
    }
  }

  void print_xmlss_cell_font_string_close_superscript_subscript(const model::font& a_font,
                                                                FILE* a_file) {
    if(model::FONT_SUPERSCRIPT_SUBSCRIPT::NONE == a_font.superscript_subscript) {
      return;
    }
    else if(model::FONT_SUPERSCRIPT_SUBSCRIPT::SUPERSCRIPT == a_font.superscript_subscript) {
      simple_xmlss_fprintf(a_file, "</Sup>");
    }
    else if(model::FONT_SUPERSCRIPT_SUBSCRIPT::SUBSCRIPT == a_font.superscript_subscript) {
      simple_xmlss_fprintf(a_file, "</Sub>");
    }
  }

  std::string get_cell_string(const model::cell_string& a_cell_string) {
    std::string return_value;
    for(auto& iter : a_cell_string) {
      return_value += iter.contents;
    }
    return utility::std_string2xml_string(return_value);
  }

  bool is_valid_font(const model::cell_string& a_cell_string) {
    for(auto& iter : a_cell_string) {
      if(0!=iter.font_id) {
        return true;
      }
    }
    return false;
  }

  void print_node_comment(model::cell& a_cell,
                          FILE* a_file) {
    simple_xmlss_fprintf(a_file, "<Comment");
    print_node_comment_author1(a_cell, a_file);
    simple_xmlss_fprintf(a_file, ">");
    simple_xmlss_fprintf(a_file, "<ss:Data xmlns=\"http://www.w3.org/TR/REC-html40\">");
    print_node_comment_author2(a_cell, a_file);
    print_node_comment_string(a_cell, a_file);
    simple_xmlss_fprintf(a_file, "</ss:Data></Comment>");
  }

  void print_node_comment_author1(model::cell& a_cell,
                                  FILE* a_file) {
    if(0 < a_cell.comment.author.contents.size()) {
      simple_xmlss_fprintf(a_file, " ss:Author=\"%s\"", a_cell.comment.author.contents.c_str());
    }
  }

  void print_node_comment_author2(model::cell& a_cell,
                                  FILE* a_file) {
    if(0 >= a_cell.comment.author.contents.size()) {
      return;
    }
    model::cell_font_string current_comment_author;
    current_comment_author = a_cell.comment.author;
    current_comment_author.contents += ":\n";
    print_xmlss_cell_font_string(current_comment_author, 0, false, a_file);
  }

  void print_node_comment_string(model::cell& a_cell,
                                 FILE* a_file) {
    if(false == is_valid_font(a_cell.comment.string)) {
      simple_xmlss_fprintf(a_file, "<Data ss:Type=\"String\">%s</Data>", get_cell_string(a_cell.comment.string).c_str());
    }
    else {
      simple_xmlss_fprintf(a_file, "<ss:Data ss:Type=\"String\" xmlns=\"http://www.w3.org/TR/REC-html40\">");
      for(auto& iter : a_cell.comment.string) {
        if(0==iter.font_id) {
          simple_xmlss_fprintf(a_file, "<Font>%s</Font>", iter.contents.c_str());
        }
        else {
          print_xmlss_cell_font_string(iter, 0, false, a_file);
        }
      }
      simple_xmlss_fprintf(a_file, "</ss:Data>");
    }
  }
};

} // namespace writer

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_WRITER_CELL_HPP */