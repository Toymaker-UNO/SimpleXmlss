#ifndef SIMPLE_XMLSS_TEST_0018_BOOK_SET_STYLE_ID_HPP
#define SIMPLE_XMLSS_TEST_0018_BOOK_SET_STYLE_ID_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0018_book_set_style_id : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

    simple_xmlss::book new_book("new_book");
    unsigned int style_id = simple_xmlss::builder::style::instance().
                                set_fill_background_color("#00FF00").
                                set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID).
                                set_alignment_text_control(model::STYLE_ALIGNMENT_TEXT_CONTROL::WRAP_TEXT).
                                build();
    new_book.set_string("C3 Data",       "Sheet No 1", 3, 3);
    new_book.set_string("D4 Data: &",    "Sheet No 1", 4, 4);
    new_book.set_string("E5 Data: <",    "Sheet No 1", 5, 5);
    new_book.set_string("F6 Data: >",    "Sheet No 1", 6, 6);
    new_book.set_string("G7 Data: \"",   "Sheet No 1", 7, 7);
    new_book.set_string("H8 Data: '",    "Sheet No 1", 8, 8);

    new_book.set_style_id(style_id, "Sheet No 1", 3, 3);
    new_book.set_style_id(style_id, "Sheet No 1", 4, 4);
    new_book.set_style_id(style_id, "Sheet No 1", 5, 5);
    new_book.set_style_id(style_id, "Sheet No 1", 6, 6);
    new_book.set_style_id(style_id, "Sheet No 1", 7, 7);
    new_book.set_style_id(style_id, "Sheet No 1", 8, 8);
    
    new_book.print_xmlss("./test_0018_book_set_style_id.xml");
    return "test_0018_book_set_style_id";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0018_BOOK_SET_STYLE_ID_HPP */
