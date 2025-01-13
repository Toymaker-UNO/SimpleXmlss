#ifndef SIMPLE_XMLSS_API_CELL_MACRO_FUNCTIONS_HPP
#define SIMPLE_XMLSS_API_CELL_MACRO_FUNCTIONS_HPP

namespace simple_xmlss {

namespace api {

#define CHECK_MERGE_FLAG(a_cell, a_arg_string, a_trace) {                                                                 \
  if(true == a_cell.configuration.merge_flag) {                                                                           \
      std::string arg_string = a_arg_string;                                                                              \
      std::string msg = "[ERROR] This is MERGED Cell. Discard: " + arg_string;                                            \
      handling_error(a_cell,msg,a_trace);                                                                                 \
      return;                                                                                                             \
    }                                                                                                                     \
}

#define CHECK_STRING_FLAG(a_cell, a_arg_string, a_trace) {                                                                \
  if(true == a_cell.status_flag.string_flag) {                                                                            \
      std::string arg_string = a_arg_string;                                                                              \
      std::string msg = "[ERROR] This cell already has a STRING defined. Discard: " + arg_string;                         \
      handling_error(a_cell,msg,a_trace);                                                                                 \
      return;                                                                                                             \
    }                                                                                                                     \
}

#define CHECK_NUMBER_FLAG(a_cell, a_arg_string, a_trace) {                                                                \
  if(true == a_cell.status_flag.number_flag) {                                                                            \
      std::string arg_string = a_arg_string;                                                                              \
      std::string msg = "[ERROR] This cell already has a NUMBER defined. Discard: " + arg_string;                         \
      handling_error(a_cell,msg,a_trace);                                                                                 \
      return;                                                                                                             \
    }                                                                                                                     \
}

#define CHECK_DATE_TIME_FLAG(a_cell, a_arg_string, a_trace) {                                                             \
  if(true == a_cell.status_flag.date_time_flag) {                                                                         \
      std::string arg_string = a_arg_string;                                                                              \
      std::string msg = "[ERROR] This cell already has a DATE_TIME defined. Discard: " + arg_string;                      \
      handling_error(a_cell,msg,a_trace);                                                                                 \
      return;                                                                                                             \
    }                                                                                                                     \
}

#define CHECK_FORMULA_FLAG(a_cell, a_arg_string, a_trace) {                                                               \
  if(true == a_cell.status_flag.formula_flag) {                                                                           \
      std::string arg_string = a_arg_string;                                                                              \
      std::string msg = "[ERROR] This cell already has a FORMULA defined. Discard: " + arg_string;                        \
      handling_error(a_cell,msg,a_trace);                                                                                 \
      return;                                                                                                             \
    }                                                                                                                     \
}

#define CHECK_COMMENT_FLAG(a_cell, a_arg_string, a_trace) {                                                               \
  if(true == a_cell.status_flag.comment_flag) {                                                                           \
      std::string arg_string = a_arg_string;                                                                              \
      std::string msg = "[ERROR] This cell already has a COMMENT defined. Discard: " + arg_string;                        \
      handling_error(a_cell,msg,a_trace);                                                                                 \
      return;                                                                                                             \
    }                                                                                                                     \
}

#define CHECK_CONTENTS_EXIST(a_cell, a_arg_string, a_trace) {                                                             \
  if(false == a_cell.status_flag.string_flag &&                                                                           \
     false == a_cell.status_flag.number_flag &&                                                                           \
     false == a_cell.status_flag.date_time_flag &&                                                                        \
     false == a_cell.status_flag.formula_flag) {                                                                          \
      std::string arg_string = a_arg_string;                                                                              \
      std::string msg = "[ERROR] STRING, NUMBER, DATE_TIME and FORMULA are not defined together. Discard:" + arg_string;  \
      handling_error(a_cell,msg,a_trace);                                                                                 \
      return;                                                                                                             \
    }                                                                                                                     \
}

} // namespace api

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_API_CELL_MACRO_FUNCTIONS_HPP */