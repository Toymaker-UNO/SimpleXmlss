#ifndef SIMPLE_XMLSS_TEST_0302_BUILDER_FONT_HPP
#define SIMPLE_XMLSS_TEST_0302_BUILDER_FONT_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0302_builder_font : public abstract_test_case {
public:
  std::string run(void) {
    unsigned int font_gullim = builder::font::instance().
                               clear().
                               set_name("굴림체").
                               build(); 

    unsigned int font_gungso = builder::font::instance().
                               clear().
                               set_name("궁서체").
                               build();

    unsigned int font_gungso2 = builder::font::instance().
                               clear().
                               set_name("궁서체").
                               set_char_set(model::FONT_CHAR_SET::RUSSIAN_CHARSET).
                               build(); 

    unsigned int font_red = builder::font::instance().
                            clear().
                            set_color("#FF0000").
                            build();

    unsigned int font_green = builder::font::instance().
                              clear().
                              set_size(14).
                              set_color("#00FF00").
                              build();

    unsigned int font_blue1 = builder::font::instance().
                              clear().
                              set_size(12).
                              set_color("#0000FF").
                              set_underline(model::FONT_UNDERLINE::NONE).
                              build();

    unsigned int font_blue2 = builder::font::instance().
                              clear().
                              set_size(12).
                              set_color("#0000FF").
                              set_underline(model::FONT_UNDERLINE::SINGLE).
                              build();

    unsigned int font_blue3 = builder::font::instance().
                              clear().
                              set_size(12).
                              set_color("#0000FF").
                              set_underline(model::FONT_UNDERLINE::DOUBLE).
                              build();

    unsigned int font_rg1 =   builder::font::instance().
                              clear().
                              set_size(12).
                              set_color("#555500").
                              set_underline(model::FONT_UNDERLINE::SINGLE_ACCOUNTING).
                              build();

    unsigned int font_rg2 =   builder::font::instance().
                              clear().
                              set_size(12).
                              set_color("#555500").
                              set_underline(model::FONT_UNDERLINE::DOUBLE_ACCOUNTING).
                              build();    

    unsigned int style_rg1 = builder::style::instance().
                             clear().
                             set_font_id(font_rg1).
                             build();

    unsigned int style_rg2 = builder::style::instance().
                             clear().
                             set_font_id(font_rg2).
                             build();

    unsigned int font_gb1 =   builder::font::instance().
                              clear().
                              set_size(10).
                              set_color("#007777").
                              set_superscript_subscript(model::FONT_SUPERSCRIPT_SUBSCRIPT::NONE).
                              build();

    unsigned int font_gb2 =   builder::font::instance().
                              clear().
                              set_size(10).
                              set_color("#007777").
                              set_superscript_subscript(model::FONT_SUPERSCRIPT_SUBSCRIPT::SUBSCRIPT).
                              build();

    unsigned int font_gb3 =   builder::font::instance().
                              clear().
                              set_size(10).
                              set_color("#007777").
                              set_superscript_subscript(model::FONT_SUPERSCRIPT_SUBSCRIPT::SUPERSCRIPT).
                              build();

    auto string_data = builder::string::instance().
                          clear().
                          set_string("AAA", font_gb1).
                          set_string("AAA", font_gb2).
                          set_string("AAA", font_gb3).
                          build();

    unsigned int font_7   =   builder::font::instance().
                              clear().
                              set_size(14).
                              set_color("#777777").
                              set_italic(true).
                              build();

    unsigned int font_8   =   builder::font::instance().
                              clear().
                              set_size(14).
                              set_color("#888888").
                              set_bold(true).
                              build();
    
    unsigned int font_9   =   builder::font::instance().
                              clear().
                              set_size(14).
                              set_color("#999999").
                              set_strikethrough(true).
                              build();

    unsigned int font_A   =   builder::font::instance().
                              clear().
                              set_size(14).
                              set_color("#AAAAAA").
                              set_italic(true).
                              set_bold(true).
                              set_strikethrough(true).
                              build();

    simple_xmlss::book new_book("new_book");
    new_book.set_string("굴림체",     font_gullim ,   "Sheet No 1", 1, 1);
    new_book.set_string("궁서체",     font_gungso ,   "Sheet No 1", 1, 2);
    new_book.set_string("궁서체",     font_gungso2 ,  "Sheet No 1", 1, 3);
    new_book.set_string("Font Red",   font_red,       "Sheet No 1", 1, 4);
    new_book.set_string("Font Green", font_green,     "Sheet No 1", 1, 5);
    new_book.set_string("Font BLUE1", font_blue1,     "Sheet No 1", 1, 6);
    new_book.set_string("Font BLUE2", font_blue2,     "Sheet No 1", 1, 7);
    new_book.set_string("Font BLUE2", font_blue3,     "Sheet No 1", 1, 8);
    new_book.set_number("12345", "Sheet No 1", 1, 9);
    new_book.set_style_id(style_rg1, "Sheet No 1", 1, 9);
    new_book.set_number("12345", "Sheet No 1", 1, 10);
    new_book.set_style_id(style_rg2, "Sheet No 1", 1, 10);
    new_book.set_string("Font GB1",   font_gb1,     "Sheet No 1", 1, 11);
    new_book.set_string("Font GB2",   font_gb2,     "Sheet No 1", 1, 12);
    new_book.set_string("Font GB3",   font_gb3,     "Sheet No 1", 1, 13);
    new_book.set_string(string_data, "Sheet No 1", 1, 14);
    new_book.set_string("Font 7",     font_7,       "Sheet No 1", 1, 15);
    new_book.set_string("Font 8",     font_8,       "Sheet No 1", 1, 16);
    new_book.set_string("Font 9",     font_9,       "Sheet No 1", 1, 17);
    new_book.set_string("Font A",     font_A,       "Sheet No 1", 1, 18);
    new_book.print_xmlss("./test_0302_builder_font.xml");
    return "test_0302_builder_font";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0302_BUILDER_FONT_HPP */
