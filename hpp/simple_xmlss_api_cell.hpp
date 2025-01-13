#ifndef SIMPLE_XMLSS_API_CELL_HPP
#define SIMPLE_XMLSS_API_CELL_HPP

#include "simple_xmlss_model_cell.hpp"
#include "simple_xmlss_utility_trace.hpp"
#include "simple_xmlss_utility_inline_functions.hpp"
#include "simple_xmlss_utility_error.hpp"
#include "simple_xmlss_utility_error_handler.hpp"
#include "simple_xmlss_api_cell_macro_functions.hpp"

namespace simple_xmlss {

namespace api {

class cell {
public:
  void simple_xmlss_set_string(model::cell& a_cell,
                           const std::string& a_string,
                           const utility::trace& a_trace) {
    CHECK_MERGE_FLAG    (a_cell, ("string("+a_string+")"), a_trace);
    CHECK_STRING_FLAG   (a_cell, ("string("+a_string+")"), a_trace);
    CHECK_NUMBER_FLAG   (a_cell, ("string("+a_string+")"), a_trace);
    CHECK_DATE_TIME_FLAG(a_cell, ("string("+a_string+")"), a_trace);
    CHECK_FORMULA_FLAG  (a_cell, ("string("+a_string+")"), a_trace);

    model::cell_font_string new_font_string;
    new_font_string.contents = a_string;
    new_font_string.font_id = 0;
    a_cell.string.push_back(new_font_string);
    a_cell.status_flag.string_flag = true;
  }

  void simple_xmlss_set_string(model::cell& a_cell,
                           const std::string& a_string,
                           const unsigned int a_font_id,
                           const utility::trace& a_trace) {
    CHECK_MERGE_FLAG    (a_cell, ("string("+a_string+"),font_id("+std::to_string(a_font_id)+")"), a_trace);
    CHECK_STRING_FLAG   (a_cell, ("string("+a_string+"),font_id("+std::to_string(a_font_id)+")"), a_trace);
    CHECK_NUMBER_FLAG   (a_cell, ("string("+a_string+"),font_id("+std::to_string(a_font_id)+")"), a_trace);
    CHECK_DATE_TIME_FLAG(a_cell, ("string("+a_string+"),font_id("+std::to_string(a_font_id)+")"), a_trace);
    CHECK_FORMULA_FLAG  (a_cell, ("string("+a_string+"),font_id("+std::to_string(a_font_id)+")"), a_trace);

    model::cell_font_string new_font_string;
    new_font_string.contents = a_string;
    new_font_string.font_id = a_font_id;
    a_cell.string.push_back(new_font_string);
    a_cell.status_flag.string_flag = true;
  }

  void simple_xmlss_set_string(model::cell& a_cell,
                           const model::cell_string& a_string,
                           const utility::trace& a_trace) {
    CHECK_MERGE_FLAG    (a_cell, ("cell_string("+ get_cell_string(a_string) + ")"), a_trace);
    CHECK_STRING_FLAG   (a_cell, ("cell_string("+ get_cell_string(a_string) + ")"), a_trace);
    CHECK_NUMBER_FLAG   (a_cell, ("cell_string("+ get_cell_string(a_string) + ")"), a_trace);
    CHECK_DATE_TIME_FLAG(a_cell, ("cell_string("+ get_cell_string(a_string) + ")"), a_trace);
    CHECK_FORMULA_FLAG  (a_cell, ("cell_string("+ get_cell_string(a_string) + ")"), a_trace);

    a_cell.string = a_string;
    a_cell.status_flag.string_flag = true;
  }

  void simple_xmlss_set_number(model::cell& a_cell,
                           const std::string& a_number,
                           const utility::trace& a_trace) {
    CHECK_MERGE_FLAG    (a_cell, ("number("+a_number+")"), a_trace);
    CHECK_STRING_FLAG   (a_cell, ("number("+a_number+")"), a_trace);
    CHECK_NUMBER_FLAG   (a_cell, ("number("+a_number+")"), a_trace);
    CHECK_DATE_TIME_FLAG(a_cell, ("number("+a_number+")"), a_trace);
    CHECK_FORMULA_FLAG  (a_cell, ("number("+a_number+")"), a_trace);

    a_cell.number = a_number;
    a_cell.status_flag.number_flag = true;
  }

  void simple_xmlss_set_date_time(model::cell& a_cell,
                              const std::string& a_date_time,
                              const utility::trace& a_trace) {
    CHECK_MERGE_FLAG    (a_cell, ("date_time("+a_date_time+")"), a_trace);
    CHECK_STRING_FLAG   (a_cell, ("date_time("+a_date_time+")"), a_trace);
    CHECK_NUMBER_FLAG   (a_cell, ("date_time("+a_date_time+")"), a_trace);
    CHECK_DATE_TIME_FLAG(a_cell, ("date_time("+a_date_time+")"), a_trace);
    CHECK_FORMULA_FLAG  (a_cell, ("date_time("+a_date_time+")"), a_trace);

    a_cell.date_time = a_date_time;
    a_cell.status_flag.date_time_flag = true;
  }

