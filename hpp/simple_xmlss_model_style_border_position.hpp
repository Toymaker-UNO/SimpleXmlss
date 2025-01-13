#ifndef SIMPLE_XMLSS_MODEL_STYLE_BORDER_POSITION_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_BORDER_POSITION_HPP

#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class STYLE_BORDER_POSITION {
  NONE = 0,
  LEFT = 1,
  TOP = 2,
  RIGHT = 3,
  BOTTOM = 4,
  DIAGONAL_RIGHT = 5,
  DIAGONAL_LEFT = 6,
};

inline std::string to_string(const STYLE_BORDER_POSITION& a_position) {
  if (STYLE_BORDER_POSITION::LEFT == a_position) {
    return "Left";
  } else if (STYLE_BORDER_POSITION::TOP == a_position) {
    return "Top";
  } else if (STYLE_BORDER_POSITION::RIGHT == a_position) {
    return "Right";
  } else if (STYLE_BORDER_POSITION::BOTTOM == a_position) {
    return "Bottom";
  } else if (STYLE_BORDER_POSITION::DIAGONAL_LEFT == a_position) {
    return "DiagonalLeft";
  } else if (STYLE_BORDER_POSITION::DIAGONAL_RIGHT == a_position) {
    return "DiagonalRight";
  } 
  return "";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_POSITION_BORDER_HPP */