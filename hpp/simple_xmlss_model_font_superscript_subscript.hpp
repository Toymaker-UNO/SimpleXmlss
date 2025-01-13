#ifndef SIMPLE_XMLSS_MODEL_FONT_SUPERSCRIPT_SUBSCRIPT_HPP
#define SIMPLE_XMLSS_MODEL_FONT_SUPERSCRIPT_SUBSCRIPT_HPP

#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class FONT_SUPERSCRIPT_SUBSCRIPT {
  NONE = 0,
  SUPERSCRIPT = 1,
  SUBSCRIPT = 2,
};

inline std::string to_string(const FONT_SUPERSCRIPT_SUBSCRIPT& a_superscript_subscript) {
  if (FONT_SUPERSCRIPT_SUBSCRIPT::SUPERSCRIPT == a_superscript_subscript) {
    return "Superscript";
  }
  else if (FONT_SUPERSCRIPT_SUBSCRIPT::SUBSCRIPT == a_superscript_subscript) {
    return "Subscript";
  }
	return "None";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_FONT_SUPERSCRIPT_SUBSCRIPT_HPP */