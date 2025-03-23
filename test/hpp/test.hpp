#ifndef SIMPLE_XMLSS_TEST_HPP
#define SIMPLE_XMLSS_TEST_HPP

#include "abstract_test_case.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cerrno>

namespace simple_xmlss {

class test {
public:
  static test& instance(void) {
      static test singleton_instance;
      return singleton_instance;
  }

  template <typename T>
  void register_test_case(void) {
    T* new_test_case = new T();
    m_data.push_back((abstract_test_case*)new_test_case);
  }

  void run(const std::string& a_example_dir) {
    try {
      utility::time_manager::instance().set_debug_flag(true);
      for(auto& iter : m_data) {
        //for unit test initialize
        builder::font::instance().initialize();
        builder::style::instance().initialize();

        std::string test_name = iter->run();
        std::string file_name_1 = "./" + test_name + ".xml";
        std::string file_name_2 = a_example_dir + test_name + ".xml";
        report(test_name, file_name_1, file_name_2);
      }
    }
    catch (const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }

private:
  ~test(void) {
    for(auto& iter : m_data) {
      if(nullptr != iter) {
        delete(iter);
      }
    }
  }

  void report(const std::string& a_test_name, const std::string& a_file_1, const std::string& a_file_2) {
    std::string string_1;
    std::string string_2;
    file_to_string(a_file_1, string_1);
    file_to_string(a_file_2, string_2);
    if(string_1 == string_2) {
      printf("[ SUCCESS ]: %s\n", a_test_name.c_str());
      std::remove(a_file_1.c_str());
    }
    else {
      printf("[  FAIL   ]: %s\n", a_test_name.c_str());
    }
  }

  void file_to_string(const std::string& a_file_name, std::string& a_return_value) {
    std::ifstream file(a_file_name);
    if (!file.is_open()) {
      std::cerr << "can not open file: " << a_file_name << std::endl;
      return;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    a_return_value = buffer.str();
    file.close();
  }

  std::list<abstract_test_case*> m_data;
};

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_TEST_HPP */