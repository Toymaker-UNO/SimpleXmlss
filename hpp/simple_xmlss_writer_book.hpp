#ifndef SIMPLE_XMLSS_WRITER_BOOK_HPP
#define SIMPLE_XMLSS_WRITER_BOOK_HPP

#include "simple_xmlss_model_book.hpp"
#include "simple_xmlss_utility_time_manager.hpp"
#include "simple_xmlss_builder_style.hpp"

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