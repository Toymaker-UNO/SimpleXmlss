#ifndef SIMPLE_XMLSS_TEST_0401_COMPLEX_CASE_HPP
#define SIMPLE_XMLSS_TEST_0401_COMPLEX_CASE_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0401_complex_case : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::book new_book("new_book");

    new_book.get_sheet("Sheet No 1").
             set_row_height(1,40).
             set_row_height(2,40).
             set_row_height(3,40).
             set_row_height(4,40).
             set_col_width(1,300).
             set_col_width(2,300).
             set_col_width(3,300).
             set_col_width(4,300).
             set_col_width(5,300).
             set_col_width(6,300).
             set_col_width(7,300);

    unsigned int font_red = builder::font::instance().
                            clear().
                            set_size(15).
                            set_italic(true).
                            set_color("#FF0000").
                            build();

    unsigned int style_01 = builder::style::instance().
                             clear().
                             set_fill_background_color("#222222").
                             //set_fill_pattern_color("#BBBBBB").
                             set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID).
                             set_font_id(font_red).
                             build();

    unsigned int font_yellow = builder::font::instance().
                            clear().
                            set_size(11).
                            set_bold(true).
                            set_color("#00FFFF").
                            build();
    
    unsigned int font_green = builder::font::instance().
                            clear().
                            set_size(11).
                            set_bold(true).
                            set_color("#00FF00").
                            build();
                             
    new_book.set_string("ABCDEFG", "Sheet No 1", 1, 1).set_style_id(style_01);
    new_book.set_string("ABCDEFG", font_yellow, "Sheet No 1", 2, 1).set_style_id(style_01);

    auto string_01 = builder::string::instance().
                        clear().
                        set_string("AB").
                        set_string("CD",font_yellow).
                        set_string("EF").
                        set_string("GH",font_green).
                        build();

    new_book.set_string(string_01, "Sheet No 1", 3, 1).set_style_id(style_01);

    new_book.print_xmlss("./test_0401_complex_case.xml");
    return "test_0401_complex_case";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0401_COMPLEX_CASE_HPP */
