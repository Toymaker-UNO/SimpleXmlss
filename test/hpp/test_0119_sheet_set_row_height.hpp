#ifndef SIMPLE_XMLSS_TEST_0119_SHEET_SET_ROW_HEIGHT_HPP
#define SIMPLE_XMLSS_TEST_0119_SHEET_SET_ROW_HEIGHT_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0119_sheet_set_row_height : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    new_sheet1.set_row_height(2,60);
    new_sheet1.set_row_height(3,60);
    new_sheet1.set_row_height(4,60);
    new_sheet1.set_row_height(5,60);
    new_sheet1.set_row_height(6,60);
    new_sheet1.set_row_height(7,60);
    new_sheet1.set_row_height(8,60);
    
    new_sheet1.set_string("C3 Data",       3, 3);
    new_sheet1.set_string("D4 Data: &",    4, 4);
    new_sheet1.set_string("E5 Data: <",    5, 5);
    new_sheet1.set_string("F6 Data: >",    6, 6);
    new_sheet1.set_string("G7 Data: \"",   7, 7);
    new_sheet1.set_string("H8 Data: '",    8, 8);
    
    new_book.print_xmlss("./test_0119_sheet_set_row_height.xml");
    return "test_0119_sheet_set_row_height";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0119_SHEET_SET_ROW_HEIGHT_HPP */
