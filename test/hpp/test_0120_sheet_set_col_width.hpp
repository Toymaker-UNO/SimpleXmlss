#ifndef SIMPLE_XMLSS_TEST_0120_SHEET_SET_COL_WIDTH_HPP
#define SIMPLE_XMLSS_TEST_0120_SHEET_SET_COL_WIDTH_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0120_sheet_set_col_width : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    new_sheet1.set_col_width(2,130);
    new_sheet1.set_col_width(3,130);
    new_sheet1.set_col_width(4,130);
    new_sheet1.set_col_width(5,130);
    new_sheet1.set_col_width(6,130);
    new_sheet1.set_col_width(7,130);
    new_sheet1.set_col_width(8,130);
    
    new_sheet1.set_string("C3 Data",       3, 3);
    new_sheet1.set_string("D4 Data: &",    4, 4);
    new_sheet1.set_string("E5 Data: <",    5, 5);
    new_sheet1.set_string("F6 Data: >",    6, 6);
    new_sheet1.set_string("G7 Data: \"",   7, 7);
    new_sheet1.set_string("H8 Data: '",    8, 8);
    
    new_book.print_xmlss("./test_0120_sheet_set_col_width.xml");
    return "test_0120_sheet_set_col_width";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0120_SHEET_SET_COL_WIDTH_HPP */
