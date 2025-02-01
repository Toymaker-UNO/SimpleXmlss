#ifndef SIMPLE_XMLSS_TEST_0206_CELL_SET_FORMULA_HPP
#define SIMPLE_XMLSS_TEST_0206_CELL_SET_FORMULA_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0206_cell_set_formula : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    simple_xmlss::cell& cell1 = new_sheet1.get_cell(1,1);
    simple_xmlss::cell& cell2 = new_sheet1.get_cell(1,2);
    simple_xmlss::cell& cell3 = new_sheet1.get_cell(1,3);
    simple_xmlss::cell& cell4 = new_sheet1.get_cell(1,4);
    cell1.set_number("12345");
    cell2.set_number("56789");
    cell3.set_formula("=R[-1]C[0]");
    cell4.set_formula("=R[-3]C[0]");

    new_book.print_xmlss("./test_0206_cell_set_formula.xml");
    return "test_0206_cell_set_formula";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0206_CELL_SET_FORMULA_HPP */
