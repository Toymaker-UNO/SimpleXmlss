#ifndef SIMPLE_XMLSS_TEST_0001_BOOK_SET_STRING_HPP
#define SIMPLE_XMLSS_TEST_0001_BOOK_SET_STRING_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0001_book_set_string : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

    simple_xmlss::book new_book("new_book");
    new_book.set_string("A1 Data",     "Sheet No 1", 1, 1);
    new_book.set_string("B2 Data: &",  "Sheet No 1", 2, 2);
    new_book.set_string("C3 Data: <",  "Sheet No 1", 3, 3);
    new_book.set_string("D4 Data: >",  "Sheet No 1", 4, 4);
    new_book.set_string("E5 Data: \"", "Sheet No 1", 5, 5);
    new_book.set_string("F6 Data: '",  "Sheet No 1", 6, 6);
    
    for(unsigned int row = 1; row <= 100; row++) {
      for(unsigned int col = 1; col <= 100; col++) {
        std::string contents = utility::column2string(col);
        contents += std::to_string(row);
        contents += " Data";
        new_book.set_string(contents, "Sheet No 2", col, row);
        new_book.set_string(contents, "Sheet No 3", col, row);
        new_book.set_string(contents, "Sheet No 4", col, row);
      }
    }
    new_book.print_xmlss("./test_0001_book_set_string.xml");
    return "test_0001_book_set_string";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0001_BOOK_SET_STRING_HPP */
