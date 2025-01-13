#ifndef SIMPLE_XMLSS_MODEL_CELL_STATUS_FLAG_HPP
#define SIMPLE_XMLSS_MODEL_CELL_STATUS_FLAG_HPP

namespace simple_xmlss {

namespace model {

class cell_status_flag {
public:
  bool string_flag;
  bool number_flag;
  bool date_time_flag;
  bool formula_flag;
  bool comment_flag;
  bool hyperlink_flag;
  bool style_flag;

  cell_status_flag(void)
    : string_flag(false),
      number_flag(false),
      date_time_flag(false),
      formula_flag(false),
      comment_flag(false),
      hyperlink_flag(false),
      style_flag(false) {}
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_CELL_STATUS_FLAG_HPP */