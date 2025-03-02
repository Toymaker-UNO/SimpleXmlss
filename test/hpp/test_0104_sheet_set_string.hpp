#ifndef SIMPLE_XMLSS_TEST_0104_SHEET_SET_STRING_HPP
#define SIMPLE_XMLSS_TEST_0104_SHEET_SET_STRING_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0104_sheet_set_string : public abstract_test_case {
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
    new_sheet1.set_string("A1 Data",     font_id2, 1, 1,   1, 1);
    new_sheet1.set_string("B2 Data: &",  font_id1, 3, 3,   1, 1);
    new_sheet1.set_string("C3 Data: <",  font_id2, 5, 5,   2, 2);
    new_sheet1.set_string("D4 Data: >",  font_id1, 8, 8,   1, 1);
    new_sheet1.set_string("E5 Data: \"", font_id2, 10, 10, 3, 3);
    new_sheet1.set_string("F6 Data: '",  font_id1, 14, 14, 5, 5);

    new_book.print_xmlss("./test_0104_sheet_set_string.xml");
    return "test_0104_sheet_set_string";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0104_SHEET_SET_STRING_HPP */
