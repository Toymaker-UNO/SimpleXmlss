#ifndef SIMPLE_XMLSS_UTILITY_TRACE_HPP
#define SIMPLE_XMLSS_UTILITY_TRACE_HPP

#include "simple_xmlss_dependency.hpp"

#define TRACE() simple_xmlss::utility::trace(__FILE__, __func__ ,__LINE__)

namespace simple_xmlss {

namespace utility {

class trace {
public:
  const std::string file_name;
  const std::string function_name;
  const unsigned int line;

  trace(void)
    : file_name("N/A"),
      function_name("N/A"),
      line(0) {}
  
  trace(const std::string& a_file_name,
        const std::string& a_function_name,
        const unsigned int a_line)
    : file_name(a_file_name),
      function_name(a_function_name),
      line(a_line) {}
};

} // namespace api

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_UTILITY_TRACE_HPP */