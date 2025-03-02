#ifndef SIMPLE_XMLSS_TEST_0103_SHEET_SET_STRING_HPP
#define SIMPLE_XMLSS_TEST_0103_SHEET_SET_STRING_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0103_sheet_set_string : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    new_sheet1.set_string("A1 Data",     1, 1,   1, 1);
    new_sheet1.set_string("B2 Data: &",  3, 3,   1, 1);
    new_sheet1.set_string("C3 Data: <",  5, 5,   2, 2);
    new_sheet1.set_string("D4 Data: >",  8, 8,   1, 1);
    new_sheet1.set_string("E5 Data: \"", 10, 10, 3, 3);
    new_sheet1.set_string("F6 Data: '",  14, 14, 5, 5);

    new_book.print_xmlss("./test_0103_sheet_set_string.xml");
    return "test_0103_sheet_set_string";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0103_SHEET_SET_STRING_HPP */
