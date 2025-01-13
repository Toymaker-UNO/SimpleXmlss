#ifndef SIMPLE_XMLSS_TEST_0303_BUILDER_STRING_HPP
#define SIMPLE_XMLSS_TEST_0303_BUILDER_STRING_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0303_builder_string : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

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

    auto string_data = builder::string::instance().
                          clear().
                          set_string("굴림체", font_gullim).
                          set_string(" ").
                          set_string("궁서체", font_gungso).
                          set_string(" ").
                          set_string("궁서체", font_gungso2).
                          set_string(" ").
                          set_string("Font Red", font_red).
                          set_string(" ").
                          set_string("Font Green", font_green).
                          set_string(" ").
                          set_string("Font BLUE1", font_blue1).
                          set_string(" ").
                          set_string("Font BLUE2", font_blue2).
                          set_string(" ").
                          set_string("Font BLUE3", font_blue3).
                          set_string(" ").
                          set_string("Font GB1", font_gb1).
                          set_string(" ").
                          set_string("Font GB2", font_gb2).
                          set_string(" ").
                          set_string("Font GB3", font_gb3).
                          set_string(" ").
                          set_string("Font 7", font_7).
                          set_string(" ").
                          set_string("Font 8", font_8).
                          set_string(" ").
                          set_string("Font 9", font_9).
                          set_string(" ").
                          set_string("Font A", font_A).
                          build();

    simple_xmlss::book new_book("new_book");
    new_book.set_string(string_data, "Sheet No 1", 1, 1);
    new_book.print_xmlss("./test_0303_builder_string.xml");
    return "test_0303_builder_string";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0303_BUILDER_STRING_HPP */
