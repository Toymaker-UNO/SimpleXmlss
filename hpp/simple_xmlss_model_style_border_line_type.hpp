#ifndef SIMPLE_XMLSS_MODEL_STYLE_BORDER_LINE_TYPE_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_BORDER_LINE_TYPE_HPP

#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class STYLE_BORDER_LINE_TYPE {
  NONE = 0,
  DOT = 1,
  DASHDOTDOT = 2,
  DASHDOT = 3,
  DASH = 4,
  CONTINUOUS = 5,
  SLANTDASHDOT = 6,
  DOUBLE = 7,
};

inline std::string to_string(const STYLE_BORDER_LINE_TYPE& a_line_type) {
  if (STYLE_BORDER_LINE_TYPE::NONE == a_line_type) {
    return "None";
  }
  else if (model::STYLE_BORDER_LINE_TYPE::DOT == a_line_type) {
    return "Dot";
  }
  else if (model::STYLE_BORDER_LINE_TYPE::DASHDOTDOT == a_line_type) {
    return "DashDotDot";
  }
  else if (model::STYLE_BORDER_LINE_TYPE::DASHDOT == a_line_type) {
    return "DashDot";
  }
  else if (model::STYLE_BORDER_LINE_TYPE::DASH == a_line_type) {
    return "Dash";
  }
  else if (model::STYLE_BORDER_LINE_TYPE::CONTINUOUS == a_line_type) {
    return "Continuous";
  }
  else if (model::STYLE_BORDER_LINE_TYPE::SLANTDASHDOT == a_line_type) {
    return "SlantDashDot";
  }
  else if (model::STYLE_BORDER_LINE_TYPE::DOUBLE == a_line_type) {
    return "Double";
  } 
  return "None";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_BORDER_LINE_TYPE_HPP */