#ifndef SIMPLE_XMLSS_TEST_0212_CELL_SET_STYLE_ID_HPP
#define SIMPLE_XMLSS_TEST_0212_CELL_SET_STYLE_ID_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0212_cell_set_style_id : public abstract_test_case {
public:
  std::string run(void) {
    unsigned int style_id = simple_xmlss::builder::style::instance().
                                set_fill_background_color("#00FF00").
                                set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID).
                                set_alignment_text_control(model::STYLE_ALIGNMENT_TEXT_CONTROL::WRAP_TEXT).
                                build();

    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    simple_xmlss::cell& cell3 = new_sheet1.get_cell(3,3);
    simple_xmlss::cell& cell4 = new_sheet1.get_cell(4,4);
    simple_xmlss::cell& cell5 = new_sheet1.get_cell(5,5);
    simple_xmlss::cell& cell6 = new_sheet1.get_cell(6,6);
    simple_xmlss::cell& cell7 = new_sheet1.get_cell(7,7);
    simple_xmlss::cell& cell8 = new_sheet1.get_cell(8,8);

    cell3.set_string("C3 Data").set_style_id(style_id);
    cell4.set_string("D4 Data: &").set_style_id(style_id);
    cell5.set_string("E5 Data: <").set_style_id(style_id);
    cell6.set_string("F6 Data: >").set_style_id(style_id);
    cell7.set_string("G7 Data: \"").set_style_id(style_id);
    cell8.set_string("H8 Data: '").set_style_id(style_id);
    
    new_book.print_xmlss("./test_0212_cell_set_style_id.xml");
    return "test_0212_cell_set_style_id";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0212_CELL_SET_STYLE_ID_HPP */
