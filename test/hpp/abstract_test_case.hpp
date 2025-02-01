#ifndef SIMPLE_XMLSS_ABSTRACT_TEST_CASE_HPP
#define SIMPLE_XMLSS_ABSTRACT_TEST_CASE_HPP

#include "simple_xmlss.hpp"

namespace simple_xmlss {

class abstract_test_case {
public:
  virtual ~abstract_test_case(void) {}
  virtual std::string run(void) = 0;
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_ABSTRACT_TEST_CASE_HPP */
