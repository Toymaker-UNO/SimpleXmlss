#ifndef SIMPLE_XMLSS_MODEL_STYLE_NUMBER_FORMAT_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_NUMBER_FORMAT_HPP

#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

class style_number_format {
public:
  bool number_comma_flag;
  std::string format;

  style_number_format(void)
    :  number_comma_flag(false) {}

  void clear(void) {
    number_comma_flag = false;
    format.clear();
  }
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_NUMBER_FORMAT_HPP */