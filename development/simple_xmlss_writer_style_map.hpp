#ifndef SIMPLE_XMLSS_WRITER_STYLE_MAP_HPP
#define SIMPLE_XMLSS_WRITER_STYLE_MAP_HPP

#include "simple_xmlss_model_style_map.hpp"
#include "simple_xmlss_utility_inline_functions.hpp"
#include "simple_xmlss_builder_font.hpp"

namespace simple_xmlss {

namespace writer {

class style_map {
public:
  void print_xmlss(model::style_map& a_style_map,
                   FILE* a_file) {
    print_xmlss_default(a_file);
    print_xmlss_style_map(a_style_map, a_file);
  }

private:
  void print_xmlss_default(FILE* a_file) {
    simple_xmlss_fprintf(a_file, "  <Style ss:ID=\"Default\" ss:Name=\"Normal\">\n");
    simple_xmlss_fprintf(a_file, "   <Alignment ss:Vertical=\"Center\"/>\n");
    simple_xmlss_fprintf(a_file, "   <Borders/>\n");
    simple_xmlss_fprintf(a_file, "   <Font ss:FontName=\"Tahoma\" x:CharSet=\"129\" x:Family=\"Modern\" ss:Size=\"11\" ss:Color=\"#000000\"/>\n");
    simple_xmlss_fprintf(a_file, "   <Interior/>\n");
    simple_xmlss_fprintf(a_file, "   <NumberFormat/>\n");
    simple_xmlss_fprintf(a_file, "   <Protection/>\n");
    simple_xmlss_fprintf(a_file, "  </Style>\n");
    simple_xmlss_fprintf(a_file, "  <Style ss:ID=\"s_num_comma\">\n");
    simple_xmlss_fprintf(a_file, "   <NumberFormat ss:Format=\"_-* #,##0_-;\\-* #,##0_-;_-* &quot;-&quot;_-;_-@_-\"/>\n");
    simple_xmlss_fprintf(a_file, "  </Style>\n");
  }

  void print_xmlss_style_map(model::style_map& a_style_map,
                             FILE* a_file) {
    for(auto& iter : a_style_map) {
      print_xmlss_style(iter.second, a_file);
    }
  }

  void print_xmlss_style(const model::style& a_style,
                         FILE* a_file) {
    simple_xmlss_fprintf(a_file, "  <Style ss:ID=\"%s\"", utility::get_style_id_string(a_style.id).c_str());
    if (true == a_style.number_format.number_comma_flag) {
      simple_xmlss_fprintf(a_file, " ss:Parent=\"s_num_comma\"");
    }
    simple_xmlss_fprintf(a_file, ">\n");

    print_xmlss_style_alignment(a_style.alignment, a_file);
    print_xmlss_style_border_map(a_style.border_map, a_file);
    builder::font::instance().print_xmlss(a_file, a_style.font_id);
    print_xmlss_style_fill(a_style.fill, a_file);
    print_xmlss_style_number_format(a_style.number_format, a_file);
    simple_xmlss_fprintf(a_file, "  </Style>\n");
  }

  void print_xmlss_style_number_format(const model::style_number_format& a_number_format,
                                       FILE *a_file) {
    if(0 < a_number_format.format.size()) {
      simple_xmlss_fprintf(a_file, "   <NumberFormat ss:Format=\"%s\"/>\n", utility::std_string2xml_string(a_number_format.format).c_str());
    }
  }

  void print_xmlss_style_fill(const model::style_fill& a_fill,
                              FILE *a_file) {
    if(0 == a_fill.background_color.size() &&
       0 == a_fill.pattern_color.size() &&
       model::STYLE_FILL_PATTERN::NONE == a_fill.pattern) {
      return;
    }

    simple_xmlss_fprintf(a_file, "   <Interior");
    if( 0 < a_fill.background_color.size()) {
      simple_xmlss_fprintf(a_file, " ss:Color=\"%s\"", a_fill.background_color.c_str());
    }
    if(model::STYLE_FILL_PATTERN::NONE != a_fill.pattern) {
      simple_xmlss_fprintf(a_file, " ss:Pattern=\"%s\"", model::to_string(a_fill.pattern).c_str());
    }
    if( 0 < a_fill.pattern_color.size()) {
      simple_xmlss_fprintf(a_file, " ss:PatternColor=\"%s\"", a_fill.pattern_color.c_str());
    }
    simple_xmlss_fprintf(a_file, "/>\n");
  }

