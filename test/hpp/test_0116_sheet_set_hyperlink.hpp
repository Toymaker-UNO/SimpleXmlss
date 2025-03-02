#ifndef SIMPLE_XMLSS_TEST_0116_SHEET_SET_HYPERLINK_HPP
#define SIMPLE_XMLSS_TEST_0116_SHEET_SET_HYPERLINK_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0116_sheet_set_hyperlink : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    new_sheet1.set_string("A1 Data", 1, 1);
    new_sheet1.set_hyperlink("https://www.naver.com", 1, 1);

    new_book.print_xmlss("./test_0116_sheet_set_hyperlink.xml");
    return "test_0116_sheet_set_hyperlink";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0116_SHEET_SET_HYPERLINK_HPP */
