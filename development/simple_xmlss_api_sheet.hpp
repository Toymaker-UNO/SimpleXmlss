#ifndef SIMPLE_XMLSS_API_SHEET_HPP
#define SIMPLE_XMLSS_API_SHEET_HPP

#include "simple_xmlss_model_sheet.hpp"

namespace simple_xmlss {

namespace api {

class sheet {
public:
  simple_xmlss::cell& simple_xmlss_get_cell(model::sheet& a_sheet,
                                    const unsigned int a_col,
                                    const unsigned int a_row,
                                    const utility::trace& a_trace) {
    return get_cell_reference(a_sheet,
                              a_col,
                              a_row,
                              0,
                              0,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_get_cell(model::sheet& a_sheet,
                                    const unsigned int a_col,
                                    const unsigned int a_row,
                                    const unsigned int a_merge_across,
                                    const unsigned int a_merge_down,
                                    const utility::trace& a_trace) {
    return get_cell_reference(a_sheet,
                              a_col,
                              a_row,
                              a_merge_across,
                              a_merge_down,
                              a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::sheet& a_sheet,
                                      const std::string& a_string,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                  set_string(a_string,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::sheet& a_sheet,
                                      const std::string& a_string,
                                      const unsigned int a_font_id,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                  set_string(a_string,
                             a_font_id,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::sheet& a_sheet,
                                      const std::string& a_string,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const unsigned int a_merge_across,
                                      const unsigned int a_merge_down,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_merge_across,
                             a_merge_down,
                             a_trace).
                  set_string(a_string,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::sheet& a_sheet,
                                      const std::string& a_string,
                                      const unsigned int a_font_id,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const unsigned int a_merge_across,
                                      const unsigned int a_merge_down,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_merge_across,
                             a_merge_down,
                             a_trace).
                  set_string(a_string,
                             a_font_id,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::sheet& a_sheet,
                                      const model::cell_string& a_string,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                  set_string(a_string,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_string(model::sheet& a_sheet,
                                      const model::cell_string& a_string,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const unsigned int a_merge_across,
                                      const unsigned int a_merge_down,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_merge_across,
                             a_merge_down,
                             a_trace).
                  set_string(a_string,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_number(model::sheet& a_sheet,
                                      const std::string& a_number,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                  set_number(a_number,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_number(model::sheet& a_sheet,
                                      const std::string& a_number,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const unsigned int a_merge_across,
                                      const unsigned int a_merge_down,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_merge_across,
                             a_merge_down,
                             a_trace).
                  set_number(a_number,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_date_time(model::sheet& a_sheet,
                                         const std::string& a_date_time,
                                         const unsigned int a_col,
                                         const unsigned int a_row,
                                         const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
               set_date_time(a_date_time,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_date_time(model::sheet& a_sheet,
                                         const std::string& a_date_time,
                                         const unsigned int a_col,
                                         const unsigned int a_row,
                                         const unsigned int a_merge_across,
                                         const unsigned int a_merge_down,
                                         const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_merge_across,
                             a_merge_down,
                             a_trace).
               set_date_time(a_date_time,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_formula(model::sheet& a_sheet,
                                       const std::string& a_formula,
                                       const unsigned int a_col,
                                       const unsigned int a_row,
                                       const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                 set_formula(a_formula,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_formula(model::sheet& a_sheet,
                                      const std::string& a_formula,
                                      const unsigned int a_col,
                                      const unsigned int a_row,
                                      const unsigned int a_merge_across,
                                      const unsigned int a_merge_down,
                                      const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_merge_across,
                             a_merge_down,
                             a_trace).
                 set_formula(a_formula,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_comment(model::sheet& a_sheet,
                                       const std::string& a_comment,
                                       const unsigned int a_col,
                                       const unsigned int a_row,
                                       const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                 set_comment(a_comment,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_comment(model::sheet& a_sheet,
                                       const std::string& a_comment,
                                       const unsigned int a_font_id,
                                       const unsigned int a_col,
                                       const unsigned int a_row,
                                       const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                 set_comment(a_comment,
                             a_font_id,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_comment(model::sheet& a_sheet,
                                       const model::cell_comment& a_comment,
                                       const unsigned int a_col,
                                       const unsigned int a_row,
                                       const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                 set_comment(a_comment,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_hyperlink(model::sheet& a_sheet,
                                         const std::string& a_hyper_link_url,
                                         const unsigned int a_col,
                                         const unsigned int a_row,
                                         const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
               set_hyperlink(a_hyper_link_url,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_hyperlink(model::sheet& a_sheet,
                                         const std::string &a_hyperlink_sheet_name,
                                         const unsigned int a_hyperlink_col,
                                         const unsigned int a_hyperlink_row,
                                         const unsigned int a_col,
                                         const unsigned int a_row,
                                         const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
               set_hyperlink(a_hyperlink_sheet_name,
                             a_hyperlink_col,
                             a_hyperlink_row,
                             a_trace);
  }

  simple_xmlss::cell& simple_xmlss_set_style_id(model::sheet& a_sheet,
                                        const unsigned int a_style_id,
                                        const unsigned int a_col,
                                        const unsigned int a_row,
                                        const utility::trace& a_trace) {
    return simple_xmlss_get_cell(a_sheet,
                             a_col,
                             a_row,
                             a_trace).
                set_style_id(a_style_id,
                             a_trace);
  }

  void simple_xmlss_set_row_height(model::sheet& a_sheet,
                               const unsigned int a_row,
                               const float a_height,
                               const utility::trace& a_trace) {
    check_set_row_height(a_sheet,a_row,a_height,a_trace);
    a_sheet.row_height_map[a_row] = a_height;
  }
  
  void simple_xmlss_set_col_width(model::sheet& a_sheet,
                              const unsigned int a_col,
                              const float a_width,
                              const utility::trace& a_trace) {
    check_set_col_width(a_sheet,a_col,a_width,a_trace);
    a_sheet.col_width_map[a_col] = a_width;
  }

private:
  simple_xmlss::cell& get_cell_reference(model::sheet& a_sheet,
                                     const unsigned int a_col,
                                     const unsigned int a_row,
                                     const unsigned int a_merge_across,
                                     const unsigned int a_merge_down,
                                     const utility::trace& a_trace) {
    CELL_TYPE current_cell_type = get_cell_type(a_sheet,a_col,a_row);

    if(CELL_TYPE::NOT_EXIST == current_cell_type) {
      for(unsigned int iter_row = a_row; iter_row <= a_row + a_merge_down; iter_row++) {
        for(unsigned int iter_col = a_col; iter_col <= a_col + a_merge_across; iter_col++) {
          if(CELL_TYPE::NOT_EXIST != get_cell_type(a_sheet,iter_col,iter_row)) {
            handling_error_already_created_cell(a_sheet,a_col,a_row,a_merge_across,a_merge_down,iter_col,iter_row,a_trace);
          }
        }
      }
      create_cell(a_sheet,a_col,a_row,a_merge_across,a_merge_down);
    }
    else if (CELL_TYPE::NORMAL_CELL == current_cell_type) {
      if(0==a_merge_across && 0==a_merge_down);
      else {
        simple_xmlss::cell& exist_cell = a_sheet.cell_map.find(a_row)->second.find(a_col)->second;
        if(exist_cell.get_configuration().merge_across != a_merge_across ||
           exist_cell.get_configuration().merge_down != a_merge_down) {
          handling_error_different_configuration(a_sheet,a_col,a_row,a_merge_across,a_merge_down,exist_cell,a_trace);
        }
      }
    }
    else if (CELL_TYPE::MERGED_CELL == current_cell_type) {
      handling_error_merged_cell(a_sheet,a_col,a_row,a_merge_across,a_merge_down,a_trace);
    }

    update_coordinate(a_sheet, a_col, a_row, a_merge_across, a_merge_down);
    return a_sheet.cell_map.find(a_row)->second.find(a_col)->second;
  }

  void update_coordinate(model::sheet& a_sheet,
                         const unsigned int a_col,
                         const unsigned int a_row,
                         const unsigned int a_merge_across,
                         const unsigned int a_merge_down) {
    a_sheet.coordinate.current_col = a_col;
    a_sheet.coordinate.current_row = a_row;
    if(a_sheet.coordinate.max_col < (a_col + a_merge_across)) {
       a_sheet.coordinate.max_col = (a_col + a_merge_across);
    }
    if(a_sheet.coordinate.max_row < (a_row + a_merge_down)) {
       a_sheet.coordinate.max_row = (a_row + a_merge_down);
    }
  }

  enum class CELL_TYPE {
    NOT_EXIST,
    NORMAL_CELL,
    MERGED_CELL,
  };

  CELL_TYPE get_cell_type(model::sheet& a_sheet,
                          const unsigned int a_col,
                          const unsigned int a_row) {
    auto iter_row = a_sheet.cell_map.find(a_row);
    if(a_sheet.cell_map.end() == iter_row) {
      return CELL_TYPE::NOT_EXIST;
    }

    auto iter_col = iter_row->second.find(a_col);
    if(iter_row->second.end() == iter_col) {
      return CELL_TYPE::NOT_EXIST;
    }

    if(true == iter_col->second.get_configuration().merge_flag) {
      return CELL_TYPE::MERGED_CELL;
    }
    return CELL_TYPE::NORMAL_CELL;
  }

  void create_cell(model::sheet& a_sheet,
                   const unsigned int a_col,
                   const unsigned int a_row,
                   const unsigned int a_merge_across,
                   const unsigned int a_merge_down) {
    for(unsigned int iter_row = a_row; iter_row <= a_row + a_merge_down; iter_row++) {
      for(unsigned int iter_col = a_col; iter_col <= a_col + a_merge_across; iter_col++) {
        if(a_col==iter_col && a_row==iter_row) {
            model::cell_configuration new_cell_configuration;
            new_cell_configuration.book_name = a_sheet.configuration.book_name;
            new_cell_configuration.sheet_name = a_sheet.configuration.sheet_name;
            new_cell_configuration.coordinate.col = a_col;
            new_cell_configuration.coordinate.row = a_row;
            new_cell_configuration.merge_across = a_merge_across;
            new_cell_configuration.merge_down = a_merge_down;
            new_cell_configuration.merge_flag = false;
            new_cell_configuration.merge_origin.col = 0;
            new_cell_configuration.merge_origin.row = 0;
            cell_map_insert(a_sheet,new_cell_configuration);
        }
        else {
            model::cell_configuration new_cell_configuration;
            new_cell_configuration.book_name = a_sheet.configuration.book_name;
            new_cell_configuration.sheet_name = a_sheet.configuration.sheet_name;
            new_cell_configuration.coordinate.col = iter_col;
            new_cell_configuration.coordinate.row = iter_row;
            new_cell_configuration.merge_across = 0;
            new_cell_configuration.merge_down = 0;
            new_cell_configuration.merge_flag = true;
            new_cell_configuration.merge_origin.col = a_col;
            new_cell_configuration.merge_origin.row = a_row;
            cell_map_insert(a_sheet,new_cell_configuration);
        }
      }
    }
  }

  void cell_map_insert(model::sheet& a_sheet, const model::cell_configuration& a_cell_configuration) {
    simple_xmlss::cell new_cell(a_cell_configuration);
    unsigned int col = a_cell_configuration.coordinate.col;
    unsigned int row = a_cell_configuration.coordinate.row;
    auto iter_row = a_sheet.cell_map.find(row);
    if(a_sheet.cell_map.end() == iter_row) {
      model::column_to_cell_map new_column_to_cell_map;
      new_column_to_cell_map.insert(std::make_pair(col, new_cell));
      a_sheet.cell_map.insert(std::make_pair(row,new_column_to_cell_map));
    }
    else {
      iter_row->second.insert(std::make_pair(col,new_cell));
    }
  }

  void handling_error_already_created_cell(model::sheet& a_sheet,
                                           const unsigned int a_col,
                                           const unsigned int a_row,
                                           const unsigned int a_merge_across,
                                           const unsigned int a_merge_down,
                                           const unsigned int a_iter_col,
                                           const unsigned int a_iter_row,
                                           const utility::trace& a_trace) {
    std::string msg = "[ERROR] While performing simple_xmlss_get_cell("+
                      std::to_string(a_col)+
                      ","+
                      std::to_string(a_row)+
                      ","+
                      std::to_string(a_merge_across)+
                      ","+
                      std::to_string(a_merge_down)+
                      "), an already created Cell("+
                      std::to_string(a_iter_col)+
                      ","+
                      std::to_string(a_iter_row)+
                      ") was found.";
    handling_error(a_sheet,a_trace,"N/A","N/A",msg);
  }

  void handling_error_different_configuration(model::sheet& a_sheet,
                                              const unsigned int a_col,
                                              const unsigned int a_row,
                                              const unsigned int a_merge_across,
                                              const unsigned int a_merge_down,
                                              const simple_xmlss::cell& a_exist_cell,
                                              const utility::trace& a_trace) {
  std::string msg = "[ERROR] The configuration of the pre-existing cell is different from the argument passed to simple_xmlss_get_cell("+
                      std::to_string(a_col)+
                      ","+
                      std::to_string(a_row)+
                      ","+
                      std::to_string(a_merge_across)+
                      ","+
                      std::to_string(a_merge_down)+
                      "). -- pre-existing cell configuration: merge_across("+
                      std::to_string(a_exist_cell.get_configuration().merge_across)+
                      "),merge_down("+
                      std::to_string(a_exist_cell.get_configuration().merge_down)+
                      ")";
    handling_error(a_sheet,a_trace,"N/A","N/A",msg);
  }

  void handling_error_merged_cell(model::sheet& a_sheet,
                                  const unsigned int a_col,
                                  const unsigned int a_row,
                                  const unsigned int a_merge_across,
                                  const unsigned int a_merge_down,
                                  const utility::trace& a_trace) {
    std::string msg = "[ERROR] While performing simple_xmlss_get_cell("+
                      std::to_string(a_col)+
                      ","+
                      std::to_string(a_row)+
                      ","+
                      std::to_string(a_merge_across)+
                      ","+
                      std::to_string(a_merge_down)+
                      "), an already merged Cell("+
                      std::to_string(a_col)+
                      ","+
                      std::to_string(a_row)+
                      ") was found.";
    handling_error(a_sheet,a_trace,"N/A","N/A",msg);
  }

  void check_set_row_height(model::sheet& a_sheet,
                            const unsigned int a_row,
                            const float a_height,
                            const utility::trace& a_trace) {
    if(a_sheet.row_height_map.end() == a_sheet.row_height_map.find(a_row)) {
      return;
    }

    handling_error(a_sheet,a_trace,"N/A",std::to_string(a_row),"Already exist row["+
                                                                std::to_string(a_row)+
                                                                "] height value["+
                                                                std::to_string(a_sheet.row_height_map[a_row])+
                                                                "] Doscard: row["+
                                                                std::to_string(a_row)+
                                                                "] height value["+
                                                                std::to_string(a_height)+
                                                                "]");
  }

  void check_set_col_width(model::sheet& a_sheet,
                              const unsigned int a_col,
                              const float a_width,
                              const utility::trace& a_trace) {
    if(a_sheet.col_width_map.end() == a_sheet.col_width_map.find(a_col)) {
      return;      
    }
    handling_error(a_sheet,a_trace,std::to_string(a_col),"N/A","Already exist col["+
                                                                std::to_string(a_col)+
                                                                "] width value["+
                                                                std::to_string(a_sheet.col_width_map[a_col])+
                                                                "] Discard: col["+
                                                                std::to_string(a_col)+
                                                                "] width value["+
                                                                std::to_string(a_width)+
                                                                "]");
  }

  void handling_error(model::sheet& a_sheet,
                      const utility::trace& a_trace,
                      const std::string& a_col,
                      const std::string& a_row,
                      const std::string& a_comment) const {
    utility::error new_error(a_trace.file_name,
                             a_trace.function_name,
                            std::to_string(a_trace.line),
                            a_sheet.configuration.book_name,
                            a_sheet.configuration.sheet_name,
                            a_col,
                            a_row,
                            a_comment);
    utility::error_handler::instance().handling_error(new_error);
  }
};

} // namespace api

} // namespace simple_xmlss

#endif /* SIMPLE_XMLSS_API_SHEET_HPP */