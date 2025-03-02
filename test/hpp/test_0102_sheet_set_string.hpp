#ifndef SIMPLE_XMLSS_TEST_0102_SHEET_SET_STRING_HPP
#define SIMPLE_XMLSS_TEST_0102_SHEET_SET_STRING_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0102_sheet_set_string : public abstract_test_case {
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
    simple_xmlss::sheet& new_sheet2 = new_book.get_sheet("Sheet No 2");
    simple_xmlss::sheet& new_sheet3 = new_book.get_sheet("Sheet No 3");
    simple_xmlss::sheet& new_sheet4 = new_book.get_sheet("Sheet No 4");

    new_sheet1.set_string("A1 Data",     font_id1, 1, 1);
    new_sheet1.set_string("B2 Data: &",  font_id2, 2, 2);
    new_sheet1.set_string("C3 Data: <",  font_id1, 3, 3);
    new_sheet1.set_string("D4 Data: >",  font_id2, 4, 4);
    new_sheet1.set_string("E5 Data: \"", font_id1, 5, 5);
    new_sheet1.set_string("F6 Data: '",  font_id2, 6, 6);
    
    for(unsigned int row = 1; row <= 100; row++) {
      for(unsigned int col = 1; col <= 100; col++) {
        std::string contents = utility::column2string(col);
        contents += std::to_string(row);
        contents += " Data";
        new_sheet2.set_string(contents, font_id2, col, row);
        new_sheet3.set_string(contents, font_id1, col, row);
        new_sheet4.set_string(contents, font_id2, col, row);
      }
    }

    new_book.print_xmlss("./test_0102_sheet_set_string.xml");
    return "test_0102_sheet_set_string";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0102_SHEET_SET_STRING_HPP */
