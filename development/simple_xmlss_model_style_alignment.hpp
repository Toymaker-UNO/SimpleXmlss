#ifndef SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_HPP

#include "simple_xmlss_model_style_number_format.hpp"
#include "simple_xmlss_model_style_alignment_vertical.hpp"
#include "simple_xmlss_model_style_alignment_text_control.hpp"
#include "simple_xmlss_model_style_alignment_horizontal.hpp"

namespace simple_xmlss {

namespace model {

class style_alignment {
public:
  STYLE_ALIGNMENT_HORIZONTAL horizontal;
  unsigned int horizontal_indent;
  STYLE_ALIGNMENT_VERTICAL vertical;
  STYLE_ALIGNMENT_TEXT_CONTROL text_control;
  int rotate;

  style_alignment(void)
    : horizontal(STYLE_ALIGNMENT_HORIZONTAL::NONE),
      horizontal_indent(0),
      vertical(STYLE_ALIGNMENT_VERTICAL::NONE),
      text_control(STYLE_ALIGNMENT_TEXT_CONTROL::NONE),
      rotate(0) {}

  void clear(void) {
    horizontal = STYLE_ALIGNMENT_HORIZONTAL::NONE;
    horizontal_indent = 0;
    vertical = STYLE_ALIGNMENT_VERTICAL::NONE;
    text_control = STYLE_ALIGNMENT_TEXT_CONTROL::NONE;
    rotate = 0;
  }
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_HPP */