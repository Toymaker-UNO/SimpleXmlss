#ifndef SIMPLE_XMLSS_MODEL_STYLE_BORDER_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_BORDER_HPP

#include "simple_xmlss_dependency.hpp"
#include "simple_xmlss_model_style_border_position.hpp"
#include "simple_xmlss_model_style_border_line_type.hpp"
#include "simple_xmlss_model_style_border_weight.hpp"

namespace simple_xmlss {

namespace model {

class style_border {
public:
  STYLE_BORDER_POSITION position;
  std::string color;
  STYLE_BORDER_LINE_TYPE line_type;
  STYLE_BORDER_WEIGHT weight;

  style_border(void)
    : position(STYLE_BORDER_POSITION::NONE),
      color("#000000"),
      line_type(STYLE_BORDER_LINE_TYPE::CONTINUOUS),
      weight(STYLE_BORDER_WEIGHT::THIN) {}

  void clear(void) {
    position = STYLE_BORDER_POSITION::NONE;
    color = "#000000";
    line_type = STYLE_BORDER_LINE_TYPE::CONTINUOUS;
    weight = STYLE_BORDER_WEIGHT::THIN;
  }
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_BORDER_HPP */