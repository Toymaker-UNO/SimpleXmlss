#ifndef SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_TEXT_CONTROL_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_TEXT_CONTROL_HPP

#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class STYLE_ALIGNMENT_TEXT_CONTROL {
  NONE = 0,
  WRAP_TEXT = 1,
  SHRINK_TO_FIT = 2,
};

inline std::string to_string(const STYLE_ALIGNMENT_TEXT_CONTROL& a_text_control) {
  if(STYLE_ALIGNMENT_TEXT_CONTROL::WRAP_TEXT == a_text_control) {
      return "WrapText";
  }
  else if (STYLE_ALIGNMENT_TEXT_CONTROL::SHRINK_TO_FIT == a_text_control) {
    return "ShrinkToFit";
  }
  return "None";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_TEXT_CONTROL_HPP */