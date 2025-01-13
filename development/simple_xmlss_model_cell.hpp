#ifndef SIMPLE_XMLSS_MODEL_CELL_HPP
#define SIMPLE_XMLSS_MODEL_CELL_HPP

#include "simple_xmlss_model_cell_string.hpp"
#include "simple_xmlss_model_cell_comment.hpp"
#include "simple_xmlss_model_cell_configuration.hpp"
#include "simple_xmlss_model_cell_status_flag.hpp"

namespace simple_xmlss {

namespace model {

class cell {
public:
  cell(const cell_configuration& a_configuration)
    : configuration(a_configuration), style_id(0), cell_function_return(false) {}

  //cell configuration
  const cell_configuration configuration;
  
  //cell flag
  cell_status_flag status_flag;

  //cell data
  cell_string string;
  std::string number;
  std::string date_time;
  std::string formula;
  cell_comment comment;
  std::string hyperlink;
  unsigned int style_id;

  //cell error
  bool cell_function_return;
  std::string cell_function_error_message;
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_CELL_HPP */