/***************************************************************************************************
****************************************************************************************************
MIT License

Copyright (c) 2024 Dong-Hun Kim

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
****************************************************************************************************
***************************************************************************************************/
#ifndef SIMPLE_XMLSS_DEPENDENCY_HPP
#define SIMPLE_XMLSS_DEPENDENCY_HPP

#include <string>
#include <exception>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <ctime>

#endif /* SIMPLE_XMLSS_DEPENDENCY_HPP */


#ifndef SIMPLE_XMLSS_UTILITY_ERROR_HPP
#define SIMPLE_XMLSS_UTILITY_ERROR_HPP

//#include "simple_xmlss_dependency.hpp"

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


#ifndef SIMPLE_XMLSS_UTILITY_ERROR_HANDLER_HPP
#define SIMPLE_XMLSS_UTILITY_ERROR_HANDLER_HPP

//#include "simple_xmlss_utility_error.hpp"

namespace simple_xmlss {

namespace utility {

class error_handler {
public:  
  static error_handler&  instance(void) {
    static error_handler singleton_instance;
    return singleton_instance;
  }

  void handling_error(const error& a_error) {
    m_error = a_error;
    throw m_error;
  }

private:
  error_handler(void) {}
  ~error_handler(void) {}

  error m_error;
};

} // namespace utility

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_UTILITY_ERROR_HANDLER_HPP */


#ifndef SIMPLE_XMLSS_UTILITY_INLINE_FUNCTIONS_HPP
#define SIMPLE_XMLSS_UTILITY_INLINE_FUNCTIONS_HPP

//#include "simple_xmlss_dependency.hpp"

//#define DEBUG_PRINT() { printf("[DEBUG] %s:%d\n", __FILE__, __LINE__); fflush(stdout); }
//#define DEBUG_PRINT_FMT(fmt,args...) { printf("[DEBUG] %s:%d - ", __FILE__, __LINE__); printf(fmt,##args); printf("\n"); fflush(stdout); }

namespace simple_xmlss {

namespace utility {

#define simple_xmlss_fprintf(p_file,args...) {   \
  fprintf(p_file,##args);                 \
}

inline std::string column2string(unsigned int column) {
  std::list<unsigned int> remainder_list;
  while (column > 0) {
    column--;
    unsigned int remainder = column % 26;
    column = column / 26;
    remainder_list.push_back(remainder);
  }

  std::string return_value;
  for (auto it = remainder_list.rbegin(); it != remainder_list.rend(); it++) {
    char ch = 'A' + (char)*it;
    return_value += ch;
  }
  return return_value;
}

inline std::string get_system_time_string(void) {
  time_t now = time(nullptr);
  struct tm* ptm = std::localtime(&now);

  char tmp_str[40] = {0,};
  snprintf(tmp_str, 39, "%4d-%02d-%02dT%02d:%02d:%02dZ", ptm->tm_year + 1900,
           ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min,
           ptm->tm_sec);
  std::string return_value = tmp_str;
  return return_value;
}

inline std::string get_style_id_string(const unsigned int a_tyle_id) {
  std::string return_value = "s" + std::to_string(a_tyle_id) + "_sty";
  return return_value;
}

inline std::string std_string2xml_string(const std::string &str) {
  std::string return_value;
  for (auto &ch : str) {
    if ('<' == ch) {
      return_value += "&lt;";
    } else if ('>' == ch) {
      return_value += "&gt;";
    } else if ('&' == ch) {
      return_value += "&amp;";
    } else if ('"' == ch) {
      return_value += "&quot;";
    } else if ('\'' == ch) {
      return_value += "&apos;";
    } else if (10 == ch) {
      return_value += "&#10;";
    } else if ('\n' == ch) {
      return_value += "&#10;";
    } else {
      return_value += ch;
    }
  }
  return return_value;
}

} // namespace utility

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_UTILITY_INLINE_FUNCTIONS_HPP */


#ifndef SIMPLE_XMLSS_TIME_MANAGER_HPP
#define SIMPLE_XMLSS_TIME_MANAGER_HPP

//#include "simple_xmlss_utility_inline_functions.hpp"

namespace simple_xmlss {

namespace utility {

class time_manager {
public:
  static time_manager& instance(void) {
    static time_manager singleton_instance;
    return singleton_instance;
  }

  void set_debug_flag(const bool a_debug_flag) {
    debug_flag = a_debug_flag;
  }

  std::string get_time_string(void) {
    if (true == debug_flag) {
      return "2017-02-17T14:12:17Z";
    }
    return get_system_time_string();
  }

private:
  time_manager(void): debug_flag(false) {}
  bool debug_flag;
};

} // namespace utility

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TIME_MANAGER_HPP */


#ifndef SIMPLE_XMLSS_UTILITY_TRACE_HPP
#define SIMPLE_XMLSS_UTILITY_TRACE_HPP

//#include "simple_xmlss_dependency.hpp"

#define TRACE() simple_xmlss::utility::trace(__FILE__, __func__ ,__LINE__)

namespace simple_xmlss {

namespace utility {

class trace {
public:
  const std::string file_name;
  const std::string function_name;
  const unsigned int line;

  trace(void)
    : file_name("N/A"),
      function_name("N/A"),
      line(0) {}
  
