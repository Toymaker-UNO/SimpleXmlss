#ifndef SIMPLE_XMLSS_TEST_0014_BOOK_SET_COMMENT_HPP
#define SIMPLE_XMLSS_TEST_0014_BOOK_SET_COMMENT_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0014_book_set_comment : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();
    
    simple_xmlss::book new_book("new_book");
    unsigned int font_id1 = builder::font::instance().
                            clear().
                            set_color("#FF0000").
                            set_size(9).
                            set_underline(model::FONT_UNDERLINE::SINGLE).
                            set_italic(true).
                            set_bold(true).
                            build();

    unsigned int font_id2 = builder::font::instance().
                            clear().
                            set_color("#0000FF").
                            set_size(11).
                            build();

    new_book.set_string("A1 Data",       font_id1,  "Sheet No 1", 1, 1);
    new_book.set_string("B2 Data",       font_id2,  "Sheet No 1", 2, 2);
    new_book.set_string("C3 Data",       font_id1,  "Sheet No 1", 3, 3);
    new_book.set_string("D4 Data: &",    font_id1,  "Sheet No 1", 4, 4);
    new_book.set_string("E5 Data: <",    font_id2,  "Sheet No 1", 5, 5);
    new_book.set_string("F6 Data: >",    font_id1,  "Sheet No 1", 6, 6);
    new_book.set_string("G7 Data: \"",   font_id2,  "Sheet No 1", 7, 7);
    new_book.set_string("H8 Data: '",    font_id1,  "Sheet No 1", 8, 8);                            

    new_book.set_comment("A1 Data",       font_id1,  "Sheet No 1", 1, 1);
    new_book.set_comment("B2 Data",       font_id2,  "Sheet No 1", 2, 2);
    new_book.set_comment("C3 Data",       font_id1,  "Sheet No 1", 3, 3);
    new_book.set_comment("D4 Data: &",    font_id1,  "Sheet No 1", 4, 4);
    new_book.set_comment("E5 Data: <",    font_id2,  "Sheet No 1", 5, 5);
    new_book.set_comment("F6 Data: >",    font_id1,  "Sheet No 1", 6, 6);
    new_book.set_comment("G7 Data: \"",   font_id2,  "Sheet No 1", 7, 7);
    new_book.set_comment("H8 Data: '",    font_id1,  "Sheet No 1", 8, 8);

    new_book.print_xmlss("./test_0014_book_set_comment.xml");
    return "test_0014_book_set_comment";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0014_BOOK_SET_COMMENT_HPP */
