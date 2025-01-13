#ifndef SIMPLE_XMLSS_BUILDER_STRING_HPP
#define SIMPLE_XMLSS_BUILDER_STRING_HPP

#include "simple_xmlss_model_cell_string.hpp"

namespace simple_xmlss {

namespace builder {

class string {
public:  
  static string&  instance(void) {
    static string singleton_instance;
    return singleton_instance;
  }

  const model::cell_string& build(void) {
    return m_cell_string;
  }

  string& clear(void) {
    m_cell_string.clear();
    return (*this);
  }

  string& set_string(const std::string& a_string) {
    return set_string(a_string,0);
  }

  string& set_string(const std::string& a_string,
                     const unsigned int a_font_id) {
    model::cell_font_string new_cell_font_string;
    new_cell_font_string.contents = a_string;
    new_cell_font_string.font_id = a_font_id;
    m_cell_string.push_back(new_cell_font_string);
    return (*this);
  }

private:
  string(void) {
    clear();
  }

  model::cell_string m_cell_string;
};

} // namespace builder

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_BUILDER_STRING_HPP */