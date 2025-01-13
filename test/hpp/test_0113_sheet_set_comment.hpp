#ifndef SIMPLE_XMLSS_TEST_0113_SHEET_SET_COMMENT_HPP
#define SIMPLE_XMLSS_TEST_0113_SHEET_SET_COMMENT_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0113_sheet_set_comment : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    new_sheet1.set_string("A1 Data",       1, 1);
    new_sheet1.set_string("B2 Data",       2, 2);
    new_sheet1.set_string("C3 Data",       3, 3);
    new_sheet1.set_string("D4 Data: &",    4, 4);
    new_sheet1.set_string("E5 Data: <",    5, 5);
    new_sheet1.set_string("F6 Data: >",    6, 6);
    new_sheet1.set_string("G7 Data: \"",   7, 7);
    new_sheet1.set_string("H8 Data: '",    8, 8);

    new_sheet1.set_comment("A1 Data",      1, 1);
    new_sheet1.set_comment("B2 Data",      2, 2);
    new_sheet1.set_comment("C3 Data",      3, 3);
    new_sheet1.set_comment("D4 Data: &",   4, 4);
    new_sheet1.set_comment("E5 Data: <",   5, 5);
    new_sheet1.set_comment("F6 Data: >",   6, 6);
    new_sheet1.set_comment("G7 Data: \"",  7, 7);
    new_sheet1.set_comment("H8 Data: '",   8, 8);
    new_book.print_xmlss("./test_0113_sheet_set_comment.xml");
    return "test_0113_sheet_set_comment";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0113_SHEET_SET_COMMENT_HPP */
