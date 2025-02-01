#ifndef SIMPLE_XMLSS_MODEL_SHEET_COORDINATE_HPP
#define SIMPLE_XMLSS_MODEL_SHEET_COORDINATE_HPP

namespace simple_xmlss {

namespace model {

class sheet_coordinate {
public:
  unsigned int max_col;
  unsigned int max_row;
  unsigned int current_col;
  unsigned int current_row;

  sheet_coordinate(void)
    : max_col(1),
      max_row(1),
      current_col(1),
      current_row(1) {}
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_SHEET_COORDINATE_HPP */