#ifndef SIMPLE_XMLSS_TEST_0003_BOOK_SET_STRING_HPP
#define SIMPLE_XMLSS_TEST_0003_BOOK_SET_STRING_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0003_book_set_string : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::book new_book("new_book");
    new_book.set_string("A1 Data",     "Sheet No 1", 1, 1,   1, 1);
    new_book.set_string("B2 Data: &",  "Sheet No 1", 3, 3,   1, 1);
    new_book.set_string("C3 Data: <",  "Sheet No 1", 5, 5,   2, 2);
    new_book.set_string("D4 Data: >",  "Sheet No 1", 8, 8,   1, 1);
    new_book.set_string("E5 Data: \"", "Sheet No 1", 10, 10, 3, 3);
    new_book.set_string("F6 Data: '",  "Sheet No 1", 14, 14, 5, 5);

    new_book.print_xmlss("./test_0003_book_set_string.xml");
    return "test_0003_book_set_string";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0003_BOOK_SET_STRING_HPP */
