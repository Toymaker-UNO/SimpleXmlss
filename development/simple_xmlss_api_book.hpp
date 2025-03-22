#ifndef SIMPLE_XMLSS_API_BOOK_HPP
#define SIMPLE_XMLSS_API_BOOK_HPP

#include "simple_xmlss_model_book.hpp"

namespace simple_xmlss {

namespace api {

class book {
public:
  simple_xmlss::sheet& simple_xmlss_get_sheet(model::book& a_book,
                                      const std::string& a_sheet_name) {
    auto iter = a_book.sheet_map.find(a_sheet_name);
    if(a_book.sheet_map.end() != iter) {
      return iter->second;
    }

    model::sheet_configuration new_sheet_configuration(a_book.book_name,
                                                       a_sheet_name);
    simple_xmlss::sheet new_sheet(new_sheet_configuration);
    a_book.sheet_map.insert(std::make_pair(a_sheet_name,
                                           new_sheet));
    a_book.sheet_order.push_back(a_sheet_name);
    return a_book.sheet_map.find(a_sheet_name)->second;
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::book& a_book,
                                      const std::string& a_string,
                                      const std::string& a_sheet_name,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                   set_string(a_string,
                              a_col,
                              a_row,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::book& a_book,
                                      const std::string& a_string,
                                      const unsigned int a_font_id,
                                      const std::string& a_sheet_name,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                   set_string(a_string,
                              a_font_id,
                              a_col,
                              a_row,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::book& a_book,
                                      const std::string& a_string,
                                      const std::string& a_sheet_name,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const unsigned int a_merge_across,
                                      const unsigned int a_merge_down,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                   set_string(a_string,
                              a_col,
                              a_row,
                              a_merge_across,
                              a_merge_down,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::book& a_book,
                                      const std::string& a_string,
                                      const unsigned int a_font_id,
                                      const std::string& a_sheet_name,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const unsigned int a_merge_across,
                                      const unsigned int a_merge_down,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                   set_string(a_string,
                              a_font_id,
                              a_col,
                              a_row,
                              a_merge_across,
                              a_merge_down,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::book& a_book,
                                      const model::cell_string& a_string,
                                      const std::string& a_sheet_name,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                   set_string(a_string,
                              a_col,
                              a_row,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::book& a_book,
                                      const model::cell_string& a_string,
                                      const std::string& a_sheet_name,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const unsigned int a_merge_across,
                                      const unsigned int a_merge_down,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                   set_string(a_string,
                              a_col,
                              a_row,
                              a_merge_across,
                              a_merge_down,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_number(model::book& a_book,
                                      const std::string& a_number,
                                      const std::string& a_sheet_name,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                   set_number(a_number,
                              a_col,
                              a_row,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_number(model::book& a_book,
                                      const std::string& a_number,
                                      const std::string& a_sheet_name,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const unsigned int a_merge_across,
                                      const unsigned int a_merge_down,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                   set_number(a_number,
                              a_col,
                              a_row,
                              a_merge_across,
                              a_merge_down,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_date_time(model::book& a_book,
                                         const std::string& a_date_time,
                                         const std::string& a_sheet_name,
                                         const unsigned int a_col,
                                         const unsigned int a_row,
                                         const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                set_date_time(a_date_time,
                              a_col,
                              a_row,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_date_time(model::book& a_book,
                                         const std::string& a_date_time,
                                         const std::string& a_sheet_name,
                                         const unsigned int a_col,
                                         const unsigned int a_row,
                                         const unsigned int a_merge_across,
                                         const unsigned int a_merge_down,
                                         const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                set_date_time(a_date_time,
                              a_col,
                              a_row,
                              a_merge_across,
                              a_merge_down,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_formula(model::book& a_book,
                                       const std::string& a_formula,
                                       const std::string& a_sheet_name,
                                       const unsigned int a_col,
                                       const unsigned int a_row,
                                       const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                  set_formula(a_formula,
                              a_col,
                              a_row,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_formula(model::book& a_book,
                                       const std::string& a_formula,
                                       const std::string& a_sheet_name,
                                       const unsigned int a_col,
                                       const unsigned int a_row,
                                       const unsigned int a_merge_across,
                                       const unsigned int a_merge_down,
                                       const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                  set_formula(a_formula,
                              a_col,
                              a_row,
                              a_merge_across,
                              a_merge_down,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_comment(model::book& a_book,
                                       const std::string& a_comment,
                                       const std::string& a_sheet_name,
                                       const unsigned int a_col,
                                       const unsigned int a_row,
                                       const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                  set_comment(a_comment,
                              a_col,
                              a_row,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_comment(model::book& a_book,
                                       const std::string& a_comment,
                                       const unsigned int a_font_id,
                                       const std::string& a_sheet_name,
                                       const unsigned int a_col,
                                       const unsigned int a_row,
                                       const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                  set_comment(a_comment,
                              a_font_id,
                              a_col,
                              a_row,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_comment(model::book& a_book,
                                       const model::cell_comment& a_comment,
                                       const std::string& a_sheet_name,
                                       const unsigned int a_col,
                                       const unsigned int a_row,
                                       const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                  set_comment(a_comment,
                              a_col,
                              a_row,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_hyperlink(model::book& a_book,
                                         const std::string& a_hyper_link_url,
                                         const std::string& a_sheet_name,
                                         const unsigned int a_col,
                                         const unsigned int a_row,
                                         const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                set_hyperlink(a_hyper_link_url,
                              a_col,
                              a_row,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_hyperlink(model::book& a_book,
                                         const std::string &a_hyperlink_sheet_name,
                                         const unsigned int a_hyperlink_col,
                                         const unsigned int a_hyperlink_row,
                                         const std::string& a_sheet_name,
                                         const unsigned int a_col,
                                         const unsigned int a_row,
                                         const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                set_hyperlink(a_hyperlink_sheet_name,
                              a_hyperlink_col,
                              a_hyperlink_row,
                              a_col,
                              a_row,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_style_id(model::book& a_book,
                                        const unsigned int a_style_id,
                                        const std::string& a_sheet_name,
                                        const unsigned int a_col,
                                        const unsigned int a_row,
                                        const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                 set_style_id(a_style_id,
                              a_col,
                              a_row,
                              a_trace);
  }

  void simple_xmlss_set_style_id(model::book& a_book,
                                 const unsigned int a_style_id,
                                 const std::string& a_sheet_name,
                                 const unsigned int a_col_begin,
                                 const unsigned int a_row_begin,
                                 const unsigned int a_col_end,
                                 const unsigned int a_row_end,
                                 const utility::trace& a_trace) {
    simple_xmlss_get_sheet(a_book,
                           a_sheet_name).
                 set_style_id(a_style_id,
                              a_col_begin,
                              a_row_begin,
                              a_col_end,
                              a_row_end,
                              a_trace);
  }

  simple_xmlss::sheet& simple_xmlss_set_row_height(model::book& a_book,
                                           const unsigned int a_row,
                                           const float a_height,
                                           const std::string& a_sheet_name,
                                           const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
               set_row_height(a_row,
                              a_height,
                              a_trace);
  }

  simple_xmlss::sheet& simple_xmlss_set_col_width(model::book& a_book,
                                         const unsigned int a_col,
                                         const float a_width,
                                         const std::string& a_sheet_name,
                                         const utility::trace& a_trace) {
    return simple_xmlss_get_sheet(a_book,
                              a_sheet_name).
                set_col_width(a_col,
                              a_width,
                              a_trace);
  }
};

} // namespace api

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_API_BOOK_HPP */