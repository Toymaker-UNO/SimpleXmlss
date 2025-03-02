#ifndef SIMPLE_XMLSS_TEST_0019_BOOK_SET_ROW_HEIGHT_HPP
#define SIMPLE_XMLSS_TEST_0019_BOOK_SET_ROW_HEIGHT_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0019_book_set_row_height : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::book new_book("new_book");
    new_book.set_row_height(2,60,"Sheet No 1");
    new_book.set_row_height(3,60,"Sheet No 1");
    new_book.set_row_height(4,60,"Sheet No 1");
    new_book.set_row_height(5,60,"Sheet No 1");
    new_book.set_row_height(6,60,"Sheet No 1");
    new_book.set_row_height(7,60,"Sheet No 1");
    new_book.set_row_height(8,60,"Sheet No 1");
    
    new_book.set_string("C3 Data",       "Sheet No 1", 3, 3);
    new_book.set_string("D4 Data: &",    "Sheet No 1", 4, 4);
    new_book.set_string("E5 Data: <",    "Sheet No 1", 5, 5);
    new_book.set_string("F6 Data: >",    "Sheet No 1", 6, 6);
    new_book.set_string("G7 Data: \"",   "Sheet No 1", 7, 7);
    new_book.set_string("H8 Data: '",    "Sheet No 1", 8, 8);
    
    new_book.print_xmlss("./test_0019_book_set_row_height.xml");
    return "test_0019_book_set_row_height";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0019_BOOK_SET_ROW_HEIGHT_HPP */
