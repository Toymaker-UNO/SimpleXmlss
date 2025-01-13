#ifndef SIMPLE_XMLSS_BUILDER_COMMENT_HPP
#define SIMPLE_XMLSS_BUILDER_COMMENT_HPP

#include "simple_xmlss_model_cell_comment.hpp"
#include "simple_xmlss_utility_trace.hpp"
#include "simple_xmlss_utility_error.hpp"
#include "simple_xmlss_utility_error_handler.hpp"

namespace simple_xmlss {

namespace builder {

class comment {
public:  
  static comment&  instance(void) {
    static comment singleton_instance;
    return singleton_instance;
  }

  const model::cell_comment& build(void) {
    return m_cell_comment;
  }

  comment& clear(void) {
    m_cell_comment.string.clear();
    m_cell_comment.author.contents.clear();
    m_cell_comment.author.font_id = 0;
    m_author_flag = false;
    return (*this);
  }

  comment& set_comment(const std::string& a_comment) {
    return set_comment(a_comment,0);
  }

  comment& set_comment(const std::string& a_comment,
                       const unsigned int a_font_id) {
    model::cell_font_string new_cell_font_string;
    new_cell_font_string.contents = a_comment;
    new_cell_font_string.font_id = a_font_id;
    m_cell_comment.string.push_back(new_cell_font_string);
    return (*this);
  }

  comment& set_author(const std::string& a_author,
                      const utility::trace& a_trace = utility::trace()) {
    return set_author(a_author, 0, a_trace);
  }

  comment& set_author(const std::string& a_author,
                      const unsigned int a_font_id,
                      const utility::trace& a_trace = utility::trace()) {
    check_set_author(a_author,
                     a_font_id,
                     a_trace);
    m_cell_comment.author.contents = a_author;
    m_cell_comment.author.font_id = a_font_id;
    m_author_flag = true;
    return (*this);
  }

private:
  comment(void) : m_author_flag(false) {
    clear();
  }

  void check_set_author(const std::string& a_author,
                        const unsigned int a_font_id,
                        const utility::trace& a_trace) {
    if(false == m_author_flag) {
      return;
    }
    
    utility::error new_error(a_trace.file_name,
                             a_trace.function_name,
                            std::to_string(a_trace.line),
                            "N/A",
                            "N/A",
                            "N/A",
                            "N/A",
                            "Already exist author["+
                            m_cell_comment.author.contents+
                            "] font_id["+
                            std::to_string(m_cell_comment.author.font_id)+
                            "]. Discard: author["+
                            a_author+
                            "] font_id["+
                            std::to_string(a_font_id)+
                            "]");
    utility::error_handler::instance().handling_error(new_error);
  }

  model::cell_comment m_cell_comment;
  bool m_author_flag;
};

} // namespace builder

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_BUILDER_COMMENT_HPP */