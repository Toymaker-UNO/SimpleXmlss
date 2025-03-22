#ifndef SIMPLE_XMLSS_BOOK_HPP
#define SIMPLE_XMLSS_BOOK_HPP

#include "simple_xmlss_model_book.hpp"
#include "simple_xmlss_api_book.hpp"
#include "simple_xmlss_writer_book.hpp"
#include "simple_xmlss_builder_comment.hpp"
#include "simple_xmlss_builder_font.hpp"
#include "simple_xmlss_builder_string.hpp"
#include "simple_xmlss_builder_style.hpp"

namespace simple_xmlss {

class book {
public:
  book(const std::string& a_book_name = "DefaultBookName")
    : m_model(a_book_name) {
      builder::comment::instance();
      builder::font::instance();
      builder::string::instance();
      builder::style::instance();
    }

  sheet& get_sheet(const std::string& a_sheet_name) {
    return m_api.simple_xmlss_get_sheet(m_model,
                                    a_sheet_name);
  }

  cell& set_string(const std::string& a_string,
                   const std::string& a_sheet_name,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_string(m_model,
                                     a_string,
                                     a_sheet_name,
                                     a_col,
                                     a_row,
                                     a_trace);
  }

  cell& set_string(const std::string& a_string,
                   const unsigned int a_font_id,
                   const std::string& a_sheet_name,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_string(m_model,
                                     a_string,
                                     a_font_id,
                                     a_sheet_name,
                                     a_col,
                                     a_row,
                                     a_trace);
  }

  cell& set_string(const std::string& a_string,
                   const std::string& a_sheet_name,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const unsigned int a_merge_across,
                   const unsigned int a_merge_down,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_string(m_model,
                                     a_string,
                                     a_sheet_name,
                                     a_col,
                                     a_row,
                                     a_merge_across,
                                     a_merge_down,
                                     a_trace);
  }

  cell& set_string(const std::string& a_string,
                   const unsigned int a_font_id,
                   const std::string& a_sheet_name,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const unsigned int a_merge_across,
                   const unsigned int a_merge_down,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_string(m_model,
                                    a_string,
                                    a_font_id,
                                    a_sheet_name,
                                    a_col,
                                    a_row,
                                    a_merge_across,
                                    a_merge_down,
                                    a_trace);
  }

  cell& set_string(const model::cell_string& a_string,
                   const std::string& a_sheet_name,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_string(m_model,
                                     a_string,
                                     a_sheet_name,
                                     a_col,
                                     a_row,
                                     a_trace);
  }

  cell& set_string(const model::cell_string& a_string,
                   const std::string& a_sheet_name,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const unsigned int a_merge_across,
                   const unsigned int a_merge_down,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_string(m_model,
                                     a_string,
                                     a_sheet_name,
                                     a_col,
                                     a_row,
                                     a_merge_across,
                                     a_merge_down,
                                     a_trace);
  }

  cell& set_number(const std::string& a_number,
                   const std::string& a_sheet_name,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_number(m_model,
                                     a_number,
                                     a_sheet_name,
                                     a_col,
                                     a_row,
                                     a_trace);
  }

  cell& set_number(const std::string& a_number,
                   const std::string& a_sheet_name,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const unsigned int a_merge_across,
                   const unsigned int a_merge_down,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_number(m_model,
                                     a_number,
                                     a_sheet_name,
                                     a_col,
                                     a_row,
                                     a_merge_across,
                                     a_merge_down,
                                     a_trace);
  }

  cell& set_date_time(const std::string& a_date_time,
                      const std::string& a_sheet_name,
                      const unsigned int a_col,
                      const unsigned int a_row,
                      const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_date_time(m_model,
                                        a_date_time,
                                        a_sheet_name,
                                        a_col,
                                        a_row,
                                        a_trace);
  }

  cell& set_date_time(const std::string& a_date_time,
                      const std::string& a_sheet_name,
                      const unsigned int a_col,
                      const unsigned int a_row,
                      const unsigned int a_merge_across,
                      const unsigned int a_merge_down,
                      const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_date_time(m_model,
                                        a_date_time,
                                        a_sheet_name,
                                        a_col,
                                        a_row,
                                        a_merge_across,
                                        a_merge_down,
                                        a_trace);
  }

  cell& set_formula(const std::string& a_formula,
                    const std::string& a_sheet_name,
                    const unsigned int a_col,
                    const unsigned int a_row,
                    const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_formula(m_model,
                                      a_formula,
                                      a_sheet_name,
                                      a_col,
                                      a_row,
                                      a_trace);
  }

