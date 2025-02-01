#ifndef SIMPLE_XMLSS_WRITER_SHEET_HPP
#define SIMPLE_XMLSS_WRITER_SHEET_HPP

#include "simple_xmlss_model_sheet.hpp"

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