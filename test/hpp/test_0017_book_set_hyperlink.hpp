#ifndef SIMPLE_XMLSS_TEST_0017_BOOK_SET_HYPERLINK_HPP
#define SIMPLE_XMLSS_TEST_0017_BOOK_SET_HYPERLINK_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0017_book_set_hyperlink : public abstract_test_case {
public:
  std::string run(void) {    
    simple_xmlss::book new_book("new_book");

    new_book.set_string("A1 Data", "Sheet No 1", 1, 1);
    new_book.set_string("A1 Data", "Sheet No 2", 1, 1);
    new_book.set_hyperlink("Sheet No 2", 1, 1, "Sheet No 1", 1, 1);

    new_book.print_xmlss("./test_0017_book_set_hyperlink.xml");
    return "test_0017_book_set_hyperlink";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0017_BOOK_SET_HYPERLINK_HPP */
