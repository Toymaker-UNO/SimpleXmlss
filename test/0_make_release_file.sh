#!/bin/bash
MERGE_FILE_NAME="./simple_xmlss.hpp"
#MERGE_FILE_NAME="../release/simple_xmlss.hpp"

rm -rf $MERGE_FILE_NAME

function merge #[#file_name]
{
  cat $1 >> $MERGE_FILE_NAME
  echo "" >> $MERGE_FILE_NAME
}

function merge_wo_include #[file_name]
{
  cat $1 | sed "s/#include/\\/\\/#include/g" >> $MERGE_FILE_NAME
  echo "" >> $MERGE_FILE_NAME
  echo "" >> $MERGE_FILE_NAME
  echo "" >> $MERGE_FILE_NAME
}

echo "/***************************************************************************************************"  >> $MERGE_FILE_NAME
echo "****************************************************************************************************"  >> $MERGE_FILE_NAME
merge ../LICENSE.txt
echo "****************************************************************************************************"  >> $MERGE_FILE_NAME
echo "***************************************************************************************************/"  >> $MERGE_FILE_NAME
merge ../development/simple_xmlss_dependency.hpp
echo "" >> $MERGE_FILE_NAME
echo "" >> $MERGE_FILE_NAME

merge_wo_include ../development/simple_xmlss_utility_error.hpp                       #BASIC
merge_wo_include ../development/simple_xmlss_utility_error_handler.hpp               #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_utility_inline_functions.hpp            #BASIC
merge_wo_include ../development/simple_xmlss_utility_time_manager.hpp                #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_utility_trace.hpp                       #BASIC

merge_wo_include ../development/simple_xmlss_model_font_char_set.hpp                 #BASIC
merge_wo_include ../development/simple_xmlss_model_font_superscript_subscript.hpp    #BASIC
merge_wo_include ../development/simple_xmlss_model_font_underline.hpp                #BASIC
merge_wo_include ../development/simple_xmlss_model_font.hpp                          #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_model_font_map.hpp                      #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_writer_font_map.hpp                     #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_api_font_map.hpp                        #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_builder_font.hpp                        #DEPENDENCY_RESOLVED

merge_wo_include ../development/simple_xmlss_model_style_alignment_horizontal.hpp    #BASIC
merge_wo_include ../development/simple_xmlss_model_style_alignment_text_control.hpp  #BASIC
merge_wo_include ../development/simple_xmlss_model_style_alignment_vertical.hpp      #BASIC
merge_wo_include ../development/simple_xmlss_model_style_border_line_type.hpp        #BASIC
merge_wo_include ../development/simple_xmlss_model_style_border_position.hpp         #BASIC
merge_wo_include ../development/simple_xmlss_model_style_border_weight.hpp           #BASIC
merge_wo_include ../development/simple_xmlss_model_style_fill_pattern.hpp            #BASIC
merge_wo_include ../development/simple_xmlss_model_style_number_format.hpp           #BASIC
merge_wo_include ../development/simple_xmlss_model_style_fill.hpp                    #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_model_style_border.hpp                  #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_model_style_border_map.hpp              #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_model_style_alignment.hpp               #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_model_style.hpp                         #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_model_style_map.hpp                     #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_writer_style_map.hpp                    #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_api_style_map.hpp                       #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_builder_style.hpp                       #DEPENDENCY_RESOLVED

merge_wo_include ../development/simple_xmlss_model_cell_coordinate.h                 #BASIC
merge_wo_include ../development/simple_xmlss_model_cell_font_string.hpp              #BASIC
merge_wo_include ../development/simple_xmlss_model_cell_status_flag.hpp              #BASIC
merge_wo_include ../development/simple_xmlss_model_cell_string.hpp                   #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_model_cell_comment.hpp                  #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_model_cell_configuration.hpp            #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_model_cell.hpp                          #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_writer_cell.hpp                         #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_api_cell.hpp                            #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_cell.hpp                                #DEPENDENCY_RESOLVED

merge_wo_include ../development/simple_xmlss_builder_string.hpp                      #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_builder_comment.hpp                     #DEPENDENCY_RESOLVED

merge_wo_include ../development/simple_xmlss_model_sheet_configuration.hpp           #BASIC
merge_wo_include ../development/simple_xmlss_model_sheet_cell_size_map.hpp           #BASIC
merge_wo_include ../development/simple_xmlss_model_sheet_coordinate.hpp              #BASIC
merge_wo_include ../development/simple_xmlss_model_sheet_tab_color.hpp               #BASIC
merge_wo_include ../development/simple_xmlss_model_sheet_cell_map.hpp                #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_model_sheet.hpp                         #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_writer_sheet.hpp                        #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_api_sheet.hpp                           #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_sheet.hpp                               #DEPENDENCY_RESOLVED

merge_wo_include ../development/simple_xmlss_model_book_sheet_map.hpp                #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_model_book.hpp                          #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_writer_book.hpp                         #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_api_book.hpp                            #DEPENDENCY_RESOLVED
merge_wo_include ../development/simple_xmlss_book.hpp                                #DEPENDENCY_RESOLVED
