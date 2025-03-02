#ifndef SIMPLE_XMLSS_TEST_0013_BOOK_SET_COMMENT_HPP
#define SIMPLE_XMLSS_TEST_0013_BOOK_SET_COMMENT_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0013_book_set_comment : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::book new_book("new_book");
    new_book.set_string("A1 Data",       "Sheet No 1", 1, 1);
    new_book.set_string("B2 Data",       "Sheet No 1", 2, 2);
    new_book.set_string("C3 Data",       "Sheet No 1", 3, 3);
    new_book.set_string("D4 Data: &",    "Sheet No 1", 4, 4);
    new_book.set_string("E5 Data: <",    "Sheet No 1", 5, 5);
    new_book.set_string("F6 Data: >",    "Sheet No 1", 6, 6);
    new_book.set_string("G7 Data: \"",   "Sheet No 1", 7, 7);
    new_book.set_string("H8 Data: '",    "Sheet No 1", 8, 8);

    new_book.set_comment("A1 Data",       "Sheet No 1", 1, 1);
    new_book.set_comment("B2 Data",       "Sheet No 1", 2, 2);
    new_book.set_comment("C3 Data",       "Sheet No 1", 3, 3);
    new_book.set_comment("D4 Data: &",    "Sheet No 1", 4, 4);
    new_book.set_comment("E5 Data: <",    "Sheet No 1", 5, 5);
    new_book.set_comment("F6 Data: >",    "Sheet No 1", 6, 6);
    new_book.set_comment("G7 Data: \"",   "Sheet No 1", 7, 7);
    new_book.set_comment("H8 Data: '",    "Sheet No 1", 8, 8);
    new_book.print_xmlss("./test_0013_book_set_comment.xml");
    return "test_0013_book_set_comment";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0013_BOOK_SET_COMMENT_HPP */
