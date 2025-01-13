#ifndef SIMPLE_XMLSS_MODEL_SHEET_HPP
#define SIMPLE_XMLSS_MODEL_SHEET_HPP

#include "simple_xmlss_model_sheet_cell_map.hpp"
#include "simple_xmlss_model_sheet_tab_color.hpp"
#include "simple_xmlss_model_sheet_cell_size_map.hpp"
#include "simple_xmlss_model_sheet_coordinate.hpp"
#include "simple_xmlss_model_sheet_configuration.hpp"

namespace simple_xmlss {

namespace model {

class sheet {
public:
  sheet(const sheet_configuration& a_sheet_configuration)
    : configuration(a_sheet_configuration),
      tab_color(model::SHEET_TAB_COLOR::DEFAULT) {}

  const sheet_configuration configuration;
  SHEET_TAB_COLOR tab_color;
  sheet_cell_map cell_map;
  sheet_coordinate coordinate;
  sheet_cell_size_map row_height_map;
  sheet_cell_size_map col_width_map;
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_SHEET_HPP */