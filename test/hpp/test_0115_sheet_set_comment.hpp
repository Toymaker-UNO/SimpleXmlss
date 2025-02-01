#ifndef SIMPLE_XMLSS_TEST_0115_SHEET_SET_COMMENT_HPP
#define SIMPLE_XMLSS_TEST_0115_SHEET_SET_COMMENT_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0115_sheet_set_comment : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();
    
    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    unsigned int font_id1 = builder::font::instance().
                            clear().
                            set_color("#FF0000").
                            set_size(9).
                            set_underline(model::FONT_UNDERLINE::SINGLE).
                            set_italic(true).
                            set_bold(true).
                            build();

    unsigned int font_id2 = builder::font::instance().
                            clear().
                            set_color("#0000FF").
                            set_size(11).
                            build();
    new_sheet1.set_string("A1 Data",       font_id1,  1, 1);
    new_sheet1.set_string("B2 Data",       font_id2,  2, 2);
    new_sheet1.set_string("C3 Data",       font_id1,  3, 3);
    new_sheet1.set_string("D4 Data: &",    font_id1,  4, 4);
    new_sheet1.set_string("E5 Data: <",    font_id2,  5, 5);
    new_sheet1.set_string("F6 Data: >",    font_id1,  6, 6);
    new_sheet1.set_string("G7 Data: \"",   font_id2,  7, 7);
    new_sheet1.set_string("H8 Data: '",    font_id1,  8, 8);                            

    simple_xmlss::model::cell_comment new_cell_comment1 = simple_xmlss::builder::comment::instance().
                                                      clear().
                                                      set_comment("A1", font_id1).
                                                      set_comment(" ").
                                                      set_comment("Data", font_id2).
                                                      build();
    new_sheet1.set_comment(new_cell_comment1,  1, 1);

    simple_xmlss::model::cell_comment new_cell_comment2 = simple_xmlss::builder::comment::instance().
                                                      clear().
                                                      set_comment("B2", font_id1).
                                                      set_comment(" ").
                                                      set_comment("Data", font_id2).
                                                      build();
    new_sheet1.set_comment(new_cell_comment2,  2, 2);

    simple_xmlss::model::cell_comment new_cell_comment3 = simple_xmlss::builder::comment::instance().
                                                      clear().
                                                      set_comment("C3", font_id1).
                                                      set_comment(" ").
                                                      set_comment("Data", font_id2).
                                                      build();
    new_sheet1.set_comment(new_cell_comment3,  3, 3);

    simple_xmlss::model::cell_comment new_cell_comment4 = simple_xmlss::builder::comment::instance().
                                                      clear().
                                                      set_comment("D4", font_id1).
                                                      set_comment(" ").
                                                      set_comment("Data:", font_id2).
                                                      set_comment(" ").
                                                      set_comment("&", font_id1).
                                                      build();
    new_sheet1.set_comment(new_cell_comment4,  4, 4);

    simple_xmlss::model::cell_comment new_cell_comment5 = simple_xmlss::builder::comment::instance().
                                                      clear().
                                                      set_comment("E5", font_id1).
                                                      set_comment(" ").
                                                      set_comment("Data:", font_id2).
                                                      set_comment(" ").
                                                      set_comment("<", font_id1).
                                                      build();
    new_sheet1.set_comment(new_cell_comment5,  5, 5);

    simple_xmlss::model::cell_comment new_cell_comment6 = simple_xmlss::builder::comment::instance().
                                                      clear().
                                                      set_comment("F6", font_id1).
                                                      set_comment(" ").
                                                      set_comment("Data:", font_id2).
                                                      set_comment(" ").
                                                      set_comment(">", font_id1).
                                                      build();    
    new_sheet1.set_comment(new_cell_comment6,  6, 6);

    simple_xmlss::model::cell_comment new_cell_comment7 = simple_xmlss::builder::comment::instance().
                                                      clear().
                                                      set_comment("G7", font_id1).
                                                      set_comment(" ").
                                                      set_comment("Data:", font_id2).
                                                      set_comment(" ").
                                                      set_comment("\"", font_id1).
                                                      build(); 
    new_sheet1.set_comment(new_cell_comment7,  7, 7);

    simple_xmlss::model::cell_comment new_cell_comment8 = simple_xmlss::builder::comment::instance().
                                                      clear().
                                                      set_comment("H8", font_id1).
                                                      set_comment(" ").
                                                      set_comment("Data:", font_id2).
                                                      set_comment(" ").
                                                      set_comment("'", font_id1).
                                                      build(); 
    new_sheet1.set_comment(new_cell_comment8,  8, 8);

    new_book.print_xmlss("./test_0115_sheet_set_comment.xml");
    return "test_0115_sheet_set_comment";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0115_SHEET_SET_COMMENT_HPP */
