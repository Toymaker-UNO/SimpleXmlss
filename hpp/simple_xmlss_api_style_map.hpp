#ifndef SIMPLE_XMLSS_API_STYLE_MAP_HPP
#define SIMPLE_XMLSS_API_STYLE_MAP_HPP

#include "simple_xmlss_model_style_map.hpp"
#include "simple_xmlss_utility_trace.hpp"
#include "simple_xmlss_utility_error.hpp"
#include "simple_xmlss_utility_error_handler.hpp"

namespace simple_xmlss {

namespace api {

class style_map {
public:
  void initialize(model::style_map& a_style_map) {
    a_style_map.clear();

    clear();
    build(a_style_map, E_PRESET_STYLE_DEFAULT);

    clear();
    set_fill_background_color("#FFFFFF");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_HYPERLINK);
    build(a_style_map, E_PRESET_STYLE_HYPERLINK);

    clear();
    set_fill_background_color("#FF0000");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_BLACK);
    build(a_style_map, E_PRESET_STYLE_RED_BLACK);

    clear();
    set_fill_background_color("#FF0000");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_WHITE);
    build(a_style_map, E_PRESET_STYLE_RED_WHITE);

    clear();
    set_fill_background_color("#00FF00");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_BLACK);
    build(a_style_map, E_PRESET_STYLE_GREEN_BLACK);

    clear();
    set_fill_background_color("#00FF00");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_WHITE);
    build(a_style_map, E_PRESET_STYLE_GREEN_WHITE);

    clear();
    set_fill_background_color("#0000FF");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_BLACK);
    build(a_style_map, E_PRESET_STYLE_BLUE_BLACK);

    clear();
    set_fill_background_color("#0000FF");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_WHITE);
    build(a_style_map, E_PRESET_STYLE_BLUE_WHITE);

    clear();
    set_fill_background_color("#FFFF00");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_BLACK);
    build(a_style_map, E_PRESET_STYLE_YELLOW_BLACK);

    clear();
    set_fill_background_color("#A6A6A6");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_BLACK);
    build(a_style_map, E_PRESET_STYLE_GRAY_BLACK);

    clear();
    set_fill_background_color("#FFC000");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_BLACK);
    build(a_style_map, E_PRESET_STYLE_ORANGE_BLACK);

    clear();
  }

  unsigned int build(model::style_map& a_style_map) {
    unsigned int return_value = a_style_map.size();
    m_style.id = return_value;
    a_style_map.insert(std::make_pair(return_value, m_style));
    return return_value;
  }

  void clear(void) {
    m_style.id = 0;
    m_style.number_format.clear();
    m_style.alignment.clear();
    m_style.font_id = 0;
    m_style.border_map.clear();
    m_style.fill.clear();
  }

  //number format
  void set_number_format(const std::string& a_format) {
    m_style.number_format.format = a_format;
  }

  void set_number_comma(const bool a_number_comma_flag) {
    m_style.number_format.number_comma_flag = a_number_comma_flag;
  }

  //alignment
  void set_alignment_horizontal(const model::STYLE_ALIGNMENT_HORIZONTAL a_horizontal) {
    m_style.alignment.horizontal = a_horizontal;
  }

  void set_alignment_horizontal_indent(const unsigned int a_indent) {
    m_style.alignment.horizontal_indent = a_indent;
  }

  void set_alignment_vertical(const model::STYLE_ALIGNMENT_VERTICAL a_vertical) {
    m_style.alignment.vertical = a_vertical;
  }

  void set_alignment_text_control(const model::STYLE_ALIGNMENT_TEXT_CONTROL a_text_control) {
    m_style.alignment.text_control = a_text_control;
  }

  void set_alignment_rotate(const int a_rotate,
                            const utility::trace& a_trace) {
    if(90 < a_rotate || -90 > a_rotate) {
      utility::error new_error(a_trace.file_name,
                               a_trace.function_name,
                               std::to_string(a_trace.line),
                               "N/A",
                               "N/A",
                               "N/A",
                               "N/A",
                               "Wrong rotate value["+
                               std::to_string(a_rotate)+
                               "]. The rotate value must be a number between -90 and 90.");
      utility::error_handler::instance().handling_error(new_error);
    }
    m_style.alignment.rotate = a_rotate;
  }

  //font
  void set_font_id(const unsigned int a_font_id) {
    m_style.font_id = a_font_id;
  }

  //boarders
  void set_default_borders(void) {
    m_style.border_map.clear();
  }

  void set_border_color(const model::STYLE_BORDER_POSITION a_position, const std::string &a_color) {
    m_style.border_map[a_position].position = a_position;
    m_style.border_map[a_position].color = a_color;
  }

  void set_border_line_type(const model::STYLE_BORDER_POSITION a_position, const model::STYLE_BORDER_LINE_TYPE a_line_type) {
    m_style.border_map[a_position].position = a_position;
    m_style.border_map[a_position].line_type = a_line_type;
  }

  void set_border_weight(const model::STYLE_BORDER_POSITION a_position, const model::STYLE_BORDER_WEIGHT a_weight) {
    m_style.border_map[a_position].position = a_position;
    m_style.border_map[a_position].weight = a_weight;
  }

  //fill
  void set_fill_background_color(const std::string& a_color) {
    m_style.fill.background_color = a_color;
  }

  void set_fill_pattern_color(const std::string& a_color) {
    m_style.fill.pattern_color = a_color;
  }

  void set_fill_pattern_style(model::STYLE_FILL_PATTERN a_pattern) {
    m_style.fill.pattern = a_pattern;
  }

  unsigned int get_font_id(model::style_map& a_style_map,
                           const unsigned int a_style_id) {
    auto iter = a_style_map.find(a_style_id);
    if(a_style_map.end() != iter) {
      return iter->second.font_id;
    }
    return 0;
  }

private:
  void build(model::style_map& a_style_map, const unsigned int a_style_id) {
    m_style.id = a_style_id;
    a_style_map.insert(std::make_pair(a_style_id, m_style));
  }

  model::style  m_style;
};

} // namespace api

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_API_STYLE_MAP_HPP */