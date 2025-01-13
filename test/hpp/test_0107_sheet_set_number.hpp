#ifndef SIMPLE_XMLSS_SHEET_0107_SHEET_SET_NUMBER_HPP
#define SIMPLE_XMLSS_SHEET_0107_SHEET_SET_NUMBER_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0107_sheet_set_number : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    new_sheet1.set_number("12345",  1, 1);
    new_sheet1.set_number("3.14",   2, 2);
    new_sheet1.set_number("-12345", 3, 3);
    new_sheet1.set_number("-1.25",  4, 4);
    new_book.print_xmlss("./test_0107_sheet_set_number.xml");
    return "test_0107_sheet_set_number";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_SHEET_0107_SHEET_SET_NUMBER_HPP */
