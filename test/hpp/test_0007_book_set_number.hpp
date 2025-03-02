#ifndef SIMPLE_XMLSS_TEST_0007_BOOK_SET_NUMBER_HPP
#define SIMPLE_XMLSS_TEST_0007_BOOK_SET_NUMBER_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0007_book_set_number : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::book new_book("new_book");
    new_book.set_number("12345",  "Sheet No 1",  1, 1);
    new_book.set_number("3.14",   "Sheet No 1",  2, 2);
    new_book.set_number("-12345", "Sheet No 1",  3, 3);
    new_book.set_number("-1.25",  "Sheet No 1",  4, 4);
    new_book.print_xmlss("./test_0007_book_set_number.xml");
    return "test_0007_book_set_number";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0007_BOOK_SET_NUMBER_HPP */
