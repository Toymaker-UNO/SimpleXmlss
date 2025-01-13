#ifndef SIMPLE_XMLSS_TEST_0202_CELL_SET_STRING_HPP
#define SIMPLE_XMLSS_TEST_0202_CELL_SET_STRING_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0202_cell_set_string : public abstract_test_case {
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

    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    simple_xmlss::sheet& new_sheet2 = new_book.get_sheet("Sheet No 2");
    simple_xmlss::sheet& new_sheet3 = new_book.get_sheet("Sheet No 3");
    simple_xmlss::sheet& new_sheet4 = new_book.get_sheet("Sheet No 4");
    simple_xmlss::cell& cell1 = new_sheet1.get_cell(1,1);
    simple_xmlss::cell& cell2 = new_sheet1.get_cell(2,2);
    simple_xmlss::cell& cell3 = new_sheet1.get_cell(3,3);
    simple_xmlss::cell& cell4 = new_sheet1.get_cell(4,4);
    simple_xmlss::cell& cell5 = new_sheet1.get_cell(5,5);
    simple_xmlss::cell& cell6 = new_sheet1.get_cell(6,6);
    cell1.set_string("A1 Data",     font_id1);
    cell2.set_string("B2 Data: &",  font_id2);
    cell3.set_string("C3 Data: <",  font_id1);
    cell4.set_string("D4 Data: >",  font_id2);
    cell5.set_string("E5 Data: \"", font_id1);
    cell6.set_string("F6 Data: '",  font_id2);
    
    for(unsigned int row = 1; row <= 100; row++) {
      for(unsigned int col = 1; col <= 100; col++) {
        std::string contents = utility::column2string(col);
        contents += std::to_string(row);
        contents += " Data";
        simple_xmlss::cell& cell_2 = new_sheet2.get_cell(col,row);
        simple_xmlss::cell& cell_3 = new_sheet3.get_cell(col,row);
        simple_xmlss::cell& cell_4 = new_sheet4.get_cell(col,row);

        cell_2.set_string(contents, font_id2);
        cell_3.set_string(contents, font_id1);
        cell_4.set_string(contents, font_id2);
      }
    }

    new_book.print_xmlss("./test_0202_cell_set_string.xml");
    return "test_0202_cell_set_string";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0202_CELL_SET_STRING_HPP */
