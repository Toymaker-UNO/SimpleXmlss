#ifndef SIMPLE_XMLSS_TEST_0205_CELL_SET_DATE_TIME_HPP
#define SIMPLE_XMLSS_TEST_0205_CELL_SET_DATE_TIME_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0205_cell_set_date_time : public abstract_test_case {
public:
  std::string run(void) {
    unsigned int new_style_id1 = builder::style::instance().
                                   set_number_format("Short Date").
                                   build();
    unsigned int new_style_id2 = builder::style::instance().
                                   set_number_format("h:mm:ss;@").
                                   build();
    unsigned int new_style_id3 = builder::style::instance().
                                   set_number_format("hh:mm:ss;@").
                                   build();
    unsigned int new_style_id4 = builder::style::instance().
                                   set_number_format("hh:mm:ss.000;@").
                                   build();
    unsigned int new_style_id5 = builder::style::instance().
                                   set_number_format("yyyy/mm/dd;@").
                                   build();
    unsigned int new_style_id6 = builder::style::instance().
                                   set_number_format("yyyy\"년\"\\ mm\"월\"\\ dd\"일\";@").
                                   build();
    unsigned int new_style_id7 = builder::style::instance().
                                   set_number_format("yy\"년\"\\ m\"월\"\\ d\"일\";@").
                                   build();

    simple_xmlss::book new_book("new_book");
    simple_xmlss::sheet& new_sheet1 = new_book.get_sheet("Sheet No 1");
    simple_xmlss::cell& cell1  = new_sheet1.get_cell(1,1);
    simple_xmlss::cell& cell2  = new_sheet1.get_cell(2,2);
    simple_xmlss::cell& cell3  = new_sheet1.get_cell(3,3);
    simple_xmlss::cell& cell4  = new_sheet1.get_cell(4,4);
    simple_xmlss::cell& cell5  = new_sheet1.get_cell(5,5);
    simple_xmlss::cell& cell6  = new_sheet1.get_cell(6,6);
    simple_xmlss::cell& cell7  = new_sheet1.get_cell(7,7);
    simple_xmlss::cell& cell8  = new_sheet1.get_cell(8,8);
    simple_xmlss::cell& cell9  = new_sheet1.get_cell(9,9);
    simple_xmlss::cell& cell11 = new_sheet1.get_cell(2,7);
    simple_xmlss::cell& cell12 = new_sheet1.get_cell(3,8);
    simple_xmlss::cell& cell13 = new_sheet1.get_cell(4,9);
    simple_xmlss::cell& cell14 = new_sheet1.get_cell(5,10);

    cell1.set_date_time("2024-10-03T20:34:12.123");

    cell2.set_date_time("2024-10-03T20:34:12.123").
          set_style_id(new_style_id1);

    cell3.set_date_time("2024-10-03T08:08:08.020").
          set_style_id(new_style_id1);

    cell4.set_date_time("2024-10-03T20:34:12.123").
          set_style_id(new_style_id2);

    cell5.set_date_time("2024-10-03T08:08:08.020").
          set_style_id(new_style_id2);

    cell6.set_date_time("2024-10-03T20:34:12.123").
          set_style_id(new_style_id3);

    cell7.set_date_time("2024-10-03T08:08:08.020").
          set_style_id(new_style_id3);

    cell8.set_date_time("2024-10-03T20:34:12.123").
          set_style_id(new_style_id4);

    cell9.set_date_time("2024-10-03T08:08:08.020").
          set_style_id(new_style_id4);

    cell11.set_date_time("1982-02-09T00:00:00.000").
           set_style_id(new_style_id5);

    cell12.set_date_time("1982-02-09T00:00:00.000").
           set_style_id(new_style_id5);

    cell13.set_date_time("1982-02-09T00:00:00.000").
           set_style_id(new_style_id6);

    cell14.set_date_time("1982-02-09T00:00:00.000").
           set_style_id(new_style_id7);

    new_book.print_xmlss("./test_0205_cell_set_date_time.xml");
    return "test_0205_cell_set_date_time";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0205_CELL_SET_DATE_TIME_HPP */
