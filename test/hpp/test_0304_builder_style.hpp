#ifndef SIMPLE_XMLSS_TEST_0304_BUILDER_STYLE_HPP
#define SIMPLE_XMLSS_TEST_0304_BUILDER_STYLE_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0304_builder_style : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::book new_book("new_book");
    unsigned int style_01 = builder::style::instance().
                             clear().
                             set_number_format("_-\"₩\"* #,##0.000_-;\\-\"₩\"* #,##0.000_-;_-\"₩\"* \"-\"???_-;_-@_-").
                             build();
    new_book.set_number("3.14", "Sheet No 1", 1, 1).set_style_id(style_01);

    unsigned int style_02 = builder::style::instance().
                             clear().
                             set_number_format("Percent").
                             build();
    new_book.set_number("1234", "Sheet No 1", 1, 2).set_style_id(style_02);

    unsigned int style_03 = builder::style::instance().
                             clear().
                             set_number_format("[<=999999]####\\-####;\\(0##\\)\\ ####\\-####").
                             build();
    new_book.set_number("123456", "Sheet No 1", 1, 3).set_style_id(style_03);

    unsigned int style_04 = builder::style::instance().
                             clear().
                             set_number_comma(true).
                             build();
    new_book.set_number("1234567890", "Sheet No 1", 1, 4).set_style_id(style_04);

    new_book.get_sheet("Sheet No 1").
             set_row_height(5,40).
             set_row_height(6,40).
             set_row_height(7,80).
             set_row_height(8,40).
             set_row_height(9,40).
             set_row_height(10,40).
             set_row_height(11,40).
             set_row_height(12,40).
             set_row_height(13,40).
             set_row_height(14,40).
             set_col_width(2,300).
             set_col_width(3,300).
             set_col_width(4,300).
             set_col_width(5,300).
             set_col_width(6,300).
             set_col_width(7,300).
             set_col_width(8,300).
             set_col_width(9,300).
             set_col_width(10,300).
             set_col_width(11,300).
             set_col_width(12,300).
             set_col_width(13,300).
             set_col_width(14,300);

    unsigned int style_05 = builder::style::instance().
                             clear().
                             set_alignment_horizontal(model::STYLE_ALIGNMENT_HORIZONTAL::CENTER).
                             build();
    new_book.set_string("alignment_horizontal_center", "Sheet No 1", 2, 5).set_style_id(style_05);

    unsigned int style_06 = builder::style::instance().
                             clear().
                             set_alignment_horizontal(model::STYLE_ALIGNMENT_HORIZONTAL::LEFT).
                             build();
    new_book.set_string("alignment_horizontal_left", "Sheet No 1", 3, 5).set_style_id(style_06);

    unsigned int style_07 = builder::style::instance().
                             clear().
                             set_alignment_horizontal(model::STYLE_ALIGNMENT_HORIZONTAL::RIGHT).
                             build();
    new_book.set_string("alignment_horizontal_right", "Sheet No 1", 4, 5).set_style_id(style_07);

    unsigned int style_08 = builder::style::instance().
                             clear().
                             set_alignment_horizontal(model::STYLE_ALIGNMENT_HORIZONTAL::CENTER_ACROSS_SELECTION).
                             build();
    new_book.set_string("alignment_horizontal_center_across_selection", "Sheet No 1", 5, 5).set_style_id(style_08);


    unsigned int style_09 = builder::style::instance().
                             clear().
                             set_alignment_horizontal(model::STYLE_ALIGNMENT_HORIZONTAL::DISTRIBUTED).
                             build();
    new_book.set_string("alignment_horizontal_distributed", "Sheet No 1", 6, 5).set_style_id(style_09);

    unsigned int style_10 = builder::style::instance().
                             clear().
                             set_alignment_horizontal(model::STYLE_ALIGNMENT_HORIZONTAL::FILL).
                             build();
    new_book.set_string("alignment_horizontal_fill", "Sheet No 1", 7, 5).set_style_id(style_10);

    unsigned int style_11 = builder::style::instance().
                             clear().
                             set_alignment_horizontal(model::STYLE_ALIGNMENT_HORIZONTAL::JUSTIFY).
                             build();
    new_book.set_string("alignment_horizontal_justify", "Sheet No 1", 8, 5).set_style_id(style_11);

    unsigned int style_12 = builder::style::instance().
                             clear().
                             set_alignment_horizontal(model::STYLE_ALIGNMENT_HORIZONTAL::CENTER).
                             set_alignment_horizontal_indent(1).
                             build();
    new_book.set_string("alignment_horizontal_center", "Sheet No 1", 2, 6).set_style_id(style_12);

    unsigned int style_13 = builder::style::instance().
                             clear().
                             set_alignment_horizontal(model::STYLE_ALIGNMENT_HORIZONTAL::LEFT).
                             set_alignment_horizontal_indent(1).
                             build();
    new_book.set_string("alignment_horizontal_left", "Sheet No 1", 3, 6).set_style_id(style_13);

    unsigned int style_14 = builder::style::instance().
                             clear().
                             set_alignment_horizontal(model::STYLE_ALIGNMENT_HORIZONTAL::RIGHT).
                             set_alignment_horizontal_indent(1).
                             build();
    new_book.set_string("alignment_horizontal_right", "Sheet No 1", 4, 6).set_style_id(style_14);

    unsigned int style_15 = builder::style::instance().
                             clear().
                             set_alignment_vertical(model::STYLE_ALIGNMENT_VERTICAL::CENTER).
                             build();
    new_book.set_string("alignment_vertical_center", "Sheet No 1", 2, 7).set_style_id(style_15);

    unsigned int style_16 = builder::style::instance().
                             clear().
                             set_alignment_vertical(model::STYLE_ALIGNMENT_VERTICAL::BOTTOM).
                             build();
    new_book.set_string("alignment_vertical_bottom", "Sheet No 1", 3, 7).set_style_id(style_16);

    unsigned int style_17 = builder::style::instance().
                             clear().
                             set_alignment_vertical(model::STYLE_ALIGNMENT_VERTICAL::DISTRIBUTED).
                             build();
    new_book.set_string("alignment_vertical_distributed", "Sheet No 1", 4, 7).set_style_id(style_17); 

    unsigned int style_18 = builder::style::instance().
                             clear().
                             set_alignment_vertical(model::STYLE_ALIGNMENT_VERTICAL::JUSTIFY).
                             build();
    new_book.set_string("alignment_vertical_justify", "Sheet No 1", 5, 7).set_style_id(style_18);

    unsigned int style_19 = builder::style::instance().
                             clear().
                             set_alignment_vertical(model::STYLE_ALIGNMENT_VERTICAL::TOP).
                             build();
    new_book.set_string("alignment_vertical_top", "Sheet No 1", 6, 7).set_style_id(style_19);

    unsigned int style_20 = builder::style::instance().
                             clear().
                             set_alignment_vertical(model::STYLE_ALIGNMENT_VERTICAL::NONE).
                             build();
    new_book.set_string("alignment_vertical_none", "Sheet No 1", 7, 7).set_style_id(style_20);

    unsigned int style_21 = builder::style::instance().
                             clear().
                             set_alignment_text_control(model::STYLE_ALIGNMENT_TEXT_CONTROL::SHRINK_TO_FIT).
                             build();
    new_book.set_string("alignment_text_control_shrink_to_fit_ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890", "Sheet No 1", 2, 8).set_style_id(style_21);

    unsigned int style_22 = builder::style::instance().
                             clear().
                             set_alignment_text_control(model::STYLE_ALIGNMENT_TEXT_CONTROL::WRAP_TEXT).
                             build();
    new_book.set_string("alignment_text_control_wrap_text_ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890", "Sheet No 1", 3, 8).set_style_id(style_22);

    unsigned int style_23 = builder::style::instance().
                             clear().
                             set_alignment_rotate(20).
                             build();
    new_book.set_string("alignment_rotate_20", "Sheet No 1", 2, 9).set_style_id(style_23);

    unsigned int style_24 = builder::style::instance().
                             clear().
                             set_alignment_rotate(45).
                             build();
    new_book.set_string("alignment_rotate_45", "Sheet No 1", 3, 9).set_style_id(style_24);

    unsigned int style_25 = builder::style::instance().
                             clear().
                             set_alignment_rotate(75).
                             build();
    new_book.set_string("alignment_rotate_75", "Sheet No 1", 4, 9).set_style_id(style_25);

    unsigned int style_26 = builder::style::instance().
                             clear().
                             set_alignment_rotate(90).
                             build();
    new_book.set_string("alignment_rotate_90", "Sheet No 1", 5, 9).set_style_id(style_26);

    unsigned int style_27 = builder::style::instance().
                             clear().
                             set_alignment_rotate(-45).
                             build();
    new_book.set_string("alignment_rotate_-45", "Sheet No 1", 6, 9).set_style_id(style_27);

    unsigned int style_28 = builder::style::instance().
                             clear().
                             set_alignment_rotate(-90).
                             build();
    new_book.set_string("alignment_rotate_-90", "Sheet No 1", 7, 9).set_style_id(style_28);

    unsigned int font_A   =   builder::font::instance().
                              clear().
                              set_size(14).
                              set_color("#AAAAAA").
                              set_italic(true).
                              set_bold(true).
                              set_strikethrough(true).
                              build();

    unsigned int style_29 = builder::style::instance().
                             clear().
                             set_font_id(font_A).
                             build();
    new_book.set_string("set_font_id", "Sheet No 1", 2, 10).set_style_id(style_29);

    unsigned int style_30 = builder::style::instance().
                             clear().
                             set_default_borders().
                             build();
    new_book.set_string("set_default_boarders", "Sheet No 1", 2, 11).set_style_id(style_30);

    unsigned int style_31 = builder::style::instance().
                             clear().
                             set_border_color(model::STYLE_BORDER_POSITION::BOTTOM, "#FF0000").
                             set_border_line_type(model::STYLE_BORDER_POSITION::BOTTOM, model::STYLE_BORDER_LINE_TYPE::CONTINUOUS).
                             set_border_weight(model::STYLE_BORDER_POSITION::BOTTOM, model::STYLE_BORDER_WEIGHT::THIN).
                             build();
    new_book.set_string("set_border_bottom_continuous_thin", "Sheet No 1", 2, 12).set_style_id(style_31);

    unsigned int style_32 = builder::style::instance().
                             clear().
                             set_border_color(model::STYLE_BORDER_POSITION::LEFT, "#FF0000").
                             set_border_line_type(model::STYLE_BORDER_POSITION::LEFT, model::STYLE_BORDER_LINE_TYPE::DASH).
                             set_border_weight(model::STYLE_BORDER_POSITION::LEFT, model::STYLE_BORDER_WEIGHT::HAIRLINE).
                             build();
    new_book.set_string("set_border_left_dash_hairline", "Sheet No 1", 3, 12).set_style_id(style_32);

    unsigned int style_33 = builder::style::instance().
                             clear().
                             set_border_color(model::STYLE_BORDER_POSITION::TOP, "#FF0000").
                             set_border_line_type(model::STYLE_BORDER_POSITION::TOP, model::STYLE_BORDER_LINE_TYPE::DASHDOT).
                             set_border_weight(model::STYLE_BORDER_POSITION::TOP, model::STYLE_BORDER_WEIGHT::THICK).
                             build();
    new_book.set_string("set_border_top_dashdot_thick", "Sheet No 1", 4, 12).set_style_id(style_33);

    unsigned int style_34 = builder::style::instance().
                             clear().
                             set_border_color(model::STYLE_BORDER_POSITION::RIGHT, "#FF0000").
                             set_border_line_type(model::STYLE_BORDER_POSITION::RIGHT, model::STYLE_BORDER_LINE_TYPE::DASHDOTDOT).
                             set_border_weight(model::STYLE_BORDER_POSITION::RIGHT, model::STYLE_BORDER_WEIGHT::MEDIUM).
                             build();
    new_book.set_string("set_border_right_dashdotdot_medium", "Sheet No 1", 5, 12).set_style_id(style_34);

    unsigned int style_35 = builder::style::instance().
                             clear().
                             set_border_color(model::STYLE_BORDER_POSITION::TOP, "#FF0000").
                             set_border_line_type(model::STYLE_BORDER_POSITION::TOP, model::STYLE_BORDER_LINE_TYPE::DOT).
                             set_border_weight(model::STYLE_BORDER_POSITION::TOP, model::STYLE_BORDER_WEIGHT::HAIRLINE).
                             build();
    new_book.set_string("set_border_top_dot_hairline", "Sheet No 1", 6, 12).set_style_id(style_35);

    unsigned int style_36 = builder::style::instance().
                             clear().
                             set_border_color(model::STYLE_BORDER_POSITION::RIGHT, "#FF0000").
                             set_border_line_type(model::STYLE_BORDER_POSITION::RIGHT, model::STYLE_BORDER_LINE_TYPE::DOUBLE).
                             set_border_weight(model::STYLE_BORDER_POSITION::RIGHT, model::STYLE_BORDER_WEIGHT::MEDIUM).
                             build();
    new_book.set_string("set_border_right_double_medium", "Sheet No 1", 7, 12).set_style_id(style_36);

    unsigned int style_37 = builder::style::instance().
                             clear().
                             set_border_color(model::STYLE_BORDER_POSITION::BOTTOM, "#FF0000").
                             set_border_line_type(model::STYLE_BORDER_POSITION::BOTTOM, model::STYLE_BORDER_LINE_TYPE::SLANTDASHDOT).
                             set_border_weight(model::STYLE_BORDER_POSITION::BOTTOM, model::STYLE_BORDER_WEIGHT::THICK).
                             build();
    new_book.set_string("set_border_bottom_slantdashdot_thick", "Sheet No 1", 8, 12).set_style_id(style_37);

    unsigned int style_38 = builder::style::instance().
                             clear().
                             set_fill_background_color("#FF7777").
                             set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID).
                             build();
    new_book.set_string("set_fill_pattern_style_solid", "Sheet No 1", 2, 13).set_style_id(style_38);

    unsigned int style_39 = builder::style::instance().
                             clear().
                             set_fill_background_color("#FF7777").
                             set_fill_pattern_color("#00FFFF").
                             set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID).
                             build();
    new_book.set_string("set_fill_pattern_style_solid2", "Sheet No 1", 3, 13).set_style_id(style_39);

    unsigned int style_40 = builder::style::instance().
                             clear().
                             set_fill_background_color("#00FF00").
                             set_fill_pattern_color("#0000FF").
                             set_fill_pattern_style(model::STYLE_FILL_PATTERN::DIAG_CROSS).
                             build();
    new_book.set_string("set_fill_pattern_style_diag_cross", "Sheet No 1", 4, 13).set_style_id(style_40);

    unsigned int style_41 = builder::style::instance().
                             clear().
                             set_fill_background_color("#00FF00").
                             set_fill_pattern_color("#0000FF").
                             set_fill_pattern_style(model::STYLE_FILL_PATTERN::DIAG_STRIPE).
                             build();
    new_book.set_string("set_fill_pattern_style_diag_stripe", "Sheet No 1", 5, 13).set_style_id(style_41);

    unsigned int style_42 = builder::style::instance().
                             clear().
                             set_fill_background_color("#00FF00").
                             set_fill_pattern_color("#0000FF").
                             set_fill_pattern_style(model::STYLE_FILL_PATTERN::GRAY_0625).
                             build();
    new_book.set_string("set_fill_pattern_style_gray_0625", "Sheet No 1", 6, 13).set_style_id(style_42);

    unsigned int style_43 = builder::style::instance().
                             clear().
                             set_fill_background_color("#00FF00").
                             set_fill_pattern_color("#0000FF").
                             set_fill_pattern_style(model::STYLE_FILL_PATTERN::GRAY_125).
                             build();
    new_book.set_string("set_fill_pattern_style_gray_125", "Sheet No 1", 7, 13).set_style_id(style_43);

    
    unsigned int style_44 = builder::style::instance().
                             clear().
                             set_fill_background_color("#00FF00").
                             set_fill_pattern_color("#0000FF").
                             set_fill_pattern_style(model::STYLE_FILL_PATTERN::GRAY_25).
                             build();
    new_book.set_string("set_fill_pattern_style_gray_25", "Sheet No 1", 8, 13).set_style_id(style_44);

    unsigned int style_45 = builder::style::instance().
                             clear().
                             set_fill_background_color("#00FF00").
                             set_fill_pattern_color("#0000FF").
                             set_fill_pattern_style(model::STYLE_FILL_PATTERN::GRAY_50).
                             build();
    new_book.set_string("set_fill_pattern_style_gray_50", "Sheet No 1", 9, 13).set_style_id(style_45);

    unsigned int style_46 = builder::style::instance().
                             clear().
                             set_fill_background_color("#00FF00").
                             set_fill_pattern_color("#0000FF").
                             set_fill_pattern_style(model::STYLE_FILL_PATTERN::GRAY_75).
                             build();
    new_book.set_string("set_fill_pattern_style_gray_75", "Sheet No 1", 10, 13).set_style_id(style_46);

    unsigned int style_47 = builder::style::instance().
                             clear().
                             set_fill_background_color("#00FF00").
                             set_fill_pattern_color("#0000FF").
                             set_fill_pattern_style(model::STYLE_FILL_PATTERN::HORZ_STRIPE).
                             build();
    new_book.set_string("set_fill_pattern_style_horz_stripe", "Sheet No 1", 11, 13).set_style_id(style_47);

    unsigned int style_48 = builder::style::instance().
                             clear().
                             set_fill_background_color("#00FF00").
                             set_fill_pattern_color("#0000FF").
                             set_fill_pattern_style(model::STYLE_FILL_PATTERN::REVERSE_DIAG_STRIPE).
                             build();
    new_book.set_string("set_fill_pattern_style_reverse_diag_stripe", "Sheet No 1", 12, 13).set_style_id(style_48);

    unsigned int style_49 = builder::style::instance().
                             clear().
                             set_fill_background_color("#00FF00").
                             set_fill_pattern_color("#0000FF").
                             set_fill_pattern_style(model::STYLE_FILL_PATTERN::THICK_DIAG_CROSS).
                             build();
    new_book.set_string("set_fill_pattern_style_thick_diag_cross", "Sheet No 1", 13, 13).set_style_id(style_49);

    new_book.print_xmlss("./test_0304_builder_style.xml");
    return "test_0304_builder_style";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0304_BUILDER_STYLE_HPP */
