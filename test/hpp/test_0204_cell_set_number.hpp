#ifndef SIMPLE_XMLSS_SHEET_0204_CELL_SET_NUMBER_HPP
#define SIMPLE_XMLSS_SHEET_0204_CELL_SET_NUMBER_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0204_cell_set_number : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    simple_xmlss::cell& cell1 = new_sheet1.get_cell(1,1);
    simple_xmlss::cell& cell2 = new_sheet1.get_cell(2,2);
    simple_xmlss::cell& cell3 = new_sheet1.get_cell(3,3);
    simple_xmlss::cell& cell4 = new_sheet1.get_cell(4,4);
    cell1.set_number("12345");
    cell2.set_number("3.14");
    cell3.set_number("-12345");
    cell4.set_number("-1.25");
    new_book.print_xmlss("./test_0204_cell_set_number.xml");
    return "test_0204_cell_set_number";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_SHEET_0204_CELL_SET_NUMBER_HPP */
