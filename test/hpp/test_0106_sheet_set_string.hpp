#ifndef SIMPLE_XMLSS_TEST_0106_SHEET_SET_STRING_HPP
#define SIMPLE_XMLSS_TEST_0106_SHEET_SET_STRING_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0106_sheet_set_string : public abstract_test_case {
public:
  std::string run(void) {
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

    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");

    simple_xmlss::model::cell_string new_cell_string1 = simple_xmlss::builder::string::instance().
                                                                            clear().
                                                                            set_string("A1", font_id1).
                                                                            set_string(" ").
                                                                            set_string("Data", font_id2).
                                                                            build();
    new_sheet1.set_string(new_cell_string1, 1, 1, 1, 1);

    simple_xmlss::model::cell_string new_cell_string2 = simple_xmlss::builder::string::instance().
                                                                            clear().
                                                                            set_string("C3", font_id1).
                                                                            set_string(" ").
                                                                            set_string("Data:", font_id2).
                                                                            set_string(" ").
                                                                            set_string("&", font_id1).
                                                                            build();
    new_sheet1.set_string(new_cell_string2, 3, 3, 0, 1);

    simple_xmlss::model::cell_string new_cell_string3 = simple_xmlss::builder::string::instance().
                                                                            clear().
                                                                            set_string("E5", font_id1).
                                                                            set_string(" ").
                                                                            set_string("Data:", font_id2).
                                                                            set_string(" ").
                                                                            set_string("<", font_id1).
                                                                            build();
    new_sheet1.set_string(new_cell_string3, 5, 5, 1, 0);

    simple_xmlss::model::cell_string new_cell_string4 = simple_xmlss::builder::string::instance().
                                                                            clear().
                                                                            set_string("G7", font_id1).
                                                                            set_string(" ").
                                                                            set_string("Data:", font_id2).
                                                                            set_string(" ").
                                                                            set_string(">", font_id1).
                                                                            build();
    new_sheet1.set_string(new_cell_string4, 7, 7, 2, 2);

    simple_xmlss::model::cell_string new_cell_string5 = simple_xmlss::builder::string::instance().
                                                                            clear().
                                                                            set_string("J10", font_id1).
                                                                            set_string(" ").
                                                                            set_string("Data:", font_id2).
                                                                            set_string(" ").
                                                                            set_string("\"", font_id1).
                                                                            build();
    new_sheet1.set_string(new_cell_string5, 10, 10, 1, 1);

    simple_xmlss::model::cell_string new_cell_string6 = simple_xmlss::builder::string::instance().
                                                                            clear().
                                                                            set_string("L12", font_id1).
                                                                            set_string(" ").
                                                                            set_string("Data:", font_id2).
                                                                            set_string(" ").
                                                                            set_string("'", font_id1).
                                                                            build();
    new_sheet1.set_string(new_cell_string6, 12, 12, 3, 4);
    
    new_book.print_xmlss("./test_0106_sheet_set_string.xml");
    return "test_0106_sheet_set_string";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0106_SHEET_SET_STRING_HPP */
