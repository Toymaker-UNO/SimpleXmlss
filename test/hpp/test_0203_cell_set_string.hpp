#ifndef SIMPLE_XMLSS_TEST_0203_CELL_SET_STRING_HPP
#define SIMPLE_XMLSS_TEST_0203_CELL_SET_STRING_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0203_cell_set_string : public abstract_test_case {
public:
  std::string run(void) {
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

    simple_xmlss::model::cell_string new_cell_string1 = simple_xmlss::builder::string::instance().
                                                                            clear().
                                                                            set_string("A1", font_id1).
                                                                            set_string(" ").
                                                                            set_string("Data", font_id2).
                                                                            build();

    simple_xmlss::model::cell_string new_cell_string2 = simple_xmlss::builder::string::instance().
                                                                            clear().
                                                                            set_string("B2", font_id1).
                                                                            set_string(" ").
                                                                            set_string("Data:", font_id2).
                                                                            set_string(" ").
                                                                            set_string("&", font_id1).
                                                                            build();

    simple_xmlss::model::cell_string new_cell_string3 = simple_xmlss::builder::string::instance().
                                                                            clear().
                                                                            set_string("C3", font_id1).
                                                                            set_string(" ").
                                                                            set_string("Data:", font_id2).
                                                                            set_string(" ").
                                                                            set_string("<", font_id1).
                                                                            build();

    simple_xmlss::model::cell_string new_cell_string4 = simple_xmlss::builder::string::instance().
                                                                            clear().
                                                                            set_string("D4", font_id1).
                                                                            set_string(" ").
                                                                            set_string("Data:", font_id2).
                                                                            set_string(" ").
                                                                            set_string(">", font_id1).
                                                                            build();

    simple_xmlss::model::cell_string new_cell_string5 = simple_xmlss::builder::string::instance().
                                                                            clear().
                                                                            set_string("E5", font_id1).
                                                                            set_string(" ").
                                                                            set_string("Data:", font_id2).
                                                                            set_string(" ").
                                                                            set_string("\"", font_id1).
                                                                            build();

    simple_xmlss::model::cell_string new_cell_string6 = simple_xmlss::builder::string::instance().
                                                                            clear().
                                                                            set_string("F6", font_id1).
                                                                            set_string(" ").
                                                                            set_string("Data:", font_id2).
                                                                            set_string(" ").
                                                                            set_string("'", font_id1).
                                                                            build();

    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    simple_xmlss::cell& cell1 = new_sheet1.get_cell(1,1);
    simple_xmlss::cell& cell2 = new_sheet1.get_cell(2,2);
    simple_xmlss::cell& cell3 = new_sheet1.get_cell(3,3);
    simple_xmlss::cell& cell4 = new_sheet1.get_cell(4,4);
    simple_xmlss::cell& cell5 = new_sheet1.get_cell(5,5);
    simple_xmlss::cell& cell6 = new_sheet1.get_cell(6,6);
    cell1.set_string(new_cell_string1);
    cell2.set_string(new_cell_string2);
    cell3.set_string(new_cell_string3);
    cell4.set_string(new_cell_string4);
    cell5.set_string(new_cell_string5);
    cell6.set_string(new_cell_string6);
    
    new_book.print_xmlss("./test_0203_cell_set_string.xml");
    return "test_0203_cell_set_string";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0203_CELL_SET_STRING_HPP */
