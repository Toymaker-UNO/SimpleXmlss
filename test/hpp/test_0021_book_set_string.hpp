#ifndef SIMPLE_XMLSS_TEST_0021_BOOK_SET_STRING_HPP
#define SIMPLE_XMLSS_TEST_0021_BOOK_SET_STRING_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0021_book_set_string : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

    simple_xmlss::book new_book("new_book");
    new_book.set_string("Cat",     "Pet", 1, 1);
    new_book.set_string("Dog",     "Pet", 2, 2);
    new_book.set_string("Porsche", "Car", 3, 3);
    new_book.print_xmlss("./test_0021_book_set_string.xml");
    return "test_0021_book_set_string";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0021_BOOK_SET_STRING_HPP */
