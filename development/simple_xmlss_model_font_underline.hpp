#ifndef SIMPLE_XMLSS_MODEL_FONT_UNDERLINE_HPP
#define SIMPLE_XMLSS_MODEL_FONT_UNDERLINE_HPP

#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class FONT_UNDERLINE {
  NONE = 0,
  SINGLE = 1,
  DOUBLE = 2,
  SINGLE_ACCOUNTING = 3,
  DOUBLE_ACCOUNTING = 4,
};

inline std::string to_string(const FONT_UNDERLINE& a_underline) {
  if (FONT_UNDERLINE::SINGLE == a_underline) {
    return "Single";
  }
  else if (FONT_UNDERLINE::DOUBLE == a_underline) {
    return "Double";
  }
  else if (FONT_UNDERLINE::SINGLE_ACCOUNTING == a_underline) {
    return "SingleAccounting";
  }
  else if (FONT_UNDERLINE::DOUBLE_ACCOUNTING == a_underline) {
    return "DoubleAccounting";
  }
	return "None";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_FONT_UNDERLINE_HPP */