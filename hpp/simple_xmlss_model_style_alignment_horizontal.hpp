#ifndef SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_HORIZONTAL_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_HORIZONTAL_HPP

#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class STYLE_ALIGNMENT_HORIZONTAL {
  NONE = 0,
  LEFT = 1,
  CENTER = 2,
  RIGHT = 3,
  FILL = 4,
  JUSTIFY = 5,
  CENTER_ACROSS_SELECTION = 6,
  DISTRIBUTED = 7,
};

inline std::string to_string(const STYLE_ALIGNMENT_HORIZONTAL& a_horizontal) {
  if (STYLE_ALIGNMENT_HORIZONTAL::NONE == a_horizontal) {
    return "None";
  }
  else if (STYLE_ALIGNMENT_HORIZONTAL::LEFT == a_horizontal) {
    return "Left";
  }
  else if (STYLE_ALIGNMENT_HORIZONTAL::CENTER == a_horizontal) {
    return "Center";
  }
  else if (STYLE_ALIGNMENT_HORIZONTAL::RIGHT == a_horizontal) {
    return "Right";
  }
  else if (STYLE_ALIGNMENT_HORIZONTAL::FILL == a_horizontal) {
    return "Fill";
  }
  else if (STYLE_ALIGNMENT_HORIZONTAL::JUSTIFY == a_horizontal) {
    return "Justify";
  }
  else if (STYLE_ALIGNMENT_HORIZONTAL::CENTER_ACROSS_SELECTION == a_horizontal) {
    return "CenterAcrossSelection";
  }
  else if (STYLE_ALIGNMENT_HORIZONTAL::DISTRIBUTED == a_horizontal) {
    return "Distributed";
  }
  return "None";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_HORIZONTAL_HPP */