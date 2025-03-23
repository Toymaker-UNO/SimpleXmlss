#ifndef SIMPLE_XMLSS_BUILDER_STYLE_HPP
#define SIMPLE_XMLSS_BUILDER_STYLE_HPP

#include "simple_xmlss_model_style_map.hpp"
#include "simple_xmlss_api_style_map.hpp"
#include "simple_xmlss_writer_style_map.hpp"

namespace simple_xmlss {

namespace builder {

class style {
public:
  static style&  instance(void) {
    static style singleton_instance;
    return singleton_instance;
  }

  unsigned int build(void) {
    return m_api.build(m_model);
  }

  style& clear(void) {
    m_api.clear();
    return (*this);
}

//number format
style& set_number_format(const std::string& a_format) {
  m_api.set_number_format(a_format);
  return (*this);
}

style& set_number_comma(const bool a_number_comma_flag) {
  m_api.set_number_comma(a_number_comma_flag);
  return (*this);
}

//alignment
style& set_alignment_horizontal(const model::STYLE_ALIGNMENT_HORIZONTAL a_horizontal) {
  m_api.set_alignment_horizontal(a_horizontal);
  return (*this);
}

style& set_alignment_horizontal_indent(const unsigned int a_indent) {
  m_api.set_alignment_horizontal_indent(a_indent);
  return (*this);
}

style& set_alignment_vertical(const model::STYLE_ALIGNMENT_VERTICAL a_vertical) {
  m_api.set_alignment_vertical(a_vertical);
  return (*this);
}

style& set_alignment_text_control(const model::STYLE_ALIGNMENT_TEXT_CONTROL a_text_control) {
  m_api.set_alignment_text_control(a_text_control);
  return (*this);
}

style& set_alignment_rotate(const int a_rotate,
                            const utility::trace& a_trace = utility::trace()) {
  m_api.set_alignment_rotate(a_rotate,
                             a_trace);
  return (*this);
}

//font
style& set_font_id(const unsigned int a_font_id) {
  m_api.set_font_id(a_font_id);
  return (*this);
}

//boarders
style& set_default_borders(void) {
  m_api.set_default_borders();
  return (*this);
}

style& set_border_color(const model::STYLE_BORDER_POSITION a_position,
                        const std::string &a_color) {
  m_api.set_border_color(a_position,
                         a_color);
  return (*this);
}

style& set_border_line_type(const model::STYLE_BORDER_POSITION a_position,
                            const model::STYLE_BORDER_LINE_TYPE a_line_type) {
  m_api.set_border_line_type(a_position, a_line_type);
  return (*this);
}

style& set_border_weight(const model::STYLE_BORDER_POSITION a_position,
                         const model::STYLE_BORDER_WEIGHT a_weight) {
  m_api.set_border_weight(a_position, a_weight);
  return (*this);
}

//fill
style& set_fill_background_color(const std::string& a_color) {
  m_api.set_fill_background_color(a_color);
  return (*this);
}

style& set_fill_pattern_color(const std::string& a_color) {
  m_api.set_fill_pattern_color(a_color);
  return (*this);
}

style& set_fill_pattern_style(model::STYLE_FILL_PATTERN a_pattern) {
  m_api.set_fill_pattern_style(a_pattern);
  return (*this);
}

unsigned int get_font_id(const unsigned int a_style_id) {
  return m_api.get_font_id(m_model, a_style_id);
}

void print_xmlss(FILE* a_file) {
  m_writer.print_xmlss(m_model, a_file);
}

void initialize(void) { //for unit test
  m_api.initialize(m_model);
}

private:
  style(void) {
    initialize();
  }

  model::style_map m_model;
  api::style_map m_api;
  writer::style_map m_writer;
};

} // namespace builder

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_BUILDER_STYLE_HPP */