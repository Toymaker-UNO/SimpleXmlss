#ifndef SIMPLE_XMLSS_MODEL_SHEET_CELL_MAP_HPP
#define SIMPLE_XMLSS_MODEL_SHEET_CELL_MAP_HPP

#include "simple_xmlss_cell.hpp"
#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

typedef std::map<unsigned int, simple_xmlss::cell> column_to_cell_map;
typedef std::map<unsigned int, column_to_cell_map> row_to_column_map;
typedef row_to_column_map sheet_cell_map;

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_SHEET_CELL_MAP_HPP */