  void simple_xmlss_set_formula(model::cell& a_cell,
                            const std::string& a_formula,
                            const utility::trace& a_trace) {
    CHECK_MERGE_FLAG    (a_cell, ("formula("+a_formula+")"), a_trace);
    CHECK_STRING_FLAG   (a_cell, ("formula("+a_formula+")"), a_trace);
    CHECK_NUMBER_FLAG   (a_cell, ("formula("+a_formula+")"), a_trace);
    CHECK_DATE_TIME_FLAG(a_cell, ("formula("+a_formula+")"), a_trace);
    CHECK_FORMULA_FLAG  (a_cell, ("formula("+a_formula+")"), a_trace);

    a_cell.formula = a_formula;
    a_cell.status_flag.formula_flag = true;
  }
  
  void simple_xmlss_set_comment(model::cell& a_cell,
                            const std::string& a_comment,
                            const utility::trace& a_trace) {
    CHECK_MERGE_FLAG  (a_cell, ("comment("+a_comment+")"), a_trace);
    CHECK_COMMENT_FLAG(a_cell, ("comment("+a_comment+")"), a_trace);

    model::cell_font_string new_font_string;
    new_font_string.contents = a_comment;
    new_font_string.font_id = 0;
    a_cell.comment.string.push_back(new_font_string);
    a_cell.status_flag.comment_flag = true;
  }

  void simple_xmlss_set_comment(model::cell& a_cell,
                            const std::string& a_comment,
                            const unsigned int a_font_id,
                            const utility::trace& a_trace) {
    CHECK_MERGE_FLAG  (a_cell, ("comment("+a_comment+"),font_id("+std::to_string(a_font_id)+")"), a_trace);
    CHECK_COMMENT_FLAG(a_cell, ("comment("+a_comment+"),font_id("+std::to_string(a_font_id)+")"), a_trace);

    model::cell_font_string new_font_string;
    new_font_string.contents = a_comment;
    new_font_string.font_id = a_font_id;
    a_cell.comment.string.push_back(new_font_string);
    a_cell.status_flag.comment_flag = true;
  }

  void simple_xmlss_set_comment(model::cell& a_cell,
                            const model::cell_comment& a_comment,
                            const utility::trace& a_trace) {
    CHECK_MERGE_FLAG  (a_cell, ("comment(author:"+a_comment.author.contents+"<author_font_id:"+std::to_string(a_comment.author.font_id)+">"+get_cell_string(a_comment.string)+")"), a_trace);
    CHECK_COMMENT_FLAG(a_cell, ("comment(author:"+a_comment.author.contents+"<author_font_id:"+std::to_string(a_comment.author.font_id)+">"+get_cell_string(a_comment.string)+")"), a_trace);

    a_cell.comment = a_comment;
    a_cell.status_flag.comment_flag = true;
  }

  void simple_xmlss_set_hyperlink(model::cell& a_cell,
                              const std::string &a_hyperlink_sheet_name,
                              const unsigned int a_hyperlink_col,
                              const unsigned int a_hyperlink_row,
                              const utility::trace& a_trace) {
    std::string hyperlink_string = "#'" + 
                                   a_hyperlink_sheet_name + 
                                   "'!" + 
                                   utility::column2string(a_hyperlink_col) + 
                                   std::to_string(a_hyperlink_row);
    simple_xmlss_set_hyperlink(a_cell, hyperlink_string, a_trace);
  }

  void simple_xmlss_set_hyperlink(model::cell& a_cell,
                              const std::string& a_hyper_link_url,
                              const utility::trace& a_trace) {
    CHECK_MERGE_FLAG   (a_cell, ("hyperlink("+a_hyper_link_url+")"), a_trace);
    CHECK_CONTENTS_EXIST(a_cell, ("hyperlink("+a_hyper_link_url+")"), a_trace);

    a_cell.hyperlink = a_hyper_link_url;
    a_cell.status_flag.hyperlink_flag = true;
  }

  void simple_xmlss_set_style_id(model::cell& a_cell,
                             const unsigned int a_style_id,
                             const utility::trace& a_trace) {
    CHECK_MERGE_FLAG(a_cell, ("style_id("+std::to_string(a_style_id)+")"), a_trace);

    a_cell.style_id = a_style_id;
    a_cell.status_flag.style_flag = true;
  }

private:
  std::string get_cell_string(const model::cell_string& a_string) {
    std::string return_value;
    for(auto& iter: a_string) {
      if(0 < return_value.size()) {
        return_value += ",";
      }
      return_value += iter.contents;
      return_value += "<font_id:";
      return_value += std::to_string(iter.font_id);
      return_value += ">";
    }
    return return_value;
  }

  void handling_error(model::cell& a_cell,
                      const std::string& a_msg,
                      const utility::trace& a_trace) {
    utility::error new_error(a_trace.file_name,
                             a_trace.function_name,
                             std::to_string(a_trace.line),
                             a_cell.configuration.book_name,
                             a_cell.configuration.sheet_name,
                             std::to_string(a_cell.configuration.coordinate.col),
                             std::to_string(a_cell.configuration.coordinate.row),
                             a_msg);
    utility::error_handler::instance().handling_error(new_error);
  }
};

} // namespace api

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_API_CELL_HPP */