#ifndef SIMPLE_XMLSS_MODEL_STYLE_FILL_PATTERN_HPP
#define SIMPLE_XMLSS_MODEL_STYLE_FILL_PATTERN_HPP

#include "simple_xmlss_dependency.hpp"

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