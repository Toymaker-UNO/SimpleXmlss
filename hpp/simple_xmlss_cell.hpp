#ifndef SIMPLE_XMLSS_CELL_HPP
#define SIMPLE_XMLSS_CELL_HPP

#include "simple_xmlss_api_cell.hpp"
#include "simple_xmlss_writer_cell.hpp"
#include "simple_xmlss_model_cell.hpp"

namespace simple_xmlss {

class cell {
public:
  cell(const model::cell_configuration& a_configuration)
    : m_model(a_configuration) {}

  cell& set_string(const std::string& a_string,
                   const utility::trace& a_trace = utility::trace()) {
    m_api.simple_xmlss_set_string(m_model,
                              a_string,
                              a_trace);
    return (*this);
  }

  cell& set_string(const std::string& a_string,
                   const unsigned int a_font_id,
                   const utility::trace& a_trace = utility::trace()) {
    m_api.simple_xmlss_set_string(m_model,
                              a_string,
                              a_font_id,
                              a_trace);
    return (*this);
  }

  cell& set_string(const model::cell_string& a_string,
                   const utility::trace& a_trace = utility::trace()) {
    m_api.simple_xmlss_set_string(m_model,
                              a_string,
                              a_trace);
    return (*this);
  }

  cell& set_number(const std::string& a_number,
                   const utility::trace& a_trace = utility::trace()) {
    m_api.simple_xmlss_set_number(m_model,
                              a_number,
                              a_trace);
    return (*this);
  }

  cell& set_date_time(const std::string& a_date_time,
                      const utility::trace& a_trace = utility::trace()) {
    m_api.simple_xmlss_set_date_time(m_model,
                                 a_date_time,
                                 a_trace);
    return (*this);
  }

  cell& set_formula(const std::string& a_formula,
                    const utility::trace& a_trace = utility::trace()) {
    m_api.simple_xmlss_set_formula(m_model,
                               a_formula,
                               a_trace);
    return (*this);
  }

  cell& set_comment(const std::string& a_comment,
                    const utility::trace& a_trace = utility::trace()) {
    m_api.simple_xmlss_set_comment(m_model,
                               a_comment,
                               a_trace);
    return (*this);
  }

  cell& set_comment(const std::string& a_comment,
                    const unsigned int a_font_id,
                    const utility::trace& a_trace = utility::trace()) {
    m_api.simple_xmlss_set_comment(m_model,
                               a_comment,
                               a_font_id,
                               a_trace);
    return (*this);
  }

  cell& set_comment(const model::cell_comment& a_comment,
                    const utility::trace& a_trace = utility::trace()) {
    m_api.simple_xmlss_set_comment(m_model,
                               a_comment,
                               a_trace);
    return (*this);                            
  }

  cell& set_hyperlink(const std::string &a_hyperlink_sheet_name,
                      const unsigned int a_hyperlink_col,
                      const unsigned int a_hyperlink_row,
                      const utility::trace& a_trace = utility::trace()) {
    m_api.simple_xmlss_set_hyperlink(m_model,
                                 a_hyperlink_sheet_name,
                                 a_hyperlink_col,
                                 a_hyperlink_row,
                                 a_trace);
    return (*this);
  }

  cell& set_hyperlink(const std::string& a_hyper_link_url,
                      const utility::trace& a_trace = utility::trace()) {
    m_api.simple_xmlss_set_hyperlink(m_model,
                                 a_hyper_link_url,
                                 a_trace);
    return (*this);
  }

  cell& set_style_id(const unsigned int a_style_id,
                     const utility::trace& a_trace = utility::trace()) {
    m_api.simple_xmlss_set_style_id(m_model,
                                a_style_id,
                                a_trace);
    return (*this);
  }

  void print_xmlss(FILE* a_file) {
    m_writer.print_xmlss(m_model,
                         a_file);
  }

  const model::cell_configuration& get_configuration(void) const {
    return m_model.configuration;
  }

private:
  model::cell m_model;
  api::cell m_api;
  writer::cell m_writer;
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_CELL_HPP */