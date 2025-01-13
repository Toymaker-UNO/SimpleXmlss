#ifndef SIMPLE_XMLSS_TEST_0210_CELL_SET_HYPERLINK_HPP
#define SIMPLE_XMLSS_TEST_0210_CELL_SET_HYPERLINK_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0210_cell_set_hyperlink : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();
    
    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    simple_xmlss::cell& cell1 = new_sheet1.get_cell(1,1);
    cell1.set_string("A1 Data").set_hyperlink("https://www.naver.com");

    new_book.print_xmlss("./test_0210_cell_set_hyperlink.xml");
    return "test_0210_cell_set_hyperlink";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0210_CELL_SET_HYPERLINK_HPP */
