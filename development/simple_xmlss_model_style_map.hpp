#ifndef SIMPLE_XMLSS_MODEL_STYLE_MAP_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_MAP_HPP

#include "simple_xmlss_model_style.hpp"
#include "simple_xmlss_dependency.hpp"

enum PRESET_STYLE {
  E_PRESET_STYLE_DEFAULT = 0,
  E_PRESET_STYLE_HYPERLINK = 1,
  E_PRESET_STYLE_RED_BLACK = 2,
  E_PRESET_STYLE_RED_WHITE = 3,
  E_PRESET_STYLE_GREEN_BLACK = 4,
  E_PRESET_STYLE_GREEN_WHITE = 5,
  E_PRESET_STYLE_BLUE_BLACK = 6,
  E_PRESET_STYLE_BLUE_WHITE = 7,
  E_PRESET_STYLE_YELLOW_BLACK = 8,
  E_PRESET_STYLE_GRAY_BLACK = 9,
  E_PRESET_STYLE_ORANGE_BLACK = 10,
};

namespace simple_xmlss {

namespace model {

typedef std::map<unsigned int, style> style_map;

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_MAP_HPP */