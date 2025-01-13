#ifndef SIMPLE_XMLSS_TEST_0111_SHEET_SET_FORMULA_HPP
#define SIMPLE_XMLSS_TEST_0111_SHEET_SET_FORMULA_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0111_sheet_set_formula : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    new_sheet1.set_number("12345",  1, 1);
    new_sheet1.set_number("56789",  1, 2);
    new_sheet1.set_formula("=R[-1]C[0]", 1, 3);
    new_sheet1.set_formula("=R[-3]C[0]", 1, 4);

    new_book.print_xmlss("./test_0111_sheet_set_formula.xml");
    return "test_0111_sheet_set_formula";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0111_SHEET_SET_FORMULA_HPP */
