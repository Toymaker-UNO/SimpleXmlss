#ifndef SIMPLE_XMLSS_BUILDER_FONT_HPP
#define SIMPLE_XMLSS_BUILDER_FONT_HPP

#include "simple_xmlss_model_font_map.hpp"
#include "simple_xmlss_api_font_map.hpp"
#include "simple_xmlss_writer_font_map.hpp"

namespace simple_xmlss {

namespace builder {

class font {
public:  
  static font&  instance(void) {
    static font singleton_instance;
    return singleton_instance;
  }

  const model::font& get_font(const unsigned int a_font_id) {
    return m_api.get_font(m_model, a_font_id);
  }

  unsigned int build(void) {
    return m_api.build(m_model);
  }

  font& clear(void) {
    m_api.clear();
    return (*this);
  }

  font& set_name(const std::string& a_name) {
    m_api.set_name(a_name);
    return (*this);
  }

  font& set_char_set(const model::FONT_CHAR_SET a_char_set) {
    m_api.set_char_set(a_char_set);
    return (*this);
  }

  font& set_family_name(const std::string& a_family_name) {
    m_api.set_family_name(a_family_name);
    return (*this);
  }

  font& set_color(const std::string& a_color) {
    m_api.set_color(a_color);
    return (*this);
  }

  font& set_size(const unsigned int a_size) {
    m_api.set_size(a_size);
    return (*this);
  }

  font& set_underline(const model::FONT_UNDERLINE a_underline) {
    m_api.set_underline(a_underline);
    return (*this);
  }

  font& set_superscript_subscript(const model::FONT_SUPERSCRIPT_SUBSCRIPT a_superscript_subscript) {
    m_api.set_superscript_subscript(a_superscript_subscript);
    return (*this);
  }

  font& set_italic(const bool a_italic) {
    m_api.set_italic(a_italic);
    return (*this);
  }

  font& set_bold(const bool a_bold) {
    m_api.set_bold(a_bold);
    return (*this);
  }

  font& set_strikethrough(const bool a_strikethrough) {
    m_api.set_strikethrough(a_strikethrough);
    return (*this);
  }

  void print_xmlss(FILE* a_file, const unsigned int a_font_id) {
    m_writer.print_xmlss(m_model, a_font_id, a_file);
  }

private:
  font(void) {
    initialize();
  }

  void initialize(void) {
    m_api.initialize(m_model);
  }

  model::font_map m_model;
  api::font_map m_api;
  writer::font_map m_writer;
};

} // namespace builder

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_BUILDER_FONT_HPP */