  trace(const std::string& a_file_name,
        const std::string& a_function_name,
        const unsigned int a_line)
    : file_name(a_file_name),
      function_name(a_function_name),
      line(a_line) {}
};

} // namespace api

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_UTILITY_TRACE_HPP */


#ifndef SIMPLE_XMLSS_MODEL_FONT_CHAR_SET_HPP
#define SIMPLE_XMLSS_MODEL_FONT_CHAR_SET_HPP

namespace simple_xmlss {

namespace model {

enum class FONT_CHAR_SET {
  NONE = -1,
  ANSI_CHARSET = 0,
  DEFAULT_CHARSET = 1,
  SYMBOL_CHARSET = 2,
  MAC_CHARSET = 77,
  SHIFTJIS_CHARSET = 128, //  (일본어)
  HANGUL_CHARSET = 129, // (한국어)
  GB2312_CHARSET = 134, // (중국어 간체)
  CHINESEBIG5_CHARSET = 136, // (중국어 번체)
  GREEK_CHARSET = 161, // (그리스어)
  TURKISH_CHARSET = 162, // (터키어)
  HEBREW_CHARSET = 177, // (히브리어)
  ARABIC_CHARSET = 178, // (아랍어)
  BALTIC_CHARSET = 186, // (발트어)
  RUSSIAN_CHARSET = 204, //  (러시아어)
  THAI_CHARSET = 222, // (태국어)
  EASTEUROPE_CHARSET = 238, // (동유럽어)
  OEM_CHARSET = 255,
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_FONT_CHAR_SET_HPP */


#ifndef SIMPLE_XMLSS_MODEL_FONT_SUPERSCRIPT_SUBSCRIPT_HPP
#define SIMPLE_XMLSS_MODEL_FONT_SUPERSCRIPT_SUBSCRIPT_HPP

//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class FONT_SUPERSCRIPT_SUBSCRIPT {
  NONE = 0,
  SUPERSCRIPT = 1,
  SUBSCRIPT = 2,
};

inline std::string to_string(const FONT_SUPERSCRIPT_SUBSCRIPT& a_superscript_subscript) {
  if (FONT_SUPERSCRIPT_SUBSCRIPT::SUPERSCRIPT == a_superscript_subscript) {
    return "Superscript";
  }
  else if (FONT_SUPERSCRIPT_SUBSCRIPT::SUBSCRIPT == a_superscript_subscript) {
    return "Subscript";
  }
	return "None";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_FONT_SUPERSCRIPT_SUBSCRIPT_HPP */


#ifndef SIMPLE_XMLSS_MODEL_FONT_UNDERLINE_HPP
#define SIMPLE_XMLSS_MODEL_FONT_UNDERLINE_HPP

//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class FONT_UNDERLINE {
  NONE = 0,
  SINGLE = 1,
  DOUBLE = 2,
  SINGLE_ACCOUNTING = 3,
  DOUBLE_ACCOUNTING = 4,
};

inline std::string to_string(const FONT_UNDERLINE& a_underline) {
  if (FONT_UNDERLINE::SINGLE == a_underline) {
    return "Single";
  }
  else if (FONT_UNDERLINE::DOUBLE == a_underline) {
    return "Double";
  }
  else if (FONT_UNDERLINE::SINGLE_ACCOUNTING == a_underline) {
    return "SingleAccounting";
  }
  else if (FONT_UNDERLINE::DOUBLE_ACCOUNTING == a_underline) {
    return "DoubleAccounting";
  }
	return "None";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_FONT_UNDERLINE_HPP */


#ifndef SIMPLE_XMLSS_MODEL_FONT_HPP
#define SIMPLE_XMLSS_MODEL_FONT_HPP

//#include "simple_xmlss_model_font_char_set.hpp"
//#include "simple_xmlss_model_font_underline.hpp"
//#include "simple_xmlss_model_font_superscript_subscript.hpp"
//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

class font {
public:
  unsigned int id;
  std::string name;
  FONT_CHAR_SET char_set;
  std::string family_name;
  std::string color;
  unsigned int size;
  FONT_UNDERLINE underline;
  FONT_SUPERSCRIPT_SUBSCRIPT superscript_subscript;
  bool italic;
  bool bold;
  bool strikethrough;

  font(void)
    : id(0),
      name("Tahoma"),
      char_set(model::FONT_CHAR_SET::NONE),
      family_name("Swiss"),
      color(""),
      size(11),
      underline(model::FONT_UNDERLINE::NONE),
      superscript_subscript(model::FONT_SUPERSCRIPT_SUBSCRIPT::NONE),
      italic(false),
      bold(false),
      strikethrough(false) {}

  void clear(void) {
    id = 0;
    name = "Tahoma";
    char_set = model::FONT_CHAR_SET::NONE;
    family_name = "Swiss";
    color = "";
    size = 11;
    underline = model::FONT_UNDERLINE::NONE;
    superscript_subscript = model::FONT_SUPERSCRIPT_SUBSCRIPT::NONE;
    italic = false;
    bold = false;
    strikethrough = false;
  }
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_FONT_HPP */


#ifndef SIMPLE_XMLSS_MODEL_FONT_MAP_HPP
#define SIMPLE_XMLSS_MODEL_FONT_MAP_HPP

//#include "simple_xmlss_model_font.hpp"
//#include "simple_xmlss_dependency.hpp"

enum PRESET_FONT {
  E_PRESET_FONT_DOCUMENT_DEFAULT = 0,
  E_PRESET_FONT_DEFAULT = 1,
  E_PRESET_FONT_HYPERLINK = 2,
  E_PRESET_FONT_BLACK = 3,
  E_PRESET_FONT_WHITE = 4,
};

namespace simple_xmlss {

namespace model {

typedef std::map<unsigned int, font> font_map;

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_FONT_MAP_HPP */


#ifndef SIMPLE_XMLSS_WRITER_FONT_MAP_HPP
#define SIMPLE_XMLSS_WRITER_FONT_MAP_HPP

//#include "simple_xmlss_model_font_map.hpp"
//#include "simple_xmlss_utility_inline_functions.hpp"

namespace simple_xmlss {

namespace writer {

class font_map {
public:
  void print_xmlss(model::font_map& a_font_map,
                   const unsigned int a_font_id,
                   FILE* a_file) {
    if(E_PRESET_FONT_DEFAULT == a_font_id) {
      return;
    }

    auto iter = a_font_map.find(a_font_id);
    if(a_font_map.end() == iter) {
      return;
    }

    print_xmlss(iter->second, a_file);
  }

private:
  void print_xmlss(const model::font& a_font,
                   FILE* a_file) {
    simple_xmlss_fprintf(a_file, "   <Font");
    simple_xmlss_fprintf(a_file, " ss:FontName=\"%s\"", a_font.name.c_str());
    if(model::FONT_CHAR_SET::NONE != a_font.char_set) {
      simple_xmlss_fprintf(a_file, " x:CharSet=\"%d\"", (int)a_font.char_set);
    }
    simple_xmlss_fprintf(a_file, " x:Family=\"%s\"", a_font.family_name.c_str());
    simple_xmlss_fprintf(a_file, " ss:Size=\"%u\"", a_font.size);
    if( 0 < a_font.color.size()) {
      simple_xmlss_fprintf(a_file, " ss:Color=\"%s\"", a_font.color.c_str());
    }
    if(model::FONT_UNDERLINE::NONE != a_font.underline) {
      simple_xmlss_fprintf(a_file, " ss:Underline=\"%s\"", model::to_string(a_font.underline).c_str());
    }
    if(model::FONT_SUPERSCRIPT_SUBSCRIPT::NONE != a_font.superscript_subscript) {
      simple_xmlss_fprintf(a_file, " ss:VerticalAlign=\"%s\"", model::to_string(a_font.superscript_subscript).c_str());
    }
    if(true == a_font.bold) {
      simple_xmlss_fprintf(a_file, "  ss:Bold=\"1\"");
    }
    if(true == a_font.italic) {
      simple_xmlss_fprintf(a_file, "  ss:Italic=\"1\"");
    }
    if(true == a_font.strikethrough) {
      simple_xmlss_fprintf(a_file, "  ss:StrikeThrough=\"1\"");
    }
    simple_xmlss_fprintf(a_file, "/>\n");
  }
};

} // namespace writer

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_WRITER_FONT_MAP_HPP */


#ifndef SIMPLE_XMLSS_API_FONT_MAP_HPP
#define SIMPLE_XMLSS_API_FONT_MAP_HPP

//#include "simple_xmlss_model_font_map.hpp"

namespace simple_xmlss {

namespace api {

class font_map {
public:
  void initialize(model::font_map& a_font_map) {
    a_font_map.clear();

    clear();
    build(a_font_map, E_PRESET_FONT_DOCUMENT_DEFAULT);

    clear();
    build(a_font_map, E_PRESET_FONT_DEFAULT);

    clear();
    set_color("#1A0DAB");
    set_underline(model::FONT_UNDERLINE::SINGLE);
    build(a_font_map, E_PRESET_FONT_HYPERLINK);

    clear();
    set_color("#000000");
    build(a_font_map, E_PRESET_FONT_BLACK);

    clear();
    set_color("#FFFFFF");
    build(a_font_map, E_PRESET_FONT_WHITE);
    
    clear();
  }

  const model::font& get_font(model::font_map& a_font_map, const unsigned int a_font_id) {
    return a_font_map.find(a_font_id)->second;
  }

  unsigned int build(model::font_map& a_font_map) {
    unsigned int return_value = (unsigned int)a_font_map.size();
    m_font.id = return_value;
    a_font_map.insert(std::make_pair(return_value,m_font));
    return return_value;
  }

  void clear(void) {
    m_font.clear();
  }

  void set_name(const std::string& a_name) {
    m_font.name = a_name;
  }

  void set_char_set(const model::FONT_CHAR_SET a_char_set) {
    m_font.char_set = a_char_set;
  }

  void set_family_name(const std::string& a_family_name) {
    m_font.family_name = a_family_name;
  }

  void set_color(const std::string& a_color) {
    m_font.color = a_color;
  }

  void set_size(const unsigned int a_size) {
    m_font.size = a_size;
  }

  void set_underline(const model::FONT_UNDERLINE a_underline) {
    m_font.underline = a_underline;
  }

  void set_superscript_subscript(const model::FONT_SUPERSCRIPT_SUBSCRIPT a_superscript_subscript) {
    m_font.superscript_subscript = a_superscript_subscript;
  }

  void set_italic(const bool a_italic) {
    m_font.italic = a_italic;
  }

  void set_bold(const bool a_bold) {
    m_font.bold = a_bold;
  }

  void set_strikethrough(const bool a_strikethrough) {
    m_font.strikethrough = a_strikethrough;
  }

private:
  void build(model::font_map& a_font_map, const unsigned int a_font_id) {
    m_font.id = a_font_id;
    a_font_map.insert(std::make_pair(a_font_id,m_font));
  }

  model::font m_font;
};

} // namespace api

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_API_FONT_MAP_HPP */


#ifndef SIMPLE_XMLSS_BUILDER_FONT_HPP
#define SIMPLE_XMLSS_BUILDER_FONT_HPP

//#include "simple_xmlss_model_font_map.hpp"
//#include "simple_xmlss_api_font_map.hpp"
//#include "simple_xmlss_writer_font_map.hpp"

namespace simple_xmlss {

namespace builder {

class font {
public:  
  static font&  instance(void) {
    static font singleton_instance;
    return singleton_instance;
  }

  void initialize(void) {
    m_api.initialize(m_model);
  }

  const model::font& get_font(const unsigned int a_font_id) {
    return m_api.get_font(m_model, a_font_id);
  }

  unsigned int build(void) {
    return m_api.build(m_model);
  }

  font& clear(void) {
    m_api.clear();
    return (*this);
  }

  font& set_name(const std::string& a_name) {
    m_api.set_name(a_name);
    return (*this);
  }

  font& set_char_set(const model::FONT_CHAR_SET a_char_set) {
    m_api.set_char_set(a_char_set);
    return (*this);
  }

  font& set_family_name(const std::string& a_family_name) {
    m_api.set_family_name(a_family_name);
    return (*this);
  }

  font& set_color(const std::string& a_color) {
    m_api.set_color(a_color);
    return (*this);
  }

  font& set_size(const unsigned int a_size) {
    m_api.set_size(a_size);
    return (*this);
  }

  font& set_underline(const model::FONT_UNDERLINE a_underline) {
    m_api.set_underline(a_underline);
    return (*this);
  }

  font& set_superscript_subscript(const model::FONT_SUPERSCRIPT_SUBSCRIPT a_superscript_subscript) {
    m_api.set_superscript_subscript(a_superscript_subscript);
    return (*this);
  }

  font& set_italic(const bool a_italic) {
    m_api.set_italic(a_italic);
    return (*this);
  }

  font& set_bold(const bool a_bold) {
    m_api.set_bold(a_bold);
    return (*this);
  }

  font& set_strikethrough(const bool a_strikethrough) {
    m_api.set_strikethrough(a_strikethrough);
    return (*this);
  }

  void print_xmlss(FILE* a_file, const unsigned int a_font_id) {
    m_writer.print_xmlss(m_model, a_font_id, a_file);
  }

private:
  font(void) {
    initialize();
  }

  model::font_map m_model;
  api::font_map m_api;
  writer::font_map m_writer;
};

} // namespace builder

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_BUILDER_FONT_HPP */


#ifndef SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_HORIZONTAL_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_HORIZONTAL_HPP

//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class STYLE_ALIGNMENT_HORIZONTAL {
  NONE = 0,
  LEFT = 1,
  CENTER = 2,
  RIGHT = 3,
  FILL = 4,
  JUSTIFY = 5,
  CENTER_ACROSS_SELECTION = 6,
  DISTRIBUTED = 7,
};

inline std::string to_string(const STYLE_ALIGNMENT_HORIZONTAL& a_horizontal) {
  if (STYLE_ALIGNMENT_HORIZONTAL::NONE == a_horizontal) {
    return "None";
  }
  else if (STYLE_ALIGNMENT_HORIZONTAL::LEFT == a_horizontal) {
    return "Left";
  }
  else if (STYLE_ALIGNMENT_HORIZONTAL::CENTER == a_horizontal) {
    return "Center";
  }
  else if (STYLE_ALIGNMENT_HORIZONTAL::RIGHT == a_horizontal) {
    return "Right";
  }
  else if (STYLE_ALIGNMENT_HORIZONTAL::FILL == a_horizontal) {
    return "Fill";
  }
  else if (STYLE_ALIGNMENT_HORIZONTAL::JUSTIFY == a_horizontal) {
    return "Justify";
  }
  else if (STYLE_ALIGNMENT_HORIZONTAL::CENTER_ACROSS_SELECTION == a_horizontal) {
    return "CenterAcrossSelection";
  }
  else if (STYLE_ALIGNMENT_HORIZONTAL::DISTRIBUTED == a_horizontal) {
    return "Distributed";
  }
  return "None";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_HORIZONTAL_HPP */


#ifndef SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_TEXT_CONTROL_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_TEXT_CONTROL_HPP

//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class STYLE_ALIGNMENT_TEXT_CONTROL {
  NONE = 0,
  WRAP_TEXT = 1,
  SHRINK_TO_FIT = 2,
};

inline std::string to_string(const STYLE_ALIGNMENT_TEXT_CONTROL& a_text_control) {
  if(STYLE_ALIGNMENT_TEXT_CONTROL::WRAP_TEXT == a_text_control) {
      return "WrapText";
  }
  else if (STYLE_ALIGNMENT_TEXT_CONTROL::SHRINK_TO_FIT == a_text_control) {
    return "ShrinkToFit";
  }
  return "None";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_TEXT_CONTROL_HPP */


#ifndef SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_VERTICAL_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_VERTICAL_HPP

//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class STYLE_ALIGNMENT_VERTICAL {
  NONE = 0,
  TOP = 1,
  CENTER = 2,
  BOTTOM = 3,
  JUSTIFY = 4,
  DISTRIBUTED = 5,
};

inline std::string to_string(const STYLE_ALIGNMENT_VERTICAL& a_vertical) {
  if (STYLE_ALIGNMENT_VERTICAL::NONE == a_vertical) {
    return "None";
  }
  else if (STYLE_ALIGNMENT_VERTICAL::TOP == a_vertical) {
    return "Top";
  }      
  else if (STYLE_ALIGNMENT_VERTICAL::CENTER == a_vertical) {
    return "Center";
  } 
  else if (STYLE_ALIGNMENT_VERTICAL::BOTTOM == a_vertical) {
    return "Bottom";
  }
  else if (STYLE_ALIGNMENT_VERTICAL::JUSTIFY == a_vertical) {
    return "Justify";
  }
  else if (STYLE_ALIGNMENT_VERTICAL::DISTRIBUTED == a_vertical) {
    return "Distributed";
  }
  return "None";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_VERTICAL_HPP */


#ifndef SIMPLE_XMLSS_MODEL_STYLE_BORDER_LINE_TYPE_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_BORDER_LINE_TYPE_HPP

//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class STYLE_BORDER_LINE_TYPE {
  NONE = 0,
  DOT = 1,
  DASHDOTDOT = 2,
  DASHDOT = 3,
  DASH = 4,
  CONTINUOUS = 5,
  SLANTDASHDOT = 6,
  DOUBLE = 7,
};

inline std::string to_string(const STYLE_BORDER_LINE_TYPE& a_line_type) {
  if (STYLE_BORDER_LINE_TYPE::NONE == a_line_type) {
    return "None";
  }
  else if (model::STYLE_BORDER_LINE_TYPE::DOT == a_line_type) {
    return "Dot";
  }
  else if (model::STYLE_BORDER_LINE_TYPE::DASHDOTDOT == a_line_type) {
    return "DashDotDot";
  }
  else if (model::STYLE_BORDER_LINE_TYPE::DASHDOT == a_line_type) {
    return "DashDot";
  }
  else if (model::STYLE_BORDER_LINE_TYPE::DASH == a_line_type) {
    return "Dash";
  }
  else if (model::STYLE_BORDER_LINE_TYPE::CONTINUOUS == a_line_type) {
    return "Continuous";
  }
  else if (model::STYLE_BORDER_LINE_TYPE::SLANTDASHDOT == a_line_type) {
    return "SlantDashDot";
  }
  else if (model::STYLE_BORDER_LINE_TYPE::DOUBLE == a_line_type) {
    return "Double";
  } 
  return "None";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_BORDER_LINE_TYPE_HPP */


#ifndef SIMPLE_XMLSS_MODEL_STYLE_BORDER_POSITION_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_BORDER_POSITION_HPP

//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class STYLE_BORDER_POSITION {
  NONE = 0,
  LEFT = 1,
  TOP = 2,
  RIGHT = 3,
  BOTTOM = 4,
  DIAGONAL_RIGHT = 5,
  DIAGONAL_LEFT = 6,
};

inline std::string to_string(const STYLE_BORDER_POSITION& a_position) {
  if (STYLE_BORDER_POSITION::LEFT == a_position) {
    return "Left";
  } else if (STYLE_BORDER_POSITION::TOP == a_position) {
    return "Top";
  } else if (STYLE_BORDER_POSITION::RIGHT == a_position) {
    return "Right";
  } else if (STYLE_BORDER_POSITION::BOTTOM == a_position) {
    return "Bottom";
  } else if (STYLE_BORDER_POSITION::DIAGONAL_LEFT == a_position) {
    return "DiagonalLeft";
  } else if (STYLE_BORDER_POSITION::DIAGONAL_RIGHT == a_position) {
    return "DiagonalRight";
  } 
  return "";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_POSITION_BORDER_HPP */


#ifndef SIMPLE_XMLSS_MODEL_STYLE_BORDER_WEIGHT_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_BORDER_WEIGHT_HPP

namespace simple_xmlss {

namespace model {

enum class STYLE_BORDER_WEIGHT {
  HAIRLINE = 0,
  THIN = 1,
  MEDIUM = 2,
  THICK = 3,
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_BORDER_WEIGHT_HPP */


#ifndef SIMPLE_XMLSS_MODEL_STYLE_FILL_PATTERN_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_FILL_PATTERN_HPP

//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

enum class STYLE_FILL_PATTERN {
  NONE = 0,
  SOLID = 1, //Solid
  GRAY_75 = 2, //Gray75
  GRAY_50 = 3, //Gray50
  GRAY_25 = 4, //Gray25
  GRAY_125 = 5, //Gray125
  GRAY_0625 = 6, //Gray0625
  HORZ_STRIPE = 7, //HorzStripe
  VERT_STRIPE = 8, //VertStripe
  REVERSE_DIAG_STRIPE = 9, //ReverseDiagStripe
  DIAG_STRIPE = 10, //DiagStripe
  DIAG_CROSS = 11, //DiagCross
  THICK_DIAG_CROSS = 12, //ThickDiagCross
  THIN_HORZ_STRIPE = 13, //ThinHorzStripe
  THIN_VERT_STRIPE = 14, //ThinVertStripe
  THIN_REVERSE_DIAG_STRIPE = 15, //ThinReverseDiagStripe
  THIN_DIAG_STRIPE = 16, //ThinDiagStripe
  THIN_HORZ_CROSS = 17, //ThinHorzCross
  THIN_DIAG_CROSS = 18, //ThinDiagCross
};

inline std::string to_string(const STYLE_FILL_PATTERN& a_pattern) {
  if(STYLE_FILL_PATTERN::SOLID == a_pattern) {
    return "Solid";
  }
  else if (STYLE_FILL_PATTERN::GRAY_75 == a_pattern) {
    return "Gray75";
  }
  else if (STYLE_FILL_PATTERN::GRAY_50 == a_pattern) {
    return "Gray50";
  }
  else if (STYLE_FILL_PATTERN::GRAY_25 == a_pattern) {
    return "Gray25";
  }
  else if (STYLE_FILL_PATTERN::GRAY_125 == a_pattern) {
    return "Gray125";
  }
  else if (STYLE_FILL_PATTERN::GRAY_0625 == a_pattern) {
    return "Gray0625";
  }
  else if (STYLE_FILL_PATTERN::HORZ_STRIPE == a_pattern) {
    return "HorzStripe";
  }
  else if (STYLE_FILL_PATTERN::VERT_STRIPE == a_pattern) {
    return "VertStripe";
  }
  else if (STYLE_FILL_PATTERN::REVERSE_DIAG_STRIPE == a_pattern) {
    return "ReverseDiagStripe";
  }
  else if (STYLE_FILL_PATTERN::DIAG_STRIPE == a_pattern) {
    return "DiagStripe";
  }
  else if (STYLE_FILL_PATTERN::DIAG_CROSS == a_pattern) {
    return "DiagCross";
  }
  else if (STYLE_FILL_PATTERN::THICK_DIAG_CROSS == a_pattern) {
    return "ThickDiagCross";
  }
  else if (STYLE_FILL_PATTERN::THIN_HORZ_STRIPE == a_pattern) {
    return "ThinHorzStripe";
  }
  else if (STYLE_FILL_PATTERN::THIN_VERT_STRIPE == a_pattern) {
    return "ThinVertStripe";
  }
  else if (STYLE_FILL_PATTERN::THIN_REVERSE_DIAG_STRIPE == a_pattern) {
    return "ThinReverseDiagStripe";
  }
  else if (STYLE_FILL_PATTERN::THIN_DIAG_STRIPE == a_pattern) {
    return "ThinDiagStripe";
  }
  else if (STYLE_FILL_PATTERN::THIN_HORZ_CROSS == a_pattern) {
    return "ThinHorzCross";
  }
  else if (STYLE_FILL_PATTERN::THIN_DIAG_CROSS == a_pattern) {
    return "ThinDiagCross";
  }
  return "None";
}

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_FILL_PATTERN_HPP */


#ifndef SIMPLE_XMLSS_MODEL_STYLE_NUMBER_FORMAT_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_NUMBER_FORMAT_HPP

//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

class style_number_format {
public:
  bool number_comma_flag;
  std::string format;

  style_number_format(void)
    :  number_comma_flag(false) {}

  void clear(void) {
    number_comma_flag = false;
    format.clear();
  }
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_NUMBER_FORMAT_HPP */


#ifndef SIMPLE_XMLSS_MODEL_STYLE_FILL_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_FILL_HPP

//#include "simple_xmlss_dependency.hpp"
//#include "simple_xmlss_model_style_fill_pattern.hpp"

namespace simple_xmlss {

namespace model {

class style_fill {
public:
  std::string background_color;
  std::string pattern_color;
  STYLE_FILL_PATTERN pattern;

  style_fill(void)
    : background_color(""),
      pattern_color(""),
      pattern(STYLE_FILL_PATTERN::NONE) {}

  void clear(void) {
    background_color.clear();
    pattern_color.clear();
    pattern = STYLE_FILL_PATTERN::NONE;
  }
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_FILL_HPP */


#ifndef SIMPLE_XMLSS_MODEL_STYLE_BORDER_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_BORDER_HPP

//#include "simple_xmlss_dependency.hpp"
//#include "simple_xmlss_model_style_border_position.hpp"
//#include "simple_xmlss_model_style_border_line_type.hpp"
//#include "simple_xmlss_model_style_border_weight.hpp"

namespace simple_xmlss {

namespace model {

class style_border {
public:
  STYLE_BORDER_POSITION position;
  std::string color;
  STYLE_BORDER_LINE_TYPE line_type;
  STYLE_BORDER_WEIGHT weight;

  style_border(void)
    : position(STYLE_BORDER_POSITION::NONE),
      color("#000000"),
      line_type(STYLE_BORDER_LINE_TYPE::CONTINUOUS),
      weight(STYLE_BORDER_WEIGHT::THIN) {}

  void clear(void) {
    position = STYLE_BORDER_POSITION::NONE;
    color = "#000000";
    line_type = STYLE_BORDER_LINE_TYPE::CONTINUOUS;
    weight = STYLE_BORDER_WEIGHT::THIN;
  }
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_BORDER_HPP */


#ifndef SIMPLE_XMLSS_MODEL_STYLE_BORDER_MAP_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_BORDER_MAP_HPP

//#include "simple_xmlss_model_style_border.hpp"
//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

typedef std::map<STYLE_BORDER_POSITION, style_border>  style_border_map;

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_BORDER_MAP_HPP */


#ifndef SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_HPP

//#include "simple_xmlss_model_style_number_format.hpp"
//#include "simple_xmlss_model_style_alignment_vertical.hpp"
//#include "simple_xmlss_model_style_alignment_text_control.hpp"
//#include "simple_xmlss_model_style_alignment_horizontal.hpp"

namespace simple_xmlss {

namespace model {

class style_alignment {
public:
  STYLE_ALIGNMENT_HORIZONTAL horizontal;
  unsigned int horizontal_indent;
  STYLE_ALIGNMENT_VERTICAL vertical;
  STYLE_ALIGNMENT_TEXT_CONTROL text_control;
  int rotate;

  style_alignment(void)
    : horizontal(STYLE_ALIGNMENT_HORIZONTAL::NONE),
      horizontal_indent(0),
      vertical(STYLE_ALIGNMENT_VERTICAL::NONE),
      text_control(STYLE_ALIGNMENT_TEXT_CONTROL::NONE),
      rotate(0) {}

  void clear(void) {
    horizontal = STYLE_ALIGNMENT_HORIZONTAL::NONE;
    horizontal_indent = 0;
    vertical = STYLE_ALIGNMENT_VERTICAL::NONE;
    text_control = STYLE_ALIGNMENT_TEXT_CONTROL::NONE;
    rotate = 0;
  }
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_ALIGNMENT_HPP */


#ifndef SIMPLE_XMLSS_MODEL_STYLE_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_HPP

//#include "simple_xmlss_model_style_number_format.hpp"
//#include "simple_xmlss_model_style_alignment.hpp"
//#include "simple_xmlss_model_style_border_map.hpp"
//#include "simple_xmlss_model_style_fill.hpp"

namespace simple_xmlss {

namespace model {

class style {
public:
  unsigned int id;
  style_number_format number_format;
  style_alignment alignment;
  unsigned int font_id;
  style_border_map border_map;
  style_fill fill;

  style(void)
    : id(0),
      font_id(0) {}
}; 

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_HPP */


#ifndef SIMPLE_XMLSS_MODEL_STYLE_MAP_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_MAP_HPP

//#include "simple_xmlss_model_style.hpp"
//#include "simple_xmlss_dependency.hpp"

enum PRESET_STYLE {
  E_PRESET_STYLE_DEFAULT = 0,
  E_PRESET_STYLE_HYPERLINK = 1,
  E_PRESET_STYLE_RED_BLACK = 2,
  E_PRESET_STYLE_RED_WHITE = 3,
  E_PRESET_STYLE_GREEN_BLACK = 4,
  E_PRESET_STYLE_GREEN_WHITE = 5,
  E_PRESET_STYLE_BLUE_BLACK = 6,
  E_PRESET_STYLE_BLUE_WHITE = 7,
  E_PRESET_STYLE_YELLOW_BLACK = 8,
  E_PRESET_STYLE_GRAY_BLACK = 9,
  E_PRESET_STYLE_ORANGE_BLACK = 10,
};

namespace simple_xmlss {

namespace model {

typedef std::map<unsigned int, style> style_map;

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_STYLE_MAP_HPP */


#ifndef SIMPLE_XMLSS_WRITER_STYLE_MAP_HPP
#define SIMPLE_XMLSS_WRITER_STYLE_MAP_HPP

//#include "simple_xmlss_model_style_map.hpp"
//#include "simple_xmlss_utility_inline_functions.hpp"
//#include "simple_xmlss_builder_font.hpp"

namespace simple_xmlss {

namespace writer {

class style_map {
public:
  void print_xmlss(model::style_map& a_style_map,
                   FILE* a_file) {
    print_xmlss_default(a_file);
    print_xmlss_style_map(a_style_map, a_file);
  }

private:
  void print_xmlss_default(FILE* a_file) {
    simple_xmlss_fprintf(a_file, "  <Style ss:ID=\"Default\" ss:Name=\"Normal\">\n");
    simple_xmlss_fprintf(a_file, "   <Alignment ss:Vertical=\"Center\"/>\n");
    simple_xmlss_fprintf(a_file, "   <Borders/>\n");
    simple_xmlss_fprintf(a_file, "   <Font ss:FontName=\"Tahoma\" x:CharSet=\"129\" x:Family=\"Modern\" ss:Size=\"11\" ss:Color=\"#000000\"/>\n");
    simple_xmlss_fprintf(a_file, "   <Interior/>\n");
    simple_xmlss_fprintf(a_file, "   <NumberFormat/>\n");
    simple_xmlss_fprintf(a_file, "   <Protection/>\n");
    simple_xmlss_fprintf(a_file, "  </Style>\n");
    simple_xmlss_fprintf(a_file, "  <Style ss:ID=\"s_num_comma\">\n");
    simple_xmlss_fprintf(a_file, "   <NumberFormat ss:Format=\"_-* #,##0_-;\\-* #,##0_-;_-* &quot;-&quot;_-;_-@_-\"/>\n");
    simple_xmlss_fprintf(a_file, "  </Style>\n");
  }

  void print_xmlss_style_map(model::style_map& a_style_map,
                             FILE* a_file) {
    for(auto& iter : a_style_map) {
      print_xmlss_style(iter.second, a_file);
    }
  }

  void print_xmlss_style(const model::style& a_style,
                         FILE* a_file) {
    simple_xmlss_fprintf(a_file, "  <Style ss:ID=\"%s\"", utility::get_style_id_string(a_style.id).c_str());
    if (true == a_style.number_format.number_comma_flag) {
      simple_xmlss_fprintf(a_file, " ss:Parent=\"s_num_comma\"");
    }
    simple_xmlss_fprintf(a_file, ">\n");

    print_xmlss_style_alignment(a_style.alignment, a_file);
    print_xmlss_style_border_map(a_style.border_map, a_file);
    builder::font::instance().print_xmlss(a_file, a_style.font_id);
    print_xmlss_style_fill(a_style.fill, a_file);
    print_xmlss_style_number_format(a_style.number_format, a_file);
    simple_xmlss_fprintf(a_file, "  </Style>\n");
  }

  void print_xmlss_style_number_format(const model::style_number_format& a_number_format,
                                       FILE *a_file) {
    if(0 < a_number_format.format.size()) {
      simple_xmlss_fprintf(a_file, "   <NumberFormat ss:Format=\"%s\"/>\n", utility::std_string2xml_string(a_number_format.format).c_str());
    }
  }

  void print_xmlss_style_fill(const model::style_fill& a_fill,
                              FILE *a_file) {
    if(0 == a_fill.background_color.size() &&
       0 == a_fill.pattern_color.size() &&
       model::STYLE_FILL_PATTERN::NONE == a_fill.pattern) {
      return;
    }

    simple_xmlss_fprintf(a_file, "   <Interior");
    if( 0 < a_fill.background_color.size()) {
      simple_xmlss_fprintf(a_file, " ss:Color=\"%s\"", a_fill.background_color.c_str());
    }
    if(model::STYLE_FILL_PATTERN::NONE != a_fill.pattern) {
      simple_xmlss_fprintf(a_file, " ss:Pattern=\"%s\"", model::to_string(a_fill.pattern).c_str());
    }
    if( 0 < a_fill.pattern_color.size()) {
      simple_xmlss_fprintf(a_file, " ss:PatternColor=\"%s\"", a_fill.pattern_color.c_str());
    }
    simple_xmlss_fprintf(a_file, "/>\n");
  }

  void print_xmlss_style_border_map(const model::style_border_map& a_border_map,
                                    FILE *a_file) {
    if (0 >= a_border_map.size()) {
      simple_xmlss_fprintf(a_file, "   <Borders/>\n");
    } 
    else {
      simple_xmlss_fprintf(a_file, "   <Borders>\n");
      for (auto& iter : a_border_map) {
        print_xmlss_style_border(iter.second, a_file);
      }
      simple_xmlss_fprintf(a_file, "   </Borders>\n");
    }
  }

  void print_xmlss_style_border(const model::style_border& a_border,
                                FILE* a_file) {
    if (model::STYLE_BORDER_POSITION::NONE == a_border.position) {
      return;
    }

    simple_xmlss_fprintf(a_file, "    <Border ss:Position=\"%s\" ss:Color=\"%s\" ss:LineStyle=\"%s\" ss:Weight=\"%d\"/>\n",
                model::to_string(a_border.position).c_str(),
                a_border.color.c_str(),
                model::to_string(a_border.line_type).c_str(),
                (int)a_border.weight);
  }

  void print_xmlss_style_alignment(const model::style_alignment& a_alignment,
                                   FILE *a_file) {
    simple_xmlss_fprintf(a_file, "   <Alignment");
    print_xmlss_style_alignment_rotate(a_alignment.rotate, a_file);
    print_xmlss_style_text_control(a_alignment.text_control, a_file);
    print_xmlss_style_horizontal(a_alignment.horizontal, a_file);
    print_xmlss_style_horizontal_indent(a_alignment.horizontal_indent, a_alignment.horizontal, a_file);
    print_xmlss_style_vertical(a_alignment.vertical, a_file);
    simple_xmlss_fprintf(a_file, "/>\n");
  }

  void print_xmlss_style_alignment_rotate(const unsigned int a_rotate,
                                          FILE *a_file) {
    if (0 != a_rotate) {
      simple_xmlss_fprintf(a_file, " ss:Rotate=\"%d\"", a_rotate);
    }
  }

  void print_xmlss_style_text_control(const model::STYLE_ALIGNMENT_TEXT_CONTROL& a_text_control,
                                      FILE* a_file) {
    if(model::STYLE_ALIGNMENT_TEXT_CONTROL::NONE == a_text_control) {
      return;
    }
    simple_xmlss_fprintf(a_file, " ss:%s=\"1\"", model::to_string(a_text_control).c_str());
  }

  void print_xmlss_style_horizontal(const model::STYLE_ALIGNMENT_HORIZONTAL& a_horizontal,
                                    FILE* a_file) {
    if (model::STYLE_ALIGNMENT_HORIZONTAL::NONE == a_horizontal) {
      return;
    }
    simple_xmlss_fprintf(a_file, " ss:Horizontal=\"%s\"", model::to_string(a_horizontal).c_str());
  }

  void print_xmlss_style_horizontal_indent(const unsigned int a_horizontal_indent,
                                           const model::STYLE_ALIGNMENT_HORIZONTAL& a_horizontal,
                                           FILE* a_file) {
    if(0 == a_horizontal_indent) {
      return;
    }

    if(model::STYLE_ALIGNMENT_HORIZONTAL::LEFT == a_horizontal ||
       model::STYLE_ALIGNMENT_HORIZONTAL::RIGHT == a_horizontal ||
       model::STYLE_ALIGNMENT_HORIZONTAL::DISTRIBUTED == a_horizontal) {
      simple_xmlss_fprintf(a_file,  " ss:Indent=\"%u\"", a_horizontal_indent);
    }
  }

  void print_xmlss_style_vertical(const model::STYLE_ALIGNMENT_VERTICAL& a_vertical,
                                  FILE* a_file) {
    if (model::STYLE_ALIGNMENT_VERTICAL::NONE == a_vertical) {
      return;
    }
    simple_xmlss_fprintf(a_file, " ss:Vertical=\"%s\"", model::to_string(a_vertical).c_str());
  }
};

} // namespace writer

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_WRITER_STYLE_MAP_HPP */



#ifndef SIMPLE_XMLSS_API_STYLE_MAP_HPP
#define SIMPLE_XMLSS_API_STYLE_MAP_HPP

//#include "simple_xmlss_model_style_map.hpp"
//#include "simple_xmlss_utility_trace.hpp"
//#include "simple_xmlss_utility_error.hpp"
//#include "simple_xmlss_utility_error_handler.hpp"

namespace simple_xmlss {

namespace api {

class style_map {
public:
  void initialize(model::style_map& a_style_map) {
    a_style_map.clear();

    clear();
    build(a_style_map, E_PRESET_STYLE_DEFAULT);

    clear();
    set_fill_background_color("#FFFFFF");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_HYPERLINK);
    build(a_style_map, E_PRESET_STYLE_HYPERLINK);

    clear();
    set_fill_background_color("#FF0000");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_BLACK);
    build(a_style_map, E_PRESET_STYLE_RED_BLACK);

    clear();
    set_fill_background_color("#FF0000");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_WHITE);
    build(a_style_map, E_PRESET_STYLE_RED_WHITE);

    clear();
    set_fill_background_color("#00FF00");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_BLACK);
    build(a_style_map, E_PRESET_STYLE_GREEN_BLACK);

    clear();
    set_fill_background_color("#00FF00");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_WHITE);
    build(a_style_map, E_PRESET_STYLE_GREEN_WHITE);

    clear();
    set_fill_background_color("#0000FF");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_BLACK);
    build(a_style_map, E_PRESET_STYLE_BLUE_BLACK);

    clear();
    set_fill_background_color("#0000FF");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_WHITE);
    build(a_style_map, E_PRESET_STYLE_BLUE_WHITE);

    clear();
    set_fill_background_color("#FFFF00");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_BLACK);
    build(a_style_map, E_PRESET_STYLE_YELLOW_BLACK);

    clear();
    set_fill_background_color("#A6A6A6");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_BLACK);
    build(a_style_map, E_PRESET_STYLE_GRAY_BLACK);

    clear();
    set_fill_background_color("#FFC000");
    set_fill_pattern_style(model::STYLE_FILL_PATTERN::SOLID);
    set_font_id(E_PRESET_FONT_BLACK);
    build(a_style_map, E_PRESET_STYLE_ORANGE_BLACK);

    clear();
  }

  unsigned int build(model::style_map& a_style_map) {
    unsigned int return_value = a_style_map.size();
    m_style.id = return_value;
    a_style_map.insert(std::make_pair(return_value, m_style));
    return return_value;
  }

  void clear(void) {
    m_style.id = 0;
    m_style.number_format.clear();
    m_style.alignment.clear();
    m_style.font_id = 0;
    m_style.border_map.clear();
    m_style.fill.clear();
  }

  //number format
  void set_number_format(const std::string& a_format) {
    m_style.number_format.format = a_format;
  }

  void set_number_comma(const bool a_number_comma_flag) {
    m_style.number_format.number_comma_flag = a_number_comma_flag;
  }

  //alignment
  void set_alignment_horizontal(const model::STYLE_ALIGNMENT_HORIZONTAL a_horizontal) {
    m_style.alignment.horizontal = a_horizontal;
  }

  void set_alignment_horizontal_indent(const unsigned int a_indent) {
    m_style.alignment.horizontal_indent = a_indent;
  }

  void set_alignment_vertical(const model::STYLE_ALIGNMENT_VERTICAL a_vertical) {
    m_style.alignment.vertical = a_vertical;
  }

  void set_alignment_text_control(const model::STYLE_ALIGNMENT_TEXT_CONTROL a_text_control) {
    m_style.alignment.text_control = a_text_control;
  }

  void set_alignment_rotate(const int a_rotate,
                            const utility::trace& a_trace) {
    if(90 < a_rotate || -90 > a_rotate) {
      utility::error new_error(a_trace.file_name,
                               a_trace.function_name,
                               std::to_string(a_trace.line),
                               "N/A",
                               "N/A",
                               "N/A",
                               "N/A",
                               "Wrong rotate value["+
                               std::to_string(a_rotate)+
                               "]. The rotate value must be a number between -90 and 90.");
      utility::error_handler::instance().handling_error(new_error);
    }
    m_style.alignment.rotate = a_rotate;
  }

  //font
  void set_font_id(const unsigned int a_font_id) {
    m_style.font_id = a_font_id;
  }

  //boarders
  void set_default_borders(void) {
    m_style.border_map.clear();
  }

  void set_border_color(const model::STYLE_BORDER_POSITION a_position, const std::string &a_color) {
    m_style.border_map[a_position].position = a_position;
    m_style.border_map[a_position].color = a_color;
  }

  void set_border_line_type(const model::STYLE_BORDER_POSITION a_position, const model::STYLE_BORDER_LINE_TYPE a_line_type) {
    m_style.border_map[a_position].position = a_position;
    m_style.border_map[a_position].line_type = a_line_type;
  }

  void set_border_weight(const model::STYLE_BORDER_POSITION a_position, const model::STYLE_BORDER_WEIGHT a_weight) {
    m_style.border_map[a_position].position = a_position;
    m_style.border_map[a_position].weight = a_weight;
  }

  //fill
  void set_fill_background_color(const std::string& a_color) {
    m_style.fill.background_color = a_color;
  }

  void set_fill_pattern_color(const std::string& a_color) {
    m_style.fill.pattern_color = a_color;
  }

  void set_fill_pattern_style(model::STYLE_FILL_PATTERN a_pattern) {
    m_style.fill.pattern = a_pattern;
  }

  unsigned int get_font_id(model::style_map& a_style_map,
                           const unsigned int a_style_id) {
    auto iter = a_style_map.find(a_style_id);
    if(a_style_map.end() != iter) {
      return iter->second.font_id;
    }
    return 0;
  }

private:
  void build(model::style_map& a_style_map, const unsigned int a_style_id) {
    m_style.id = a_style_id;
    a_style_map.insert(std::make_pair(a_style_id, m_style));
  }

  model::style  m_style;
};

} // namespace api

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_API_STYLE_MAP_HPP */


#ifndef SIMPLE_XMLSS_BUILDER_STYLE_HPP
#define SIMPLE_XMLSS_BUILDER_STYLE_HPP

//#include "simple_xmlss_model_style_map.hpp"
//#include "simple_xmlss_api_style_map.hpp"
//#include "simple_xmlss_writer_style_map.hpp"

namespace simple_xmlss {

namespace builder {

class style {
public:
  static style&  instance(void) {
    static style singleton_instance;
    return singleton_instance;
  }

  void initialize(void) {
    m_api.initialize(m_model);
  }

  unsigned int build(void) {
    return m_api.build(m_model);
  }

  style& clear(void) {
    m_api.clear();
    return (*this);
}

//number format
style& set_number_format(const std::string& a_format) {
  m_api.set_number_format(a_format);
  return (*this);
}

style& set_number_comma(const bool a_number_comma_flag) {
  m_api.set_number_comma(a_number_comma_flag);
  return (*this);
}

//alignment
style& set_alignment_horizontal(const model::STYLE_ALIGNMENT_HORIZONTAL a_horizontal) {
  m_api.set_alignment_horizontal(a_horizontal);
  return (*this);
}

style& set_alignment_horizontal_indent(const unsigned int a_indent) {
  m_api.set_alignment_horizontal_indent(a_indent);
  return (*this);
}

style& set_alignment_vertical(const model::STYLE_ALIGNMENT_VERTICAL a_vertical) {
  m_api.set_alignment_vertical(a_vertical);
  return (*this);
}

style& set_alignment_text_control(const model::STYLE_ALIGNMENT_TEXT_CONTROL a_text_control) {
  m_api.set_alignment_text_control(a_text_control);
  return (*this);
}

style& set_alignment_rotate(const int a_rotate,
                            const utility::trace& a_trace = utility::trace()) {
  m_api.set_alignment_rotate(a_rotate,
                             a_trace);
  return (*this);
}

//font
style& set_font_id(const unsigned int a_font_id) {
  m_api.set_font_id(a_font_id);
  return (*this);
}

//boarders
style& set_default_borders(void) {
  m_api.set_default_borders();
  return (*this);
}

style& set_border_color(const model::STYLE_BORDER_POSITION a_position,
                        const std::string &a_color) {
  m_api.set_border_color(a_position,
                         a_color);
  return (*this);
}

style& set_border_line_type(const model::STYLE_BORDER_POSITION a_position,
                            const model::STYLE_BORDER_LINE_TYPE a_line_type) {
  m_api.set_border_line_type(a_position, a_line_type);
  return (*this);
}

style& set_border_weight(const model::STYLE_BORDER_POSITION a_position,
                         const model::STYLE_BORDER_WEIGHT a_weight) {
  m_api.set_border_weight(a_position, a_weight);
  return (*this);
}

//fill
style& set_fill_background_color(const std::string& a_color) {
  m_api.set_fill_background_color(a_color);
  return (*this);
}

style& set_fill_pattern_color(const std::string& a_color) {
  m_api.set_fill_pattern_color(a_color);
  return (*this);
}

style& set_fill_pattern_style(model::STYLE_FILL_PATTERN a_pattern) {
  m_api.set_fill_pattern_style(a_pattern);
  return (*this);
}

unsigned int get_font_id(const unsigned int a_style_id) {
  return m_api.get_font_id(m_model, a_style_id);
}

void print_xmlss(FILE* a_file) {
  m_writer.print_xmlss(m_model, a_file);
}

private:
  style(void) {
    initialize();
  }

  model::style_map m_model;
  api::style_map m_api;
  writer::style_map m_writer;
};

} // namespace builder

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_BUILDER_STYLE_HPP */


#ifndef SIMPLE_XMLSS_MODEL_CELL_COORDINATE_HPP
#define SIMPLE_XMLSS_MODEL_CELL_COORDINATE_HPP

namespace simple_xmlss {

namespace model {

class cell_coordinate {
public:
  unsigned int col;
  unsigned int row;

  cell_coordinate(void) 
    : col(0),
      row(0) {}
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_CELL_COORDINATE_HPP */


#ifndef SIMPLE_XMLSS_MODEL_CELL_FONT_STRING_HPP
#define SIMPLE_XMLSS_MODEL_CELL_FONT_STRING_HPP

//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

class cell_font_string {
public:
  unsigned int font_id;
  std::string contents;

  cell_font_string(void)
    : font_id(0) {}
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_CELL_FONT_STRING_HPP */


#ifndef SIMPLE_XMLSS_MODEL_CELL_STATUS_FLAG_HPP
#define SIMPLE_XMLSS_MODEL_CELL_STATUS_FLAG_HPP

namespace simple_xmlss {

namespace model {

class cell_status_flag {
public:
  bool string_flag;
  bool number_flag;
  bool date_time_flag;
  bool formula_flag;
  bool comment_flag;
  bool hyperlink_flag;
  bool style_flag;

  cell_status_flag(void)
    : string_flag(false),
      number_flag(false),
      date_time_flag(false),
      formula_flag(false),
      comment_flag(false),
      hyperlink_flag(false),
      style_flag(false) {}
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_CELL_STATUS_FLAG_HPP */


#ifndef SIMPLE_XMLSS_MODEL_CELL_STRING_HPP
#define SIMPLE_XMLSS_MODEL_CELL_STRING_HPP

//#include "simple_xmlss_model_cell_font_string.hpp"
//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

typedef std::list<cell_font_string> cell_string;

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_CELL_STRING_HPP */


#ifndef SIMPLE_XMLSS_MODEL_CELL_COMMENT_HPP
#define SIMPLE_XMLSS_MODEL_CELL_COMMENT_HPP

//#include "simple_xmlss_model_cell_string.hpp"
//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

class cell_comment {
public:
    cell_font_string author;
    cell_string string;
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_CELL_COMMENT_HPP */


#ifndef SIMPLE_XMLSS_MODEL_CELL_CONFIGURATION_HPP
#define SIMPLE_XMLSS_MODEL_CELL_CONFIGURATION_HPP

//#include "simple_xmlss_model_cell_coordinate.h"

namespace simple_xmlss {

namespace model {

class cell_configuration {
public:
  //book, sheet information
  std::string book_name;
  std::string sheet_name;

  //current coordinate
  cell_coordinate coordinate;

  //merge configuration
  unsigned int merge_across;
  unsigned int merge_down;
  bool merge_flag;
  cell_coordinate merge_origin;

  cell_configuration(void)
    : book_name("Default"),
      sheet_name("Default"),
      coordinate(cell_coordinate()),
      merge_across(0),
      merge_down(0),
      merge_flag(false),
      merge_origin(cell_coordinate()) {}
      
  void debug_print(void) const {
    printf("<<cell_configuration>>\n");
    printf("book_name: %s", book_name.c_str());
    printf("sheet_name: %s", sheet_name.c_str());
    printf("coordinate: [row:%u,col:%u]\n", coordinate.col, coordinate.row);
    printf("merge_across: %u\n", merge_across);
    printf("merge_down: %u\n", merge_down);
    printf("merge_flag: %s\n", (true == merge_flag)?"true":"false");
    printf("merge_origin: [row:%u,col:%u]\n\n", merge_origin.col, merge_origin.row);
  }
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_CELL_CONFIGURATION_HPP */


#ifndef SIMPLE_XMLSS_MODEL_CELL_HPP
#define SIMPLE_XMLSS_MODEL_CELL_HPP

//#include "simple_xmlss_model_cell_string.hpp"
//#include "simple_xmlss_model_cell_comment.hpp"
//#include "simple_xmlss_model_cell_configuration.hpp"
//#include "simple_xmlss_model_cell_status_flag.hpp"

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


#ifndef SIMPLE_XMLSS_WRITER_CELL_HPP
#define SIMPLE_XMLSS_WRITER_CELL_HPP

//#include "simple_xmlss_model_cell.hpp"
//#include "simple_xmlss_utility_inline_functions.hpp"
//#include "simple_xmlss_builder_font.hpp"
//#include "simple_xmlss_builder_style.hpp"

namespace simple_xmlss {

namespace writer {

class cell {
public:
  void print_xmlss(model::cell& a_cell,
                   FILE* a_file) {
    if (true == a_cell.configuration.merge_flag) {
      return;
    }

    if (false == a_cell.status_flag.string_flag &&
        false == a_cell.status_flag.number_flag &&
        false == a_cell.status_flag.date_time_flag &&
        false == a_cell.status_flag.formula_flag &&
        false == a_cell.status_flag.comment_flag &&
        false == a_cell.status_flag.hyperlink_flag &&
        false == a_cell.status_flag.style_flag) {
      return;
    }

    simple_xmlss_fprintf(a_file, "    <Cell ss:Index=\"%u\"", a_cell.configuration.coordinate.col );
    
    if (0 != a_cell.style_id) {
      simple_xmlss_fprintf(a_file, " ss:StyleID=\"%s\"", utility::get_style_id_string(a_cell.style_id).c_str());
    }
      
    if (true == a_cell.status_flag.hyperlink_flag) {
      simple_xmlss_fprintf(a_file, " ss:HRef=\"%s\"", utility::std_string2xml_string(a_cell.hyperlink).c_str());
    }

    if (0 < a_cell.configuration.merge_across) {
      simple_xmlss_fprintf(a_file, " ss:MergeAcross=\"%u\"", a_cell.configuration.merge_across);
    }

    if (0 < a_cell.configuration.merge_down) {
      simple_xmlss_fprintf(a_file, " ss:MergeDown=\"%u\"", a_cell.configuration.merge_down);
    }

    if (true == a_cell.status_flag.formula_flag) {
      simple_xmlss_fprintf(a_file, " ss:Formula=\"%s\"", utility::std_string2xml_string(a_cell.formula).c_str());
    }

    simple_xmlss_fprintf(a_file, ">");
    if (true == a_cell.status_flag.string_flag) {
      print_xmlss_cell_string(a_cell, a_file);
    }
    else if (true == a_cell.status_flag.number_flag) {
      simple_xmlss_fprintf(a_file, "<Data ss:Type=\"Number\">%s</Data>", a_cell.number.c_str()); 
    }
    else if (true == a_cell.status_flag.date_time_flag) {
      simple_xmlss_fprintf(a_file, "<Data ss:Type=\"DateTime\">%s</Data>", a_cell.date_time.c_str()); 
    }

    if (true == a_cell.status_flag.comment_flag) {
      print_node_comment(a_cell, a_file);
    }
    simple_xmlss_fprintf(a_file, "</Cell>\n");
  }

private:
  void print_xmlss_cell_string(model::cell& a_cell,
                               FILE* a_file) {
    if(false == is_valid_font(a_cell.string)) {
      simple_xmlss_fprintf(a_file, "<Data ss:Type=\"String\">%s</Data>", get_cell_string(a_cell.string).c_str());
    }
    else {
      simple_xmlss_fprintf(a_file, "<ss:Data ss:Type=\"String\" xmlns=\"http://www.w3.org/TR/REC-html40\">");
      unsigned int font_id_defined_in_the_style = builder::style::instance().get_font_id(a_cell.style_id);
      for(auto& iter : a_cell.string) {
        if(0==iter.font_id && 0==font_id_defined_in_the_style) {
          simple_xmlss_fprintf(a_file, "<Font>%s</Font>", iter.contents.c_str());
        }
        else {
          print_xmlss_cell_font_string(iter, font_id_defined_in_the_style, true, a_file);
        }
      }
      simple_xmlss_fprintf(a_file, "</ss:Data>");
    }
  }

  void print_xmlss_cell_font_string(const model::cell_font_string& a_cell_font_string,
                                    unsigned int a_font_id_defined_in_the_style,
                                    const bool a_accounting_flag,
                                    FILE* a_file) {
    unsigned int current_font_id = (0!=a_cell_font_string.font_id)?a_cell_font_string.font_id:a_font_id_defined_in_the_style;
    const model::font& current_font = builder::font::instance().get_font(current_font_id);
    print_xmlss_cell_font_string_open_bold(current_font, a_file);
    print_xmlss_cell_font_string_open_italic(current_font, a_file);
    print_xmlss_cell_font_string_open_underline(current_font, a_accounting_flag, a_file);
    print_xmlss_cell_font_string_open_strikethrough(current_font, a_file);
    print_xmlss_cell_font_string_open_superscript_subscript(current_font, a_file);
    print_xmlss_cell_font_string_open_font(current_font, a_file);
    simple_xmlss_fprintf(a_file, "%s", utility::std_string2xml_string(a_cell_font_string.contents).c_str());
    print_xmlss_cell_font_string_close_font(a_file);
    print_xmlss_cell_font_string_close_superscript_subscript(current_font, a_file);
    print_xmlss_cell_font_string_close_strikethrough(current_font, a_file);
    print_xmlss_cell_font_string_close_underline(current_font, a_file);
    print_xmlss_cell_font_string_close_italic(current_font, a_file);
    print_xmlss_cell_font_string_close_bold(current_font, a_file);
  }

  void print_xmlss_cell_font_string_open_bold(const model::font& a_font,
                                              FILE* a_file) {
    if(true == a_font.bold) {
      simple_xmlss_fprintf(a_file, "<B>");
    }
  }

  void print_xmlss_cell_font_string_close_bold(const model::font& a_font,
                                               FILE* a_file) {
    if(true == a_font.bold) {
      simple_xmlss_fprintf(a_file, "</B>");
    }
  }

  void print_xmlss_cell_font_string_open_italic(const model::font& a_font,
                                                FILE* a_file) {
    if(true == a_font.italic) {
      simple_xmlss_fprintf(a_file, "<I>");
    }
  }

  void print_xmlss_cell_font_string_close_italic(const model::font& a_font,
                                                 FILE* a_file) {
    if(true == a_font.italic) {
      simple_xmlss_fprintf(a_file, "</I>");
    }
  }

  void print_xmlss_cell_font_string_open_font(const model::font& a_font,
                                              FILE* a_file) {
    simple_xmlss_fprintf(a_file, "<Font");
    if(0 < a_font.name.size()) {
      simple_xmlss_fprintf(a_file, " html:Face=\"%s\"", a_font.name.c_str()); 
    }
    if(model::FONT_CHAR_SET::NONE != a_font.char_set) {
      simple_xmlss_fprintf(a_file, " x:CharSet=\"%d\"", (int)a_font.char_set);
    }
    if(0 < a_font.family_name.size()) {
      simple_xmlss_fprintf(a_file, " x:Family=\"%s\"", a_font.family_name.c_str());
    }
    if(0 < a_font.size) {
      simple_xmlss_fprintf(a_file, " html:Size=\"%u\"", a_font.size);
    }
    if(0 < a_font.color.size()) {
      simple_xmlss_fprintf(a_file, " html:Color=\"%s\"", a_font.color.c_str());
    }
    simple_xmlss_fprintf(a_file, ">");
  }

  void print_xmlss_cell_font_string_close_font(FILE* a_file) {
    simple_xmlss_fprintf(a_file, "</Font>");
  }

  void print_xmlss_cell_font_string_open_underline(const model::font& a_font,
                                                   const bool a_accounting_flag,
                                                  FILE* a_file) {
    if(model::FONT_UNDERLINE::NONE == a_font.underline) {
      return;
    }

    simple_xmlss_fprintf(a_file, "<U");
    if(model::FONT_UNDERLINE::SINGLE == a_font.underline);
    else if (model::FONT_UNDERLINE::DOUBLE == a_font.underline) {
      simple_xmlss_fprintf(a_file, " html:Style=\"text-underline:double\"");
    }
    else if (model::FONT_UNDERLINE::SINGLE_ACCOUNTING == a_font.underline && true == a_accounting_flag) {
      simple_xmlss_fprintf(a_file, " html:Style=\"text-underline:single-accounting\"");
    }
    else if (model::FONT_UNDERLINE::DOUBLE_ACCOUNTING == a_font.underline && true == a_accounting_flag) {
      simple_xmlss_fprintf(a_file, " html:Style=\"text-underline:double-accounting\"");
    }
    simple_xmlss_fprintf(a_file, ">");
  }

  void print_xmlss_cell_font_string_close_underline(const model::font& a_font,
                                                    FILE* a_file) {
    if(model::FONT_UNDERLINE::NONE == a_font.underline) {
      return;
    }

    simple_xmlss_fprintf(a_file, "</U>");
  }

  void print_xmlss_cell_font_string_open_strikethrough(const model::font& a_font,
                                                       FILE* a_file) {
    if(true == a_font.strikethrough) {
      simple_xmlss_fprintf(a_file, "<S>");
    }
  }

  void print_xmlss_cell_font_string_close_strikethrough(const model::font& a_font,
                                                        FILE* a_file) {
    if(true == a_font.strikethrough) {
      simple_xmlss_fprintf(a_file, "</S>");
    }
  }

  void print_xmlss_cell_font_string_open_superscript_subscript(const model::font& a_font,
                                                               FILE* a_file) {
    if(model::FONT_SUPERSCRIPT_SUBSCRIPT::NONE == a_font.superscript_subscript) {
      return;
    }
    else if(model::FONT_SUPERSCRIPT_SUBSCRIPT::SUPERSCRIPT == a_font.superscript_subscript) {
      simple_xmlss_fprintf(a_file, "<Sup>");
    }
    else if(model::FONT_SUPERSCRIPT_SUBSCRIPT::SUBSCRIPT == a_font.superscript_subscript) {
      simple_xmlss_fprintf(a_file, "<Sub>");
    }
  }

  void print_xmlss_cell_font_string_close_superscript_subscript(const model::font& a_font,
                                                                FILE* a_file) {
    if(model::FONT_SUPERSCRIPT_SUBSCRIPT::NONE == a_font.superscript_subscript) {
      return;
    }
    else if(model::FONT_SUPERSCRIPT_SUBSCRIPT::SUPERSCRIPT == a_font.superscript_subscript) {
      simple_xmlss_fprintf(a_file, "</Sup>");
    }
    else if(model::FONT_SUPERSCRIPT_SUBSCRIPT::SUBSCRIPT == a_font.superscript_subscript) {
      simple_xmlss_fprintf(a_file, "</Sub>");
    }
  }

  std::string get_cell_string(const model::cell_string& a_cell_string) {
    std::string return_value;
    for(auto& iter : a_cell_string) {
      return_value += iter.contents;
    }
    return utility::std_string2xml_string(return_value);
  }

  bool is_valid_font(const model::cell_string& a_cell_string) {
    for(auto& iter : a_cell_string) {
      if(0!=iter.font_id) {
        return true;
      }
    }
    return false;
  }

  void print_node_comment(model::cell& a_cell,
                          FILE* a_file) {
    simple_xmlss_fprintf(a_file, "<Comment");
    print_node_comment_author1(a_cell, a_file);
    simple_xmlss_fprintf(a_file, ">");
    simple_xmlss_fprintf(a_file, "<ss:Data xmlns=\"http://www.w3.org/TR/REC-html40\">");
    print_node_comment_author2(a_cell, a_file);
    print_node_comment_string(a_cell, a_file);
    simple_xmlss_fprintf(a_file, "</ss:Data></Comment>");
  }

  void print_node_comment_author1(model::cell& a_cell,
                                  FILE* a_file) {
    if(0 < a_cell.comment.author.contents.size()) {
      simple_xmlss_fprintf(a_file, " ss:Author=\"%s\"", a_cell.comment.author.contents.c_str());
    }
  }

  void print_node_comment_author2(model::cell& a_cell,
                                  FILE* a_file) {
    if(0 >= a_cell.comment.author.contents.size()) {
      return;
    }
    model::cell_font_string current_comment_author;
    current_comment_author = a_cell.comment.author;
    current_comment_author.contents += ":\n";
    print_xmlss_cell_font_string(current_comment_author, 0, false, a_file);
  }

  void print_node_comment_string(model::cell& a_cell,
                                 FILE* a_file) {
    if(false == is_valid_font(a_cell.comment.string)) {
      simple_xmlss_fprintf(a_file, "<Data ss:Type=\"String\">%s</Data>", get_cell_string(a_cell.comment.string).c_str());
    }
    else {
      simple_xmlss_fprintf(a_file, "<ss:Data ss:Type=\"String\" xmlns=\"http://www.w3.org/TR/REC-html40\">");
      for(auto& iter : a_cell.comment.string) {
        if(0==iter.font_id) {
          simple_xmlss_fprintf(a_file, "<Font>%s</Font>", iter.contents.c_str());
        }
        else {
          print_xmlss_cell_font_string(iter, 0, false, a_file);
        }
      }
      simple_xmlss_fprintf(a_file, "</ss:Data>");
    }
  }
};

} // namespace writer

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_WRITER_CELL_HPP */


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


#ifndef SIMPLE_XMLSS_API_CELL_HPP
#define SIMPLE_XMLSS_API_CELL_HPP

//#include "simple_xmlss_model_cell.hpp"
//#include "simple_xmlss_utility_trace.hpp"
//#include "simple_xmlss_utility_inline_functions.hpp"
//#include "simple_xmlss_utility_error.hpp"
//#include "simple_xmlss_utility_error_handler.hpp"
//#include "simple_xmlss_api_cell_macro_functions.hpp"

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


#ifndef SIMPLE_XMLSS_CELL_HPP
#define SIMPLE_XMLSS_CELL_HPP

//#include "simple_xmlss_api_cell.hpp"
//#include "simple_xmlss_writer_cell.hpp"
//#include "simple_xmlss_model_cell.hpp"

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


#ifndef SIMPLE_XMLSS_BUILDER_STRING_HPP
#define SIMPLE_XMLSS_BUILDER_STRING_HPP

//#include "simple_xmlss_model_cell_string.hpp"

namespace simple_xmlss {

namespace builder {

class string {
public:  
  static string&  instance(void) {
    static string singleton_instance;
    return singleton_instance;
  }

  const model::cell_string& build(void) {
    return m_cell_string;
  }

  string& clear(void) {
    m_cell_string.clear();
    return (*this);
  }

  string& set_string(const std::string& a_string) {
    return set_string(a_string,0);
  }

  string& set_string(const std::string& a_string,
                     const unsigned int a_font_id) {
    model::cell_font_string new_cell_font_string;
    new_cell_font_string.contents = a_string;
    new_cell_font_string.font_id = a_font_id;
    m_cell_string.push_back(new_cell_font_string);
    return (*this);
  }

private:
  string(void) {
    clear();
  }

  model::cell_string m_cell_string;
};

} // namespace builder

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_BUILDER_STRING_HPP */


#ifndef SIMPLE_XMLSS_BUILDER_COMMENT_HPP
#define SIMPLE_XMLSS_BUILDER_COMMENT_HPP

//#include "simple_xmlss_model_cell_comment.hpp"
//#include "simple_xmlss_utility_trace.hpp"
//#include "simple_xmlss_utility_error.hpp"
//#include "simple_xmlss_utility_error_handler.hpp"

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


#ifndef SIMPLE_XMLSS_MODEL_SHEET_CONFIGURATION_HPP
#define SIMPLE_XMLSS_MODEL_SHEET_CONFIGURATION_HPP

//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

class sheet_configuration {
public:
  const std::string book_name;
  const std::string sheet_name;

  sheet_configuration(const std::string& a_book_name,
                      const std::string& a_sheet_name)
    : book_name(a_book_name),
      sheet_name(a_sheet_name) {}
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_SHEET_CONFIGURATION_HPP */


#ifndef SIMPLE_XMLSS_MODEL_SHEET_CELL_SIZE_MAP
#define SIMPLE_XMLSS_MODEL_SHEET_CELL_SIZE_MAP

//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

typedef std::map<const unsigned int, float> sheet_cell_size_map;

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_SHEET_CELL_SIZE_MAP */


#ifndef SIMPLE_XMLSS_MODEL_SHEET_COORDINATE_HPP
#define SIMPLE_XMLSS_MODEL_SHEET_COORDINATE_HPP

namespace simple_xmlss {

namespace model {

class sheet_coordinate {
public:
  unsigned int max_col;
  unsigned int max_row;
  unsigned int current_col;
  unsigned int current_row;

  sheet_coordinate(void)
    : max_col(1),
      max_row(1),
      current_col(1),
      current_row(1) {}
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_SHEET_COORDINATE_HPP */


#ifndef SIMPLE_XMLSS_MODEL_SHEET_TAB_COLOR_HPP
#define SIMPLE_XMLSS_MODEL_SHEET_TAB_COLOR_HPP

namespace simple_xmlss {

namespace model {

enum class SHEET_TAB_COLOR {
  DEFAULT = -1,
  BLACK = 0,
  RED = 2,     // R
  LIME = 3,    // G
  BLUE = 4,    // B
  YELLOW = 5,  //#FFFF00
  MAGENTA = 6, //#FF00FF
  CYAN = 7,    //#00FFFF
  MAROON = 16, //#800000
  GREEN = 17,  //#008000
  NAVY = 18,   //#000080
  ORANGE = 53,
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_SHEET_TAB_COLOR_HPP */


#ifndef SIMPLE_XMLSS_MODEL_SHEET_CELL_MAP_HPP
#define SIMPLE_XMLSS_MODEL_SHEET_CELL_MAP_HPP

//#include "simple_xmlss_cell.hpp"
//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

typedef std::map<unsigned int, simple_xmlss::cell> column_to_cell_map;
typedef std::map<unsigned int, column_to_cell_map> row_to_column_map;
typedef row_to_column_map sheet_cell_map;

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_SHEET_CELL_MAP_HPP */


#ifndef SIMPLE_XMLSS_MODEL_SHEET_HPP
#define SIMPLE_XMLSS_MODEL_SHEET_HPP

//#include "simple_xmlss_model_sheet_cell_map.hpp"
//#include "simple_xmlss_model_sheet_tab_color.hpp"
//#include "simple_xmlss_model_sheet_cell_size_map.hpp"
//#include "simple_xmlss_model_sheet_coordinate.hpp"
//#include "simple_xmlss_model_sheet_configuration.hpp"

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


#ifndef SIMPLE_XMLSS_WRITER_SHEET_HPP
#define SIMPLE_XMLSS_WRITER_SHEET_HPP

//#include "simple_xmlss_model_sheet.hpp"

namespace simple_xmlss {

namespace writer {

class sheet {
public:
  void print_xmlss_node_worksheet(model::sheet& a_sheet,
                                  FILE* a_file) {
    simple_xmlss_fprintf(a_file, " <Worksheet ss:Name=\"%s\">\n", a_sheet.configuration.sheet_name.c_str());
    print_xmlss_node_table(a_sheet, a_file);
    print_xmlss_node_worksheet_options(a_sheet, a_file);
    simple_xmlss_fprintf(a_file, " </Worksheet>\n");
  }

private:
  //TODO 아래 값들을 option 으로 뺄 것.
  void print_xmlss_node_table(model::sheet& a_sheet,
                              FILE* a_file) {
    simple_xmlss_fprintf(a_file, "  <Table ss:ExpandedColumnCount=\"%u\" ss:ExpandedRowCount=\"%u\"", get_max_col(a_sheet), get_max_row(a_sheet));
    simple_xmlss_fprintf(a_file, " x:FullColumns=\"1\" x:FullRows=\"1\"");
    simple_xmlss_fprintf(a_file, " ss:DefaultColumnWidth=\"54\" ss:DefaultRowHeight=\"16.5\">\n");
    print_xmlss_node_column(a_sheet, a_file);
    print_xmlss_node_row(a_sheet, a_file);
    simple_xmlss_fprintf(a_file, "  </Table>\n");
  }

  unsigned int get_max_col(model::sheet& a_sheet) {
    unsigned int return_value = 0;
    for(auto& iter : a_sheet.col_width_map) {
      if(return_value < iter.first) {
        return_value = iter.first;
      }
    }
    if(return_value < a_sheet.coordinate.max_col) {
      return_value = a_sheet.coordinate.max_col;
    }
    return return_value;
  }

  unsigned int get_max_row(model::sheet& a_sheet) {
    unsigned int return_value = 0;
    for(auto& iter : a_sheet.row_height_map) {
      if(return_value < iter.first) {
        return_value = iter.first;
      }
    }
    if(return_value < a_sheet.coordinate.max_row) {
      return_value = a_sheet.coordinate.max_row;
    }
    return return_value;
  }

  void print_xmlss_node_column(model::sheet& a_sheet,
                               FILE* a_file) {
    for (auto &iter : a_sheet.col_width_map) {
      simple_xmlss_fprintf(a_file,"   <Column ss:Index=\"%u\" ss:AutoFitWidth=\"0\" ss:Width=\"%.2f\"/>\n", iter.first, iter.second);
    }
  }

  void print_xmlss_node_row(model::sheet& a_sheet,
                            FILE* a_file) {
    std::set<unsigned int> row;
    for (auto& row_iter : a_sheet.cell_map) {
      row.insert(row_iter.first);
    }
    for (auto& row_iter : a_sheet.row_height_map) {
      row.insert(row_iter.first);
    }
    for(auto& row_iter : row) {
      print_xmlss_node_row(a_sheet, row_iter, a_file);
    }
  }

  void print_xmlss_node_row(model::sheet& a_sheet,
                            const unsigned int a_row,
                            FILE* a_file) {
    simple_xmlss_fprintf(a_file, "   <Row ss:Index=\"%u\"", a_row);
    print_xmlss_row_height(a_sheet, a_row, a_file);
    auto row_iter = a_sheet.cell_map.find(a_row);
    if(a_sheet.cell_map.end() == row_iter) {
      simple_xmlss_fprintf(a_file, "/>\n");
    }
    else {
      simple_xmlss_fprintf(a_file, ">\n");
      for (auto& column_iter : row_iter->second) {
        column_iter.second.print_xmlss(a_file);
      }
      simple_xmlss_fprintf(a_file, "   </Row>\n");
    }
  }
  
  void print_xmlss_row_height(model::sheet& a_sheet,
                              const unsigned int a_row,
                              FILE* a_file) {
    auto iter = a_sheet.row_height_map.find(a_row);
    if(a_sheet.row_height_map.end() != iter) {
      simple_xmlss_fprintf(a_file, " ss:Height=\"%f\"", iter->second);
    }
  }

  //TODO: 아래 값들을 option 으로 뺄 것.
  void print_xmlss_node_worksheet_options(model::sheet& a_sheet,
                                          FILE* a_file) {
    simple_xmlss_fprintf(a_file, "  <WorksheetOptions xmlns=\"urn:schemas-microsoft-com:office:excel\">\n");
    simple_xmlss_fprintf(a_file, "   <PageSetup>\n");
    simple_xmlss_fprintf(a_file, "    <Header x:Margin=\"0.3\"/>\n");
    simple_xmlss_fprintf(a_file, "    <Footer x:Margin=\"0.3\"/>\n");
    simple_xmlss_fprintf(a_file, "    <PageMargins x:Bottom=\"0.75\" x:Left=\"0.7\" x:Right=\"0.7\" x:Top=\"0.75\"/>\n");
    simple_xmlss_fprintf(a_file, "   </PageSetup>\n");
    print_xmlss_worksheet_tab_color(a_sheet, a_file);
    simple_xmlss_fprintf(a_file, "   <Selected/>\n");
    simple_xmlss_fprintf(a_file, "   <ProtectObjects>False</ProtectObjects>\n");
    simple_xmlss_fprintf(a_file, "   <ProtectScenarios>False</ProtectScenarios>\n");
    simple_xmlss_fprintf(a_file, "  </WorksheetOptions>\n");
  }

  void print_xmlss_worksheet_tab_color(model::sheet& a_sheet,
                                       FILE* a_file) {
    if (model::SHEET_TAB_COLOR::DEFAULT != a_sheet.tab_color) {
      simple_xmlss_fprintf(a_file, "   <Unsynced/>\n");
      int current_tab_color = (int)a_sheet.tab_color;
      simple_xmlss_fprintf(a_file, "   <TabColorIndex>%d</TabColorIndex>\n", current_tab_color);
    }
  }
};

} // namespace writer

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_WRITER_SHEET_HPP */


#ifndef SIMPLE_XMLSS_API_SHEET_HPP
#define SIMPLE_XMLSS_API_SHEET_HPP

//#include "simple_xmlss_model_sheet.hpp"

namespace simple_xmlss {

namespace api {

class sheet {
public:
  simple_xmlss::cell& simple_xmlss_get_cell(model::sheet& a_sheet,
                                    const unsigned int a_col,
                                    const unsigned int a_row,
                                    const utility::trace& a_trace) {
    return get_cell_reference(a_sheet,
                              a_col,
                              a_row,
                              0,
                              0,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_get_cell(model::sheet& a_sheet,
                                    const unsigned int a_col,
                                    const unsigned int a_row,
                                    const unsigned int a_merge_across,
                                    const unsigned int a_merge_down,
                                    const utility::trace& a_trace) {
    return get_cell_reference(a_sheet,
                              a_col,
                              a_row,
                              a_merge_across,
                              a_merge_down,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::sheet& a_sheet,
                                      const std::string& a_string,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                  set_string(a_string,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::sheet& a_sheet,
                                      const std::string& a_string,
                                      const unsigned int a_font_id,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                  set_string(a_string,
                             a_font_id,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::sheet& a_sheet,
                                      const std::string& a_string,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const unsigned int a_merge_across,
                                      const unsigned int a_merge_down,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_merge_across,
                             a_merge_down,
                             a_trace).
                  set_string(a_string,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::sheet& a_sheet,
                                      const std::string& a_string,
                                      const unsigned int a_font_id,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const unsigned int a_merge_across,
                                      const unsigned int a_merge_down,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_merge_across,
                             a_merge_down,
                             a_trace).
                  set_string(a_string,
                             a_font_id,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::sheet& a_sheet,
                                      const model::cell_string& a_string,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                  set_string(a_string,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::sheet& a_sheet,
                                      const model::cell_string& a_string,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const unsigned int a_merge_across,
                                      const unsigned int a_merge_down,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_merge_across,
                             a_merge_down,
                             a_trace).
                  set_string(a_string,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_number(model::sheet& a_sheet,
                                      const std::string& a_number,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                  set_number(a_number,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_number(model::sheet& a_sheet,
                                      const std::string& a_number,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const unsigned int a_merge_across,
                                      const unsigned int a_merge_down,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_merge_across,
                             a_merge_down,
                             a_trace).
                  set_number(a_number,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_date_time(model::sheet& a_sheet,
                                         const std::string& a_date_time,
                                         const unsigned int a_col,
                                         const unsigned int a_row,
                                         const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
               set_date_time(a_date_time,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_date_time(model::sheet& a_sheet,
                                         const std::string& a_date_time,
                                         const unsigned int a_col,
                                         const unsigned int a_row,
                                         const unsigned int a_merge_across,
                                         const unsigned int a_merge_down,
                                         const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_merge_across,
                             a_merge_down,
                             a_trace).
               set_date_time(a_date_time,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_formula(model::sheet& a_sheet,
                                       const std::string& a_formula,
                                       const unsigned int a_col,
                                       const unsigned int a_row,
                                       const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                 set_formula(a_formula,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_formula(model::sheet& a_sheet,
                                      const std::string& a_formula,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const unsigned int a_merge_across,
                                      const unsigned int a_merge_down,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_merge_across,
                             a_merge_down,
                             a_trace).
                 set_formula(a_formula,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_comment(model::sheet& a_sheet,
                                       const std::string& a_comment,
                                       const unsigned int a_col,
                                       const unsigned int a_row,
                                       const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                 set_comment(a_comment,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_comment(model::sheet& a_sheet,
                                       const std::string& a_comment,
                                       const unsigned int a_font_id,
                                       const unsigned int a_col,
                                       const unsigned int a_row,
                                       const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                 set_comment(a_comment,
                             a_font_id,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_comment(model::sheet& a_sheet,
                                       const model::cell_comment& a_comment,
                                       const unsigned int a_col,
                                       const unsigned int a_row,
                                       const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                 set_comment(a_comment,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_hyperlink(model::sheet& a_sheet,
                                         const std::string& a_hyper_link_url,
                                         const unsigned int a_col,
                                         const unsigned int a_row,
                                         const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
               set_hyperlink(a_hyper_link_url,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_hyperlink(model::sheet& a_sheet,
                                         const std::string &a_hyperlink_sheet_name,
                                         const unsigned int a_hyperlink_col,
                                         const unsigned int a_hyperlink_row,
                                         const unsigned int a_col,
                                         const unsigned int a_row,
                                         const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
               set_hyperlink(a_hyperlink_sheet_name,
                             a_hyperlink_col,
                             a_hyperlink_row,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_style_id(model::sheet& a_sheet,
                                        const unsigned int a_style_id,
                                        const unsigned int a_col,
                                        const unsigned int a_row,
                                        const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                set_style_id(a_style_id,
                             a_trace);
  }

  void simple_xmlss_set_row_height(model::sheet& a_sheet,
                               const unsigned int a_row,
                               const float a_height,
                               const utility::trace& a_trace) {
    check_set_row_height(a_sheet,a_row,a_height,a_trace);
    a_sheet.row_height_map[a_row] = a_height;
  }
  
  void simple_xmlss_set_col_width(model::sheet& a_sheet,
                              const unsigned int a_col,
                              const float a_width,
                              const utility::trace& a_trace) {
    check_set_col_width(a_sheet,a_col,a_width,a_trace);
    a_sheet.col_width_map[a_col] = a_width;
  }

private:
  simple_xmlss::cell& get_cell_reference(model::sheet& a_sheet,
                                     const unsigned int a_col,
                                     const unsigned int a_row,
                                     const unsigned int a_merge_across,
                                     const unsigned int a_merge_down,
                                     const utility::trace& a_trace) {
    CELL_TYPE current_cell_type = get_cell_type(a_sheet,a_col,a_row);

    if(CELL_TYPE::NOT_EXIST == current_cell_type) {
      for(unsigned int iter_row = a_row; iter_row <= a_row + a_merge_down; iter_row++) {
        for(unsigned int iter_col = a_col; iter_col <= a_col + a_merge_across; iter_col++) {
          if(CELL_TYPE::NOT_EXIST != get_cell_type(a_sheet,iter_col,iter_row)) {
            handling_error_already_created_cell(a_sheet,a_col,a_row,a_merge_across,a_merge_down,iter_col,iter_row,a_trace);
          }
        }
      }
      create_cell(a_sheet,a_col,a_row,a_merge_across,a_merge_down);
    }
    else if (CELL_TYPE::NORMAL_CELL == current_cell_type) {
      if(0==a_merge_across && 0==a_merge_down);
      else {
        simple_xmlss::cell& exist_cell = a_sheet.cell_map.find(a_row)->second.find(a_col)->second;
        if(exist_cell.get_configuration().merge_across != a_merge_across ||
           exist_cell.get_configuration().merge_down != a_merge_down) {
          handling_error_different_configuration(a_sheet,a_col,a_row,a_merge_across,a_merge_down,exist_cell,a_trace);
        }
      }
    }
    else if (CELL_TYPE::MERGED_CELL == current_cell_type) {
      handling_error_merged_cell(a_sheet,a_col,a_row,a_merge_across,a_merge_down,a_trace);
    }

    update_coordinate(a_sheet, a_col, a_row, a_merge_across, a_merge_down);
    return a_sheet.cell_map.find(a_row)->second.find(a_col)->second;
  }

  void update_coordinate(model::sheet& a_sheet,
                         const unsigned int a_col,
                         const unsigned int a_row,
                         const unsigned int a_merge_across,
                         const unsigned int a_merge_down) {
    a_sheet.coordinate.current_col = a_col;
    a_sheet.coordinate.current_row = a_row;
    if(a_sheet.coordinate.max_col < (a_col + a_merge_across)) {
       a_sheet.coordinate.max_col = (a_col + a_merge_across);
    }
    if(a_sheet.coordinate.max_row < (a_row + a_merge_down)) {
       a_sheet.coordinate.max_row = (a_row + a_merge_down);
    }
  }

  enum class CELL_TYPE {
    NOT_EXIST,
    NORMAL_CELL,
    MERGED_CELL,
  };

  CELL_TYPE get_cell_type(model::sheet& a_sheet,
                          const unsigned int a_col,
                          const unsigned int a_row) {
    auto iter_row = a_sheet.cell_map.find(a_row);
    if(a_sheet.cell_map.end() == iter_row) {
      return CELL_TYPE::NOT_EXIST;
    }

    auto iter_col = iter_row->second.find(a_col);
    if(iter_row->second.end() == iter_col) {
      return CELL_TYPE::NOT_EXIST;
    }

    if(true == iter_col->second.get_configuration().merge_flag) {
      return CELL_TYPE::MERGED_CELL;
    }
    return CELL_TYPE::NORMAL_CELL;
  }

  void create_cell(model::sheet& a_sheet,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const unsigned int a_merge_across,
                   const unsigned int a_merge_down) {
    for(unsigned int iter_row = a_row; iter_row <= a_row + a_merge_down; iter_row++) {
      for(unsigned int iter_col = a_col; iter_col <= a_col + a_merge_across; iter_col++) {
        if(a_col==iter_col && a_row==iter_row) {
            model::cell_configuration new_cell_configuration;
            new_cell_configuration.book_name = a_sheet.configuration.book_name;
            new_cell_configuration.sheet_name = a_sheet.configuration.sheet_name;
            new_cell_configuration.coordinate.col = a_col;
            new_cell_configuration.coordinate.row = a_row;
            new_cell_configuration.merge_across = a_merge_across;
            new_cell_configuration.merge_down = a_merge_down;
            new_cell_configuration.merge_flag = false;
            new_cell_configuration.merge_origin.col = 0;
            new_cell_configuration.merge_origin.row = 0;
            cell_map_insert(a_sheet,new_cell_configuration);
        }
        else {
            model::cell_configuration new_cell_configuration;
            new_cell_configuration.book_name = a_sheet.configuration.book_name;
            new_cell_configuration.sheet_name = a_sheet.configuration.sheet_name;
            new_cell_configuration.coordinate.col = iter_col;
            new_cell_configuration.coordinate.row = iter_row;
            new_cell_configuration.merge_across = 0;
            new_cell_configuration.merge_down = 0;
            new_cell_configuration.merge_flag = true;
            new_cell_configuration.merge_origin.col = a_col;
            new_cell_configuration.merge_origin.row = a_row;
            cell_map_insert(a_sheet,new_cell_configuration);
        }
      }
    }
  }

  void cell_map_insert(model::sheet& a_sheet, const model::cell_configuration& a_cell_configuration) {
    simple_xmlss::cell new_cell(a_cell_configuration);
    unsigned int col = a_cell_configuration.coordinate.col;
    unsigned int row = a_cell_configuration.coordinate.row;
    auto iter_row = a_sheet.cell_map.find(row);
    if(a_sheet.cell_map.end() == iter_row) {
      model::column_to_cell_map new_column_to_cell_map;
      new_column_to_cell_map.insert(std::make_pair(col, new_cell));
      a_sheet.cell_map.insert(std::make_pair(row,new_column_to_cell_map));
    }
    else {
      iter_row->second.insert(std::make_pair(col,new_cell));
    }
  }

  void handling_error_already_created_cell(model::sheet& a_sheet,
                                           const unsigned int a_col,
                                           const unsigned int a_row,
                                           const unsigned int a_merge_across,
                                           const unsigned int a_merge_down,
                                           const unsigned int a_iter_col,
                                           const unsigned int a_iter_row,
                                           const utility::trace& a_trace) {
    std::string msg = "[ERROR] While performing simple_xmlss_get_cell("+
                      std::to_string(a_col)+
                      ","+
                      std::to_string(a_row)+
                      ","+
                      std::to_string(a_merge_across)+
                      ","+
                      std::to_string(a_merge_down)+
                      "), an already created Cell("+
                      std::to_string(a_iter_col)+
                      ","+
                      std::to_string(a_iter_row)+
                      ") was found.";
    handling_error(a_sheet,a_trace,"N/A","N/A",msg);
  }

  void handling_error_different_configuration(model::sheet& a_sheet,
                                              const unsigned int a_col,
                                              const unsigned int a_row,
                                              const unsigned int a_merge_across,
                                              const unsigned int a_merge_down,
                                              const simple_xmlss::cell& a_exist_cell,
                                              const utility::trace& a_trace) {
  std::string msg = "[ERROR] The configuration of the pre-existing cell is different from the argument passed to simple_xmlss_get_cell("+
                      std::to_string(a_col)+
                      ","+
                      std::to_string(a_row)+
                      ","+
                      std::to_string(a_merge_across)+
                      ","+
                      std::to_string(a_merge_down)+
                      "). -- pre-existing cell configuration: merge_across("+
                      std::to_string(a_exist_cell.get_configuration().merge_across)+
                      "),merge_down("+
                      std::to_string(a_exist_cell.get_configuration().merge_down)+
                      ")";
    handling_error(a_sheet,a_trace,"N/A","N/A",msg);
  }

  void handling_error_merged_cell(model::sheet& a_sheet,
                                  const unsigned int a_col,
                                  const unsigned int a_row,
                                  const unsigned int a_merge_across,
                                  const unsigned int a_merge_down,
                                  const utility::trace& a_trace) {
    std::string msg = "[ERROR] While performing simple_xmlss_get_cell("+
                      std::to_string(a_col)+
                      ","+
                      std::to_string(a_row)+
                      ","+
                      std::to_string(a_merge_across)+
                      ","+
                      std::to_string(a_merge_down)+
                      "), an already merged Cell("+
                      std::to_string(a_col)+
                      ","+
                      std::to_string(a_row)+
                      ") was found.";
    handling_error(a_sheet,a_trace,"N/A","N/A",msg);
  }

  void check_set_row_height(model::sheet& a_sheet,
                            const unsigned int a_row,
                            const float a_height,
                            const utility::trace& a_trace) {
    if(a_sheet.row_height_map.end() == a_sheet.row_height_map.find(a_row)) {
      return;
    }

    handling_error(a_sheet,a_trace,"N/A",std::to_string(a_row),"Already exist row["+
                                                                std::to_string(a_row)+
                                                                "] height value["+
                                                                std::to_string(a_sheet.row_height_map[a_row])+
                                                                "] Doscard: row["+
                                                                std::to_string(a_row)+
                                                                "] height value["+
                                                                std::to_string(a_height)+
                                                                "]");
  }

  void check_set_col_width(model::sheet& a_sheet,
                              const unsigned int a_col,
                              const float a_width,
                              const utility::trace& a_trace) {
    if(a_sheet.col_width_map.end() == a_sheet.col_width_map.find(a_col)) {
      return;      
    }
    handling_error(a_sheet,a_trace,std::to_string(a_col),"N/A","Already exist col["+
                                                                std::to_string(a_col)+
                                                                "] width value["+
                                                                std::to_string(a_sheet.col_width_map[a_col])+
                                                                "] Discard: col["+
                                                                std::to_string(a_col)+
                                                                "] width value["+
                                                                std::to_string(a_width)+
                                                                "]");
  }

  void handling_error(model::sheet& a_sheet,
                      const utility::trace& a_trace,
                      const std::string& a_col,
                      const std::string& a_row,
                      const std::string& a_comment) const {
    utility::error new_error(a_trace.file_name,
                             a_trace.function_name,
                            std::to_string(a_trace.line),
                            a_sheet.configuration.book_name,
                            a_sheet.configuration.sheet_name,
                            a_col,
                            a_row,
                            a_comment);
    utility::error_handler::instance().handling_error(new_error);
  }
};

} // namespace api

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_API_SHEET_HPP */


#ifndef SIMPLE_XMLSS_SHEET_HPP
#define SIMPLE_XMLSS_SHEET_HPP

//#include "simple_xmlss_model_sheet.hpp"
//#include "simple_xmlss_api_sheet.hpp"
//#include "simple_xmlss_writer_sheet.hpp"

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


#ifndef SIMPLE_XMLSS_MODEL_BOOK_SHEET_MAP_HPP
#define SIMPLE_XMLSS_MODEL_BOOK_SHEET_MAP_HPP

//#include "simple_xmlss_sheet.hpp"
//#include "simple_xmlss_dependency.hpp"

namespace simple_xmlss {

namespace model {

typedef std::map<const std::string, simple_xmlss::sheet> book_sheet_map;

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_BOOK_SHEET_MAP_HPP */


#ifndef SIMPLE_XMLSS_MODEL_BOOK_HPP
#define SIMPLE_XMLSS_MODEL_BOOK_HPP

//#include "simple_xmlss_model_book_sheet_map.hpp"

namespace simple_xmlss {

namespace model {

class book {
public:
  const std::string book_name;
  book_sheet_map sheet_map;

  book(const std::string& a_book_name)
    : book_name(a_book_name) {}
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_BOOK_HPP */


#ifndef SIMPLE_XMLSS_WRITER_BOOK_HPP
#define SIMPLE_XMLSS_WRITER_BOOK_HPP

//#include "simple_xmlss_model_book.hpp"
//#include "simple_xmlss_utility_time_manager.hpp"
//#include "simple_xmlss_builder_style.hpp"

namespace simple_xmlss {

namespace writer {

class book {
public:
  void print_xmlss_book(model::book& a_book,
                        FILE* a_file) {
    if(0 >= a_book.sheet_map.size()) {
      return;
    }

    print_xmlss_hdr(a_file);
    print_xmlss_node_workbook(a_book,a_file);
  }

private:
  void print_xmlss_hdr(FILE* a_file) {
    simple_xmlss_fprintf(a_file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    simple_xmlss_fprintf(a_file, "<?mso-application progid=\"Excel.Sheet\"?>\n");  
  }

  void print_xmlss_node_workbook(model::book& a_book,
                                 FILE* a_file) {
  simple_xmlss_fprintf(a_file, "<Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\"");
  simple_xmlss_fprintf(a_file, " xmlns:o=\"urn:schemas-microsoft-com:office:office\"");
  simple_xmlss_fprintf(a_file, " xmlns:x=\"urn:schemas-microsoft-com:office:excel\"");
  simple_xmlss_fprintf(a_file, " xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\"");
  simple_xmlss_fprintf(a_file, " xmlns:html=\"http://www.w3.org/TR/REC-html40\">\n");
  print_xmlss_node_document_properties(a_file);
  print_xmlss_node_office_document_settings(a_file);
  print_xmlss_node_workbook(a_file);
  print_xmlss_node_styles(a_file);
  print_xmlss_node_worksheet(a_book, a_file);
  simple_xmlss_fprintf(a_file, "</Workbook>");
}

//TODO: Author, LastAuthor, Created, LastSaved, Company 를 Update 받을 수 있도록 할 것.
void print_xmlss_node_document_properties(FILE* a_file) {
  simple_xmlss_fprintf(a_file, " <DocumentProperties xmlns=\"urn:schemas-microsoft-com:office:office\">\n");
  simple_xmlss_fprintf(a_file, "  <Author>Default</Author>\n");
  simple_xmlss_fprintf(a_file, "  <LastAuthor>Default</LastAuthor>\n");
  std::string current_time_str = utility::time_manager::instance().get_time_string();
  simple_xmlss_fprintf(a_file, "  <Created>%s</Created>\n", current_time_str.c_str());
  simple_xmlss_fprintf(a_file, "  <LastSaved>%s</LastSaved>\n", current_time_str.c_str());
  simple_xmlss_fprintf(a_file, "  <Company>Default</Company>\n");
  simple_xmlss_fprintf(a_file, "  <Version>14.00</Version>\n");
  simple_xmlss_fprintf(a_file, " </DocumentProperties>\n");
}

void print_xmlss_node_office_document_settings(FILE* a_file) {
  simple_xmlss_fprintf(a_file, " <OfficeDocumentSettings xmlns=\"urn:schemas-microsoft-com:office:office\">\n");
  simple_xmlss_fprintf(a_file, "  <AllowPNG/>\n");
  simple_xmlss_fprintf(a_file, " </OfficeDocumentSettings>\n");
}

//TODO: WindowHeight, WindowWidth, WindowTopX, WindowTopY 를 Update 받을 수 있도록 할 것.
void print_xmlss_node_workbook(FILE* a_file) {
  simple_xmlss_fprintf(a_file, " <ExcelWorkbook xmlns=\"urn:schemas-microsoft-com:office:excel\">\n");
  simple_xmlss_fprintf(a_file, "  <WindowHeight>8730</WindowHeight>\n");
  simple_xmlss_fprintf(a_file, "  <WindowWidth>17235</WindowWidth>\n");
  simple_xmlss_fprintf(a_file, "  <WindowTopX>480</WindowTopX>\n");
  simple_xmlss_fprintf(a_file, "  <WindowTopY>60</WindowTopY>\n");
  simple_xmlss_fprintf(a_file, "  <ProtectStructure>False</ProtectStructure>\n");
  simple_xmlss_fprintf(a_file, "  <ProtectWindows>False</ProtectWindows>\n");
  simple_xmlss_fprintf(a_file, " </ExcelWorkbook>\n");
}

void print_xmlss_node_styles(FILE* a_file) {
  simple_xmlss_fprintf(a_file, " <Styles>\n");
  builder::style::instance().print_xmlss(a_file);
  fprintf(a_file, " </Styles>\n");
}

void print_xmlss_node_worksheet(model::book& a_book,
                                FILE* a_file) {
  for (auto &ws_iter : a_book.sheet_map) {
    ws_iter.second.print_xmlss(a_file);
  }
}

};

} // namespace writer

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_WRITER_BOOK_HPP */


#ifndef SIMPLE_XMLSS_API_BOOK_HPP
#define SIMPLE_XMLSS_API_BOOK_HPP

//#include "simple_xmlss_model_book.hpp"

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


#ifndef SIMPLE_XMLSS_BOOK_HPP
#define SIMPLE_XMLSS_BOOK_HPP

//#include "simple_xmlss_model_book.hpp"
//#include "simple_xmlss_api_book.hpp"
//#include "simple_xmlss_writer_book.hpp"
//#include "simple_xmlss_builder_comment.hpp"
//#include "simple_xmlss_builder_font.hpp"
//#include "simple_xmlss_builder_string.hpp"
//#include "simple_xmlss_builder_style.hpp"

namespace simple_xmlss {

class book {
public:
  book(const std::string& a_book_name = "DefaultBookName")
    : m_model(a_book_name) {}

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


