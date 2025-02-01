#ifndef SIMPLE_XMLSS_WRITER_FONT_MAP_HPP
#define SIMPLE_XMLSS_WRITER_FONT_MAP_HPP

#include "simple_xmlss_model_font_map.hpp"
#include "simple_xmlss_utility_inline_functions.hpp"

namespace simple_xmlss {

namespace writer {

class font_map {
public:
  void print_xmlss(model::font_map& a_font_map,
                   const unsigned int a_font_id,
                   FILE* a_file) {
    if(E_PRESET_FONT_DEFAULT == a_font_id) {
      return;
    }

    auto iter = a_font_map.find(a_font_id);
    if(a_font_map.end() == iter) {
      return;
    }

    print_xmlss(iter->second, a_file);
  }

private:
  void print_xmlss(const model::font& a_font,
                   FILE* a_file) {
    simple_xmlss_fprintf(a_file, "   <Font");
    simple_xmlss_fprintf(a_file, " ss:FontName=\"%s\"", a_font.name.c_str());
    if(model::FONT_CHAR_SET::NONE != a_font.char_set) {
      simple_xmlss_fprintf(a_file, " x:CharSet=\"%d\"", (int)a_font.char_set);
    }
    simple_xmlss_fprintf(a_file, " x:Family=\"%s\"", a_font.family_name.c_str());
    simple_xmlss_fprintf(a_file, " ss:Size=\"%u\"", a_font.size);
    if( 0 < a_font.color.size()) {
      simple_xmlss_fprintf(a_file, " ss:Color=\"%s\"", a_font.color.c_str());
    }
    if(model::FONT_UNDERLINE::NONE != a_font.underline) {
      simple_xmlss_fprintf(a_file, " ss:Underline=\"%s\"", model::to_string(a_font.underline).c_str());
    }
    if(model::FONT_SUPERSCRIPT_SUBSCRIPT::NONE != a_font.superscript_subscript) {
      simple_xmlss_fprintf(a_file, " ss:VerticalAlign=\"%s\"", model::to_string(a_font.superscript_subscript).c_str());
    }
    if(true == a_font.bold) {
      simple_xmlss_fprintf(a_file, "  ss:Bold=\"1\"");
    }
    if(true == a_font.italic) {
      simple_xmlss_fprintf(a_file, "  ss:Italic=\"1\"");
    }
    if(true == a_font.strikethrough) {
      simple_xmlss_fprintf(a_file, "  ss:StrikeThrough=\"1\"");
    }
    simple_xmlss_fprintf(a_file, "/>\n");
  }
};

} // namespace writer

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_WRITER_FONT_MAP_HPP */