  void print_xmlss_style_border_map(const model::style_border_map& a_border_map,
                                    FILE *a_file) {
    if (0 >= a_border_map.size()) {
      simple_xmlss_fprintf(a_file, "   <Borders/>\n");
    } 
    else {
      simple_xmlss_fprintf(a_file, "   <Borders>\n");
      for (auto& iter : a_border_map) {
        print_xmlss_style_border(iter.second, a_file);
      }
      simple_xmlss_fprintf(a_file, "   </Borders>\n");
    }
  }

  void print_xmlss_style_border(const model::style_border& a_border,
                                FILE* a_file) {
    if (model::STYLE_BORDER_POSITION::NONE == a_border.position) {
      return;
    }

    simple_xmlss_fprintf(a_file, "    <Border ss:Position=\"%s\" ss:Color=\"%s\" ss:LineStyle=\"%s\" ss:Weight=\"%d\"/>\n",
                model::to_string(a_border.position).c_str(),
                a_border.color.c_str(),
                model::to_string(a_border.line_type).c_str(),
                (int)a_border.weight);
  }

  void print_xmlss_style_alignment(const model::style_alignment& a_alignment,
                                   FILE *a_file) {
    simple_xmlss_fprintf(a_file, "   <Alignment");
    print_xmlss_style_alignment_rotate(a_alignment.rotate, a_file);
    print_xmlss_style_text_control(a_alignment.text_control, a_file);
    print_xmlss_style_horizontal(a_alignment.horizontal, a_file);
    print_xmlss_style_horizontal_indent(a_alignment.horizontal_indent, a_alignment.horizontal, a_file);
    print_xmlss_style_vertical(a_alignment.vertical, a_file);
    simple_xmlss_fprintf(a_file, "/>\n");
  }

  void print_xmlss_style_alignment_rotate(const unsigned int a_rotate,
                                          FILE *a_file) {
    if (0 != a_rotate) {
      simple_xmlss_fprintf(a_file, " ss:Rotate=\"%d\"", a_rotate);
    }
  }

  void print_xmlss_style_text_control(const model::STYLE_ALIGNMENT_TEXT_CONTROL& a_text_control,
                                      FILE* a_file) {
    if(model::STYLE_ALIGNMENT_TEXT_CONTROL::NONE == a_text_control) {
      return;
    }
    simple_xmlss_fprintf(a_file, " ss:%s=\"1\"", model::to_string(a_text_control).c_str());
  }

  void print_xmlss_style_horizontal(const model::STYLE_ALIGNMENT_HORIZONTAL& a_horizontal,
                                    FILE* a_file) {
    if (model::STYLE_ALIGNMENT_HORIZONTAL::NONE == a_horizontal) {
      return;
    }
    simple_xmlss_fprintf(a_file, " ss:Horizontal=\"%s\"", model::to_string(a_horizontal).c_str());
  }

  void print_xmlss_style_horizontal_indent(const unsigned int a_horizontal_indent,
                                           const model::STYLE_ALIGNMENT_HORIZONTAL& a_horizontal,
                                           FILE* a_file) {
    if(0 == a_horizontal_indent) {
      return;
    }

    if(model::STYLE_ALIGNMENT_HORIZONTAL::LEFT == a_horizontal ||
       model::STYLE_ALIGNMENT_HORIZONTAL::RIGHT == a_horizontal ||
       model::STYLE_ALIGNMENT_HORIZONTAL::DISTRIBUTED == a_horizontal) {
      simple_xmlss_fprintf(a_file,  " ss:Indent=\"%u\"", a_horizontal_indent);
    }
  }

  void print_xmlss_style_vertical(const model::STYLE_ALIGNMENT_VERTICAL& a_vertical,
                                  FILE* a_file) {
    if (model::STYLE_ALIGNMENT_VERTICAL::NONE == a_vertical) {
      return;
    }
    simple_xmlss_fprintf(a_file, " ss:Vertical=\"%s\"", model::to_string(a_vertical).c_str());
  }
};

} // namespace writer

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_WRITER_STYLE_MAP_HPP */
