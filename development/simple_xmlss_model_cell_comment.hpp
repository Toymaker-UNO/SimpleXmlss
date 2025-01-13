#ifndef SIMPLE_XMLSS_MODEL_CELL_COMMENT_HPP
#define SIMPLE_XMLSS_MODEL_CELL_COMMENT_HPP

#include "simple_xmlss_model_cell_string.hpp"
#include "simple_xmlss_dependency.hpp"

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