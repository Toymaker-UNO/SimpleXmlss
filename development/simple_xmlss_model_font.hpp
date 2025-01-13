#ifndef SIMPLE_XMLSS_MODEL_FONT_HPP
#define SIMPLE_XMLSS_MODEL_FONT_HPP

#include "simple_xmlss_model_font_char_set.hpp"
#include "simple_xmlss_model_font_underline.hpp"
#include "simple_xmlss_model_font_superscript_subscript.hpp"
#include "simple_xmlss_dependency.hpp"

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