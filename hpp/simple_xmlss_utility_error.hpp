#ifndef SIMPLE_XMLSS_UTILITY_ERROR_HPP
#define SIMPLE_XMLSS_UTILITY_ERROR_HPP

#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace utility {

class error : public std::exception {
public:
  std::string file_name;
  std::string function_name;
  std::string line;
  std::string book_name;
  std::string sheet_name;
  std::string col;
  std::string row;
  std::string comment;
  std::string error_message;

  error(void){}

  error(const std::string& a_comment)
    : comment(a_comment),
      error_message(make_error_message("",
                                       "",
                                       "",
                                       "",
                                       "",
                                       "",
                                       "",
                                       a_comment)) {}

  error(const std::string& a_file_name,
        const std::string& a_function_name,
        const std::string& a_line,
        const std::string& a_book_name,
        const std::string& a_sheet_name,
        const std::string& a_col,
        const std::string& a_row,
        const std::string& a_comment)
    : file_name(a_file_name),
      function_name(a_function_name),
      line(a_line),
      book_name(a_book_name),
      sheet_name(a_sheet_name),
      col(a_col),
      row(a_row),
      comment(a_comment),
      error_message(make_error_message(a_file_name,
                                       a_function_name,
                                       a_line,
                                       a_book_name,
                                       a_sheet_name,
                                       a_col,
                                       a_row,
                                       a_comment)) {}
  
  const char *what(void) const noexcept override {
    return error_message.c_str();
  }

private:
  std::string make_error_message(const std::string& a_file_name,
                                 const std::string& a_function_name,
                                 const std::string& a_line,
                                 const std::string& a_book_name,
                                 const std::string& a_sheet_name,
                                 const std::string& a_col,
                                 const std::string& a_row,
                                 const std::string& a_comment) {
    std::string return_value = "<<simple_xmlss_exception>>\n";
    if(0 < a_file_name.size() && 
       0 < a_line.size()) {
      return_value += "Code Location: "+
                      a_file_name+
                      ":"+
                      a_line+
                      "\n";
    }
    if(0 < a_function_name.size()) {
      return_value += "Function: "+
                      a_function_name+
                      "\n";
    }
    if(0 < a_book_name.size() && 
       0 < a_sheet_name.size() && 
       0 < a_col.size() && 
       0 < a_row.size()) {
      return_value += "Location: "+
                      a_book_name+
                      ":"+
                      a_sheet_name+
                      ":[COL("+
                      a_col+
                      "):ROW("+
                      a_row+
                      ")]\n";
    }
    if(0 < a_comment.size()) {
      return_value += "Comment: "+
                      a_comment+"\n";
    }
    else {
      return_value += "Dummy Error Comment";
    }
    return return_value;
  }

};

} // namespace utility

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_UTILITY_ERROR_HPP */