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