#ifndef SIMPLE_XMLSS_TEST_0114_SHEET_SET_COMMENT_HPP
#define SIMPLE_XMLSS_TEST_0114_SHEET_SET_COMMENT_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0114_sheet_set_comment : public abstract_test_case {
public:
  std::string run(void) {    
    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");

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

    new_sheet1.set_string("A1 Data",       font_id1,  1, 1);
    new_sheet1.set_string("B2 Data",       font_id2,  2, 2);
    new_sheet1.set_string("C3 Data",       font_id1,  3, 3);
    new_sheet1.set_string("D4 Data: &",    font_id1,  4, 4);
    new_sheet1.set_string("E5 Data: <",    font_id2,  5, 5);
    new_sheet1.set_string("F6 Data: >",    font_id1,  6, 6);
    new_sheet1.set_string("G7 Data: \"",   font_id2,  7, 7);
    new_sheet1.set_string("H8 Data: '",    font_id1,  8, 8);                            

    new_sheet1.set_comment("A1 Data",       font_id1,  1, 1);
    new_sheet1.set_comment("B2 Data",       font_id2,  2, 2);
    new_sheet1.set_comment("C3 Data",       font_id1,  3, 3);
    new_sheet1.set_comment("D4 Data: &",    font_id1,  4, 4);
    new_sheet1.set_comment("E5 Data: <",    font_id2,  5, 5);
    new_sheet1.set_comment("F6 Data: >",    font_id1,  6, 6);
    new_sheet1.set_comment("G7 Data: \"",   font_id2,  7, 7);
    new_sheet1.set_comment("H8 Data: '",    font_id1,  8, 8);

    new_book.print_xmlss("./test_0114_sheet_set_comment.xml");
    return "test_0114_sheet_set_comment";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0114_SHEET_SET_COMMENT_HPP */
