#ifndef SIMPLE_XMLSS_MODEL_STYLE_FILL_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_FILL_HPP

#include "simple_xmlss_dependency.hpp"
#include "simple_xmlss_model_style_fill_pattern.hpp"

namespace simple_xmlss {

namespace model {

class style_fill {
public:
  std::string background_color;
  std::string pattern_color;
  STYLE_FILL_PATTERN pattern;

  style_fill(void)
    : background_color(""),
      pattern_color(""),
      pattern(STYLE_FILL_PATTERN::NONE) {}

  void clear(void) {
    background_color.clear();
    pattern_color.clear();
    pattern = STYLE_FILL_PATTERN::NONE;
  }
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_FILL_HPP */