#ifndef SIMPLE_XMLSS_MODEL_FONT_MAP_HPP
#define SIMPLE_XMLSS_MODEL_FONT_MAP_HPP

#include "simple_xmlss_model_font.hpp"
#include "simple_xmlss_dependency.hpp"

enum PRESET_FONT {
  E_PRESET_FONT_DOCUMENT_DEFAULT = 0,
  E_PRESET_FONT_DEFAULT = 1,
  E_PRESET_FONT_HYPERLINK = 2,
  E_PRESET_FONT_BLACK = 3,
  E_PRESET_FONT_WHITE = 4,
};

namespace simple_xmlss {

namespace model {

typedef std::map<unsigned int, font> font_map;

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_FONT_MAP_HPP */