#ifndef SIMPLE_XMLSS_UTILITY_ERROR_HANDLER_HPP
#define SIMPLE_XMLSS_UTILITY_ERROR_HANDLER_HPP

#include "simple_xmlss_utility_error.hpp"

namespace simple_xmlss {

namespace utility {

class error_handler {
public:  
  static error_handler&  instance(void) {
    static error_handler singleton_instance;
    return singleton_instance;
  }

  void handling_error(const error& a_error) {
    m_error = a_error;
    throw m_error;
  }

private:
  error_handler(void) {}
  ~error_handler(void) {}

  error m_error;
};

} // namespace utility

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_UTILITY_ERROR_HANDLER_HPP */