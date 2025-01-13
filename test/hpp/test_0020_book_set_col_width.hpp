#ifndef SIMPLE_XMLSS_TEST_0020_BOOK_SET_COL_WIDTH_HPP
#define SIMPLE_XMLSS_TEST_0020_BOOK_SET_COL_WIDTH_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0020_book_set_col_width : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

    simple_xmlss::book new_book("new_book");
    new_book.set_col_width(2,130,"Sheet No 1");
    new_book.set_col_width(3,130,"Sheet No 1");
    new_book.set_col_width(4,130,"Sheet No 1");
    new_book.set_col_width(5,130,"Sheet No 1");
    new_book.set_col_width(6,130,"Sheet No 1");
    new_book.set_col_width(7,130,"Sheet No 1");
    new_book.set_col_width(8,130,"Sheet No 1");
    
    new_book.set_string("C3 Data",       "Sheet No 1", 3, 3);
    new_book.set_string("D4 Data: &",    "Sheet No 1", 4, 4);
    new_book.set_string("E5 Data: <",    "Sheet No 1", 5, 5);
    new_book.set_string("F6 Data: >",    "Sheet No 1", 6, 6);
    new_book.set_string("G7 Data: \"",   "Sheet No 1", 7, 7);
    new_book.set_string("H8 Data: '",    "Sheet No 1", 8, 8);
    
    new_book.print_xmlss("./test_0020_book_set_col_width.xml");
    return "test_0020_book_set_col_width";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0020_BOOK_SET_COL_WIDTH_HPP */
