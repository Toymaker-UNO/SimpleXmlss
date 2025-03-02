#ifndef SIMPLE_XMLSS_TEST_0109_SHEET_SET_DATE_TIME_HPP
#define SIMPLE_XMLSS_TEST_0109_SHEET_SET_DATE_TIME_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0109_sheet_set_date_time : public abstract_test_case {
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
    new_sheet1.set_date_time("2024-10-03T20:34:12.123",  1, 1);

    new_sheet1.set_date_time("2024-10-03T20:34:12.123",  2, 2);
    new_sheet1.set_style_id(new_style_id1, 2, 2);

    new_sheet1.set_date_time("2024-10-03T08:08:08.020",  3, 3);
    new_sheet1.set_style_id(new_style_id1, 3, 3);

    new_sheet1.set_date_time("2024-10-03T20:34:12.123",  4, 4);
    new_sheet1.set_style_id(new_style_id2, 4, 4);

    new_sheet1.set_date_time("2024-10-03T08:08:08.020",  5, 5);
    new_sheet1.set_style_id(new_style_id2, 5, 5);

    new_sheet1.set_date_time("2024-10-03T20:34:12.123",  6, 6);
    new_sheet1.set_style_id(new_style_id3, 6, 6);

    new_sheet1.set_date_time("2024-10-03T08:08:08.020",  7, 7);
    new_sheet1.set_style_id(new_style_id3, 7, 7);

    new_sheet1.set_date_time("2024-10-03T20:34:12.123",  8, 8);
    new_sheet1.set_style_id(new_style_id4, 8, 8);

    new_sheet1.set_date_time("2024-10-03T08:08:08.020",  9, 9);
    new_sheet1.set_style_id(new_style_id4, 9, 9);

    new_sheet1.set_date_time("1982-02-09T00:00:00.000",  2, 7);
    new_sheet1.set_style_id(new_style_id5,  2, 7);

    new_sheet1.set_date_time("1982-02-09T00:00:00.000",  3, 8);
    new_sheet1.set_style_id(new_style_id5,  3, 8);

    new_sheet1.set_date_time("1982-02-09T00:00:00.000",  4, 9);
    new_sheet1.set_style_id(new_style_id6,  4, 9);

    new_sheet1.set_date_time("1982-02-09T00:00:00.000",  5, 10);
    new_sheet1.set_style_id(new_style_id7,  5, 10);

    new_book.print_xmlss("./test_0109_sheet_set_date_time.xml");
    return "test_0109_sheet_set_date_time";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0109_SHEET_SET_DATE_TIME_HPP */
