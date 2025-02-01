#ifndef SIMPLE_XMLSS_TEST_0010_BOOK_SET_DATE_TIME_HPP
#define SIMPLE_XMLSS_TEST_0010_BOOK_SET_DATE_TIME_HPP

#include "simple_xmlss.hpp"
#include "abstract_test_case.hpp"

namespace simple_xmlss {

class test_0010_book_set_date_time : public abstract_test_case {
public:
  std::string run(void) {
    simple_xmlss::builder::style::instance().initialize();
    simple_xmlss::builder::font::instance().initialize();

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
    new_book.set_date_time("2024-10-03T20:34:12.123",  "Sheet No 1",  1, 1, 0, 1);

    new_book.set_date_time("2024-10-03T20:34:12.123",  "Sheet No 1",  2, 2, 1, 0);
    new_book.set_style_id(new_style_id1, "Sheet No 1",  2, 2);

    new_book.set_date_time("2024-10-03T08:08:08.020",  "Sheet No 1",  3, 3, 0 , 1);
    new_book.set_style_id(new_style_id1, "Sheet No 1",  3, 3);

    new_book.set_date_time("2024-10-03T20:34:12.123",  "Sheet No 1",  4, 4, 1, 0);
    new_book.set_style_id(new_style_id2, "Sheet No 1",  4, 4);

    new_book.set_date_time("2024-10-03T08:08:08.020",  "Sheet No 1",  5, 5, 0, 1);
    new_book.set_style_id(new_style_id2, "Sheet No 1",  5, 5);

    new_book.set_date_time("2024-10-03T20:34:12.123",  "Sheet No 1",  6, 6, 1, 0);
    new_book.set_style_id(new_style_id3, "Sheet No 1",  6, 6);

    new_book.set_date_time("2024-10-03T08:08:08.020",  "Sheet No 1",  7, 7, 0, 1);
    new_book.set_style_id(new_style_id3, "Sheet No 1",  7, 7);

    new_book.set_date_time("2024-10-03T20:34:12.123",  "Sheet No 1",  8, 8, 1, 0);
    new_book.set_style_id(new_style_id4, "Sheet No 1",  8, 8);

    new_book.set_date_time("2024-10-03T08:08:08.020",  "Sheet No 1",  9, 9, 0, 1);
    new_book.set_style_id(new_style_id4, "Sheet No 1",  9, 9);

    new_book.set_date_time("1982-02-09T00:00:00.000",  "Sheet No 1",  2, 7, 1, 0);
    new_book.set_style_id(new_style_id5,  "Sheet No 1",  2, 7);

    new_book.set_date_time("1982-02-09T00:00:00.000",  "Sheet No 1",  3, 8, 0, 1);
    new_book.set_style_id(new_style_id5,  "Sheet No 1",  3, 8);

    new_book.set_date_time("1982-02-09T00:00:00.000",  "Sheet No 1",  4, 9, 1, 0);
    new_book.set_style_id(new_style_id6,  "Sheet No 1",  4, 9);

    new_book.set_date_time("1982-02-09T00:00:00.000",  "Sheet No 1",  5, 10, 0, 1);
    new_book.set_style_id(new_style_id7,  "Sheet No 1",  5, 10);

    new_book.print_xmlss("./test_0010_book_set_date_time.xml");
    return "test_0010_book_set_date_time";
  }
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_0010_BOOK_SET_DATE_TIME_HPP */
