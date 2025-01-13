#ifndef SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_VERTICAL_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_VERTICAL_HPP

#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class STYLE_ALIGNMENT_VERTICAL {
  NONE = 0,
  TOP = 1,
  CENTER = 2,
  BOTTOM = 3,
  JUSTIFY = 4,
  DISTRIBUTED = 5,
};

inline std::string to_string(const STYLE_ALIGNMENT_VERTICAL& a_vertical) {
  if (STYLE_ALIGNMENT_VERTICAL::NONE == a_vertical) {
    return "None";
  }
  else if (STYLE_ALIGNMENT_VERTICAL::TOP == a_vertical) {
    return "Top";
  }      
  else if (STYLE_ALIGNMENT_VERTICAL::CENTER == a_vertical) {
    return "Center";
  } 
  else if (STYLE_ALIGNMENT_VERTICAL::BOTTOM == a_vertical) {
    return "Bottom";
  }
  else if (STYLE_ALIGNMENT_VERTICAL::JUSTIFY == a_vertical) {
    return "Justify";
  }
  else if (STYLE_ALIGNMENT_VERTICAL::DISTRIBUTED == a_vertical) {
    return "Distributed";
  }
  return "None";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_VERTICAL_HPP */