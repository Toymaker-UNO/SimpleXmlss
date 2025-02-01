#ifndef SIMPLE_XMLSS_MODEL_STYLE_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_HPP

#include "simple_xmlss_model_style_number_format.hpp"
#include "simple_xmlss_model_style_alignment.hpp"
#include "simple_xmlss_model_style_border_map.hpp"
#include "simple_xmlss_model_style_fill.hpp"

namespace simple_xmlss {

namespace model {

class style {
public:
  unsigned int id;
  style_number_format number_format;
  style_alignment alignment;
  unsigned int font_id;
  style_border_map border_map;
  style_fill fill;

  style(void)
    : id(0),
      font_id(0) {}
}; 

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_HPP */