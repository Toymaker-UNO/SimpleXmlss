#ifndef SIMPLE_XMLSS_TEST_0101_SHEET_SET_STRING_HPP
#define SIMPLE_XMLSS_TEST_0101_SHEET_SET_STRING_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0101_sheet_set_string : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    simple_xmlss::sheet& new_sheet2 = new_book.get_sheet("Sheet No 2");
    simple_xmlss::sheet& new_sheet3 = new_book.get_sheet("Sheet No 3");
    simple_xmlss::sheet& new_sheet4 = new_book.get_sheet("Sheet No 4");
    new_sheet1.set_string("A1 Data",     1, 1);
    new_sheet1.set_string("B2 Data: &",  2, 2);
    new_sheet1.set_string("C3 Data: <",  3, 3);
    new_sheet1.set_string("D4 Data: >",  4, 4);
    new_sheet1.set_string("E5 Data: \"", 5, 5);
    new_sheet1.set_string("F6 Data: '",  6, 6);
    
    for(unsigned int row = 1; row <= 100; row++) {
      for(unsigned int col = 1; col <= 100; col++) {
        std::string contents = utility::column2string(col);
        contents += std::to_string(row);
        contents += " Data";
        new_sheet2.set_string(contents, col, row);
        new_sheet3.set_string(contents, col, row);
        new_sheet4.set_string(contents, col, row);
      }
    }
    new_book.print_xmlss("./test_0101_sheet_set_string.xml");
    return "test_0101_sheet_set_string";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0101_SHEET_SET_STRING_HPP */
