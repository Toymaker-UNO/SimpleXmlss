#ifndef SIMPLE_XMLSS_UTILITY_INLINE_FUNCTIONS_HPP
#define SIMPLE_XMLSS_UTILITY_INLINE_FUNCTIONS_HPP

#include "simple_xmlss_dependency.hpp"

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