  cell& set_formula(const std::string& a_formula,
                    const std::string& a_sheet_name,
                    const unsigned int a_col,
                    const unsigned int a_row,
                    const unsigned int a_merge_across,
                    const unsigned int a_merge_down,
                    const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_formula(m_model,
                                      a_formula,
                                      a_sheet_name,
                                      a_col,
                                      a_row,
                                      a_merge_across,
                                      a_merge_down,
                                      a_trace);
  }

  cell& set_comment(const std::string& a_comment,
                    const std::string& a_sheet_name,
                    const unsigned int a_col,
                    const unsigned int a_row,
                    const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_comment(m_model,
                                      a_comment,
                                      a_sheet_name,
                                      a_col,
                                      a_row,
                                      a_trace);
  }

  cell& set_comment(const std::string& a_comment,
                    const unsigned int a_font_id,
                    const std::string& a_sheet_name,
                    const unsigned int a_col,
                    const unsigned int a_row,
                    const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_comment(m_model,
                                      a_comment,
                                      a_font_id,
                                      a_sheet_name,
                                      a_col,
                                      a_row,
                                      a_trace);
  }

  cell& set_comment(const model::cell_comment& a_comment,
                    const std::string& a_sheet_name,
                    const unsigned int a_col,
                    const unsigned int a_row,
                    const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_comment(m_model,
                                      a_comment,
                                      a_sheet_name,
                                      a_col,
                                      a_row,
                                      a_trace);
  }

  cell& set_hyperlink(const std::string& a_hyper_link_url,
                      const std::string& a_sheet_name,
                      const unsigned int a_col,
                      const unsigned int a_row,
                      const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_hyperlink(m_model,
                                        a_hyper_link_url,
                                        a_sheet_name,
                                        a_col,
                                        a_row,
                                        a_trace);
  }

  cell& set_hyperlink(const std::string &a_hyperlink_sheet_name,
                      const unsigned int a_hyperlink_col,
                      const unsigned int a_hyperlink_row,
                      const std::string& a_sheet_name,
                      const unsigned int a_col,
                      const unsigned int a_row,
                      const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_hyperlink(m_model,
                                        a_hyperlink_sheet_name,
                                        a_hyperlink_col,
                                        a_hyperlink_row,
                                        a_sheet_name,
                                        a_col,
                                        a_row,
                                        a_trace);
  }

  cell& set_style_id(const unsigned int a_style_id,
                     const std::string& a_sheet_name,
                     const unsigned int a_col,
                     const unsigned int a_row,
                     const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_style_id(m_model,
                                       a_style_id,
                                       a_sheet_name,
                                       a_col,
                                       a_row,
                                       a_trace);
  }

  void set_style_id(const unsigned int a_style_id,
                    const std::string& a_sheet_name,
                    const unsigned int a_col_begin,
                    const unsigned int a_row_begin,
                    const unsigned int a_col_end,
                    const unsigned int a_row_end,
                    const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_style_id(m_model,
                                        a_style_id,
                                        a_sheet_name,
                                        a_col_begin,
                                        a_row_begin,
                                        a_col_end,
                                        a_row_end,
                                        a_trace);
  }

  sheet& set_row_height(const unsigned int a_row,
                        const float a_height,
                        const std::string& a_sheet_name,
                        const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_row_height(m_model,
                                         a_row,
                                         a_height,
                                         a_sheet_name,
                                         a_trace);
  }

  sheet& set_col_width(const unsigned int a_col,
                       const float a_width,
                       const std::string& a_sheet_name,
                       const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_col_width(m_model,
                                        a_col,
                                        a_width,
                                        a_sheet_name,
                                        a_trace);
  }

  void print_xmlss(const std::string& a_file_name,
                   const utility::trace& a_trace = utility::trace()) {
    FILE* p_file = fopen(a_file_name.c_str(), "w+");
    if(NULL == p_file) {
      utility::error new_error(a_trace.file_name,
                               a_trace.function_name,
                               std::to_string(a_trace.line),
                               "N/A",
                               "N/A",
                               "N/A",
                               "N/A",
                               "[ERROR] open(" + a_file_name + ", \"w+\") fail");
      utility::error_handler::instance().handling_error(new_error);      
      return;
    }
    m_writer.print_xmlss_book(m_model,p_file);
    fclose(p_file);
  }

private:
  model::book m_model;
  api::book m_api;
  writer::book m_writer;
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_BOOK_HPP */