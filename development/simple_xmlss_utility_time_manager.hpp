#ifndef SIMPLE_XMLSS_TIME_MANAGER_HPP
#define SIMPLE_XMLSS_TIME_MANAGER_HPP

#include "simple_xmlss_utility_inline_functions.hpp"

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