#ifndef SIMPLE_XMLSS_TEST_0118_SHEET_SET_STYLE_ID_HPP
#define SIMPLE_XMLSS_TEST_0118_SHEET_SET_STYLE_ID_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0118_sheet_set_style_id : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    unsigned int style_id = simple_xmlss::builder::style::instance().
                                set_fill_background_color("#00FF00").
                                set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID).
                                set_alignment_text_control(model::STYLE_ALIGNMENT_TEXT_CONTROL::WRAP_TEXT).
                                build();
    new_sheet1.set_string("C3 Data",       3, 3);
    new_sheet1.set_string("D4 Data: &",    4, 4);
    new_sheet1.set_string("E5 Data: <",    5, 5);
    new_sheet1.set_string("F6 Data: >",    6, 6);
    new_sheet1.set_string("G7 Data: \"",   7, 7);
    new_sheet1.set_string("H8 Data: '",    8, 8);

    new_sheet1.set_style_id(style_id, 3, 3);
    new_sheet1.set_style_id(style_id, 4, 4);
    new_sheet1.set_style_id(style_id, 5, 5);
    new_sheet1.set_style_id(style_id, 6, 6);
    new_sheet1.set_style_id(style_id, 7, 7);
    new_sheet1.set_style_id(style_id, 8, 8);
    
    new_book.print_xmlss("./test_0118_sheet_set_style_id.xml");
    return "test_0118_sheet_set_style_id";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0118_SHEET_SET_STYLE_ID_HPP */
