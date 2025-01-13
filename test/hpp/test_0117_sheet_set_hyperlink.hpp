#ifndef SIMPLE_XMLSS_TEST_0117_SHEET_SET_HYPERLINK_HPP
#define SIMPLE_XMLSS_TEST_0117_SHEET_SET_HYPERLINK_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0117_sheet_set_hyperlink : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();
    
    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    simple_xmlss::sheet& new_sheet2 = new_book.get_sheet("Sheet No 2");

    new_sheet1.set_string("A1 Data", 1, 1);
    new_sheet2.set_string("A1 Data", 1, 1);
    new_sheet1.set_hyperlink("Sheet No 2", 1, 1, 1, 1);

    new_book.print_xmlss("./test_0117_sheet_set_hyperlink.xml");
    return "test_0117_sheet_set_hyperlink";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0117_SHEET_SET_HYPERLINK_HPP */
