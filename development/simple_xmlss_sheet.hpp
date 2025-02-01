#ifndef SIMPLE_XMLSS_SHEET_HPP
#define SIMPLE_XMLSS_SHEET_HPP

#include "simple_xmlss_model_sheet.hpp"
#include "simple_xmlss_api_sheet.hpp"
#include "simple_xmlss_writer_sheet.hpp"

namespace simple_xmlss {

class sheet {
public:
  sheet(const model::sheet_configuration& a_sheet_configuration)
    : m_model(a_sheet_configuration) {}

  cell& get_cell(const unsigned int a_col,
                 const unsigned int a_row,
                 const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_get_cell(m_model,
                                   a_col,
                                   a_row,
                                   a_trace);
  }

  cell& get_cell(const unsigned int a_col,
                 const unsigned int a_row,
                 const unsigned int a_merge_across,
                 const unsigned int a_merge_down,
                 const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_get_cell(m_model,
                                   a_col,
                                   a_row,
                                   a_merge_across,
                                   a_merge_down,
                                   a_trace);
  }

  cell& set_string(const std::string& a_string,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_string(m_model,
                                    a_string,
                                    a_col,
                                    a_row,
                                    a_trace);
  }

  cell& set_string(const std::string& a_string,
                   const unsigned int a_font_id,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_string(m_model,
                                     a_string,
                                     a_font_id,
                                     a_col,
                                     a_row,
                                     a_trace);
  }

  cell& set_string(const std::string& a_string,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const unsigned int a_merge_across,
                   const unsigned int a_merge_down,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_string(m_model,
                                     a_string,
                                     a_col,
                                     a_row,
                                     a_merge_across,
                                     a_merge_down,
                                     a_trace);
  }

  cell& set_string(const std::string& a_string,
                   const unsigned int a_font_id,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const unsigned int a_merge_across,
                   const unsigned int a_merge_down,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_string(m_model,
                                     a_string,
                                     a_font_id,
                                     a_col,
                                     a_row,
                                     a_merge_across,
                                     a_merge_down,
                                     a_trace);
  }

  cell& set_string(const model::cell_string& a_string,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_string(m_model,
                                     a_string,
                                     a_col,
                                     a_row,
                                     a_trace);
  }

  cell& set_string(const model::cell_string& a_string,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const unsigned int a_merge_across,
                   const unsigned int a_merge_down,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_string(m_model,
                                     a_string,
                                     a_col,
                                     a_row,
                                     a_merge_across,
                                     a_merge_down,
                                     a_trace);
  }

  cell& set_number(const std::string& a_number,
                  const unsigned int a_col,
                  const unsigned int a_row,
                  const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_number(m_model,
                                     a_number,
                                     a_col,
                                     a_row,
                                     a_trace);
  }

  cell& set_number(const std::string& a_number,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const unsigned int a_merge_across,
                   const unsigned int a_merge_down,
                   const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_number(m_model,
                                     a_number,
                                     a_col,
                                     a_row,
                                     a_merge_across,
                                     a_merge_down,
                                     a_trace);
  }

  cell& set_date_time(const std::string& a_date_time,
                      const unsigned int a_col,
                      const unsigned int a_row,
                      const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_date_time(m_model,
                                 a_date_time,
                                 a_col,
                                 a_row,
                                 a_trace);
  }

  cell& set_date_time(const std::string& a_date_time,
                      const unsigned int a_col,
                      const unsigned int a_row,
                      const unsigned int a_merge_across,
                      const unsigned int a_merge_down,
                      const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_date_time(m_model,
                                        a_date_time,
                                        a_col,
                                        a_row,
                                        a_merge_across,
                                        a_merge_down,
                                        a_trace);
  }

  cell& set_formula(const std::string& a_formula,
                    const unsigned int a_col,
                    const unsigned int a_row,
                    const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_formula(m_model,
                                      a_formula,
                                      a_col,
                                      a_row,
                                      a_trace);
  }

  cell& set_formula(const std::string& a_formula,
                    const unsigned int a_col,
                    const unsigned int a_row,
                    const unsigned int a_merge_across,
                    const unsigned int a_merge_down,
                    const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_formula(m_model,
                                      a_formula,
                                      a_col,
                                      a_row,
                                      a_merge_across,
                                      a_merge_down,
                                      a_trace);
  }

  cell& set_comment(const std::string& a_comment,
                    const unsigned int a_col,
                    const unsigned int a_row,
                    const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_comment(m_model,
                                      a_comment,
                                      a_col,
                                      a_row,
                                      a_trace);
  }

  cell& set_comment(const std::string& a_comment,
                    const unsigned int a_font_id,
                    const unsigned int a_col,
                    const unsigned int a_row,
                    const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_comment(m_model,
                                      a_comment,
                                      a_font_id,
                                      a_col,
                                      a_row,
                                      a_trace);
  }

  cell& set_comment(const model::cell_comment& a_comment,
                    const unsigned int a_col,
                    const unsigned int a_row,
                    const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_comment(m_model,
                                      a_comment,
                                      a_col,
                                      a_row,
                                      a_trace);
  }

  cell& set_hyperlink(const std::string& a_hyper_link_url,
                      const unsigned int a_col,
                      const unsigned int a_row,
                      const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_hyperlink(m_model,
                                        a_hyper_link_url,
                                        a_col,
                                        a_row,
                                        a_trace);
  }

  cell& set_hyperlink(const std::string &a_hyperlink_sheet_name,
                      const unsigned int a_hyperlink_col,
                      const unsigned int a_hyperlink_row,
                      const unsigned int a_col,
                      const unsigned int a_row,
                      const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_hyperlink(m_model,
                                        a_hyperlink_sheet_name,
                                        a_hyperlink_col,
                                        a_hyperlink_row,
                                        a_col,
                                        a_row,
                                        a_trace);
  }

  cell& set_style_id(const unsigned int a_style_id,
                     const unsigned int a_col,
                     const unsigned int a_row,
                     const utility::trace& a_trace = utility::trace()) {
    return m_api.simple_xmlss_set_style_id(m_model,
                                       a_style_id,
                                       a_col,
                                       a_row,
                                       a_trace);
  }

  sheet& set_row_height(const unsigned int a_row,
                       const float a_height,
                       const utility::trace& a_trace = utility::trace()) {
    m_api.simple_xmlss_set_row_height(m_model,
                                  a_row,
                                  a_height,
                                  a_trace);
    return (*this);
  }

  sheet& set_col_width(const unsigned int a_col,
                      const float a_width,
                      const utility::trace& a_trace = utility::trace()) {
    m_api.simple_xmlss_set_col_width(m_model,
                                 a_col,
                                 a_width,
                                 a_trace);
    return (*this);
  }

  void print_xmlss(FILE* a_file) {
    m_writer.print_xmlss_node_worksheet(m_model,
                                        a_file);
  }

private:
  model::sheet m_model;
  api::sheet m_api;
  writer::sheet m_writer;
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_SHEET_HPP */