#ifndef SIMPLE_XMLSS_TEST_0121_SHEET_SET_TAB_CLOLR_HPP
#define SIMPLE_XMLSS_TEST_0121_SHEET_SET_TAB_CLOLR_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0121_sheet_set_tab_color : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    simple_xmlss::sheet& new_sheet2 = new_book.get_sheet("Sheet No 2");
    simple_xmlss::sheet& new_sheet3 = new_book.get_sheet("Sheet No 3");
    simple_xmlss::sheet& new_sheet4 = new_book.get_sheet("Sheet No 4");
    simple_xmlss::sheet& new_sheet5 = new_book.get_sheet("Sheet No 5");
    simple_xmlss::sheet& new_sheet6 = new_book.get_sheet("Sheet No 6");
    simple_xmlss::sheet& new_sheet7 = new_book.get_sheet("Sheet No 7");
    simple_xmlss::sheet& new_sheet8 = new_book.get_sheet("Sheet No 8");
    simple_xmlss::sheet& new_sheet9 = new_book.get_sheet("Sheet No 9");
    simple_xmlss::sheet& new_sheet10 = new_book.get_sheet("Sheet No 10");
    simple_xmlss::sheet& new_sheet11 = new_book.get_sheet("Sheet No 11");
    simple_xmlss::sheet& new_sheet12 = new_book.get_sheet("Sheet No 12");

    new_sheet1.set_tab_color(model::SHEET_TAB_COLOR::DEFAULT);
    new_sheet2.set_tab_color(model::SHEET_TAB_COLOR::BLACK);
    new_sheet3.set_tab_color(model::SHEET_TAB_COLOR::RED);
    new_sheet4.set_tab_color(model::SHEET_TAB_COLOR::LIME);
    new_sheet5.set_tab_color(model::SHEET_TAB_COLOR::BLUE);
    new_sheet6.set_tab_color(model::SHEET_TAB_COLOR::YELLOW);
    new_sheet7.set_tab_color(model::SHEET_TAB_COLOR::MAGENTA);
    new_sheet8.set_tab_color(model::SHEET_TAB_COLOR::CYAN);
    new_sheet9.set_tab_color(model::SHEET_TAB_COLOR::MAROON);
    new_sheet10.set_tab_color(model::SHEET_TAB_COLOR::GREEN);
    new_sheet11.set_tab_color(model::SHEET_TAB_COLOR::NAVY);
    new_sheet12.set_tab_color(model::SHEET_TAB_COLOR::ORANGE);
    
    new_book.print_xmlss("./test_0121_sheet_set_tab_color.xml");
    return "test_0121_sheet_set_tab_color";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0121_SHEET_SET_TAB_CLOLR_HPP */
