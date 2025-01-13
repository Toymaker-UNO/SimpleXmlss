#ifndef SIMPLE_XMLSS_TEST_0008_BOOK_SET_NUMBER_HPP
#define SIMPLE_XMLSS_TEST_0008_BOOK_SET_NUMBER_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0008_book_set_number : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

    simple_xmlss::book new_book("new_book");
    new_book.set_number("12345",  "Sheet No 1",  1, 1, 1, 1);
    new_book.set_number("3.14",   "Sheet No 1",  3, 3, 2, 2);
    new_book.set_number("-12345", "Sheet No 1",  6, 6, 0, 2);
    new_book.set_number("-1.25",  "Sheet No 1",  7, 7, 4, 4);
    new_book.set_number("-12345", "Sheet No 1",  12, 12, 1, 0);
    new_book.print_xmlss("./test_0008_book_set_number.xml");
    return "test_0008_book_set_number";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0008_BOOK_SET_NUMBER_HPP */
