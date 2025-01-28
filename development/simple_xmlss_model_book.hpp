#ifndef SIMPLE_XMLSS_MODEL_BOOK_HPP
#define SIMPLE_XMLSS_MODEL_BOOK_HPP

#include "simple_xmlss_model_book_sheet_map.hpp"
#include "simple_xmlss_model_book_sheet_index_map.hpp"

namespace simple_xmlss {

namespace model {

class book {
public:
  const std::string book_name;
  book_sheet_map sheet_map;
  book_sheet_index_map sheet_index_map;

  book(const std::string& a_book_name)
    : book_name(a_book_name) {}
};

} // namespace model

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_MODEL_BOOK_HPP */