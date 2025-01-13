#ifndef SIMPLE_XMLSS_MODEL_CELL_COORDINATE_HPP
#define SIMPLE_XMLSS_MODEL_CELL_COORDINATE_HPP

namespace simple_xmlss {

namespace model {

class cell_coordinate {
public:
  unsigned int col;
  unsigned int row;

  cell_coordinate(void) 
    : col(0),
      row(0) {}
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_CELL_COORDINATE_HPP */