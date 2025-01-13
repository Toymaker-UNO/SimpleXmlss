#ifndef SIMPLE_XMLSS_API_FONT_MAP_HPP
#define SIMPLE_XMLSS_API_FONT_MAP_HPP

#include "simple_xmlss_model_font_map.hpp"

namespace simple_xmlss {

namespace api {

class font_map {
public:
  void initialize(model::font_map& a_font_map) {
    a_font_map.clear();

    clear();
    build(a_font_map, E_PRESET_FONT_DOCUMENT_DEFAULT);

    clear();
    build(a_font_map, E_PRESET_FONT_DEFAULT);

    clear();
    set_color("#1A0DAB");
    set_underline(model::FONT_UNDERLINE::SINGLE);
    build(a_font_map, E_PRESET_FONT_HYPERLINK);

    clear();
    set_color("#000000");
    build(a_font_map, E_PRESET_FONT_BLACK);

    clear();
    set_color("#FFFFFF");
    build(a_font_map, E_PRESET_FONT_WHITE);
    
    clear();
  }

  const model::font& get_font(model::font_map& a_font_map, const unsigned int a_font_id) {
    return a_font_map.find(a_font_id)->second;
  }

  unsigned int build(model::font_map& a_font_map) {
    unsigned int return_value = (unsigned int)a_font_map.size();
    m_font.id = return_value;
    a_font_map.insert(std::make_pair(return_value,m_font));
    return return_value;
  }

  void clear(void) {
    m_font.clear();
  }

  void set_name(const std::string& a_name) {
    m_font.name = a_name;
  }

  void set_char_set(const model::FONT_CHAR_SET a_char_set) {
    m_font.char_set = a_char_set;
  }

  void set_family_name(const std::string& a_family_name) {
    m_font.family_name = a_family_name;
  }

  void set_color(const std::string& a_color) {
    m_font.color = a_color;
  }

  void set_size(const unsigned int a_size) {
    m_font.size = a_size;
  }

  void set_underline(const model::FONT_UNDERLINE a_underline) {
    m_font.underline = a_underline;
  }

  void set_superscript_subscript(const model::FONT_SUPERSCRIPT_SUBSCRIPT a_superscript_subscript) {
    m_font.superscript_subscript = a_superscript_subscript;
  }

  void set_italic(const bool a_italic) {
    m_font.italic = a_italic;
  }

  void set_bold(const bool a_bold) {
    m_font.bold = a_bold;
  }

  void set_strikethrough(const bool a_strikethrough) {
    m_font.strikethrough = a_strikethrough;
  }

private:
  void build(model::font_map& a_font_map, const unsigned int a_font_id) {
    m_font.id = a_font_id;
    a_font_map.insert(std::make_pair(a_font_id,m_font));
  }

  model::font m_font;
};

} // namespace api

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_API_FONT_MAP_HPP */