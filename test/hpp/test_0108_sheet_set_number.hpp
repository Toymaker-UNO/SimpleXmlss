#ifndef SIMPLE_XMLSS_TEST_0108_SHEET_SET_NUMBER_HPP
#define SIMPLE_XMLSS_TEST_0108_SHEET_SET_NUMBER_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0108_sheet_set_number : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    new_sheet1.set_number("12345",  1, 1, 1, 1);
    new_sheet1.set_number("3.14",   3, 3, 2, 2);
    new_sheet1.set_number("-12345", 6, 6, 0, 2);
    new_sheet1.set_number("-1.25",  7, 7, 4, 4);
    new_sheet1.set_number("-12345", 12, 12, 1, 0);
    new_book.print_xmlss("./test_0108_sheet_set_number.xml");
    return "test_0108_sheet_set_number";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0108_SHEET_SET_NUMBER_HPP */
