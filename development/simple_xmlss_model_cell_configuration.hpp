#ifndef SIMPLE_XMLSS_MODEL_CELL_CONFIGURATION_HPP
#define SIMPLE_XMLSS_MODEL_CELL_CONFIGURATION_HPP

#include "simple_xmlss_model_cell_coordinate.h"

namespace simple_xmlss {

namespace model {

class cell_configuration {
public:
  //book, sheet information
  std::string book_name;
  std::string sheet_name;

  //current coordinate
  cell_coordinate coordinate;

  //merge configuration
  unsigned int merge_across;
  unsigned int merge_down;
  bool merge_flag;
  cell_coordinate merge_origin;

  cell_configuration(void)
    : book_name("Default"),
      sheet_name("Default"),
      coordinate(cell_coordinate()),
      merge_across(0),
      merge_down(0),
      merge_flag(false),
      merge_origin(cell_coordinate()) {}
      
  void debug_print(void) const {
    printf("<<cell_configuration>>\n");
    printf("book_name: %s", book_name.c_str());
    printf("sheet_name: %s", sheet_name.c_str());
    printf("coordinate: [row:%u,col:%u]\n", coordinate.col, coordinate.row);
    printf("merge_across: %u\n", merge_across);
    printf("merge_down: %u\n", merge_down);
    printf("merge_flag: %s\n", (true == merge_flag)?"true":"false");
    printf("merge_origin: [row:%u,col:%u]\n\n", merge_origin.col, merge_origin.row);
  }
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_CELL_CONFIGURATION_HPP */