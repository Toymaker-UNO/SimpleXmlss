#ifndef SIMPLE_XMLSS_MODEL_CELL_FONT_STRING_HPP
#define SIMPLE_XMLSS_MODEL_CELL_FONT_STRING_HPP

#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

class cell_font_string {
public:
  unsigned int font_id;
  std::string contents;

  cell_font_string(void)
    : font_id(0) {}
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_CELL_FONT_STRING_HPP */