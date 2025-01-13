#ifndef SIMPLE_XMLSS_MODEL_SHEET_CONFIGURATION_HPP
#define SIMPLE_XMLSS_MODEL_SHEET_CONFIGURATION_HPP

#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

class sheet_configuration {
public:
  const std::string book_name;
  const std::string sheet_name;

  sheet_configuration(const std::string& a_book_name,
                      const std::string& a_sheet_name)
    : book_name(a_book_name),
      sheet_name(a_sheet_name) {}
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_SHEET_CONFIGURATION_HPP */