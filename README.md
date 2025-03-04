# 1. Simple xmlss
This is a library that easily creates spreadsheets in XMLSS format.

#c++
#C++
#Excel
#xmlss
#spreadsheet


# 2. class 소개
이 문서에서는 xmlss 를 작성하기 위한 다음 class 들의 member function 에 대해서 구체적으로 설명한다.
simple_xmlss 에서 사용하는 class 는 다음과 같다.

| class | Description |
|------|------|
| book | 이 class instance 는 하나의 xmlss 문서 (spread sheet)를 의미한다 |
| sheet | 이 class instance 는 book 내부 의 하나의 sheet 를 의미한다 |
| cell | 이 class instance 는 sheet 내부 의 하나의 cell을 의미한다 |
| builder::font | singleton class 이다. 모든 book 에서 사용할 수 있는 font 정보를 관리하고 font id 를 build 한다. |
| builder::style | singleton class 이다. 모든 book 에서 사용할 수 있는 cell  의 style 정보를 관리하고 stule id 를 build 한다. |
| builder::string | singleton class 이다. cell 의 string 을 advancedsettings 할 수 있는 model::cell_string 을 build 한다 |
| builder::comment | singleton class 이다. cell 의 comment 를 advancedsettings 할 수 있는 model::cell_comment 을 build 한다 |


# 3. dependency
simple_xmlss.hpp 는 다음 lib 을 요구한다.
```cpp
#include <string>
#include <exception>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <ctime>
```


# 4. namespace guide
```cpp
using namespace simple_xmlss;
```


# 5. book, sheet, cell class & member function
## 5.1 book
### 5.1.1 Description
book class 의 생성자에 대해 기술한다.

### 5.1.2 Function declaration
```cpp
book::book(const std::string& a_book_name = "DefaultBookName");
```

### 5.1.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_book_name | book 의 instance 를 구분하기 위함이다. 이 정보는 simple_xmlss 동작 중 Error 발생시 throw simple_xmlss::utility::error 를 수행하는데, 이 때 std::string book_name 으로써 전달 된다.  optional 이며 default 로 "DefaultBookName" 이 사용된다. |


## 5.2 get_sheet
### 5.2.1 Description
sheet& 를 가져온다. 만약 해당 book 내부에 a_sheet_name 에 해당하는 sheet instance 가 없다면 신규 생성 후 return 하고, 그렇지 않다면 기존에 생성된 sheet instance 의 reference 를 return 한다.

### 5.2.2 Function declaration
```cpp
sheet& book::get_sheet(const std::string& a_sheet_name);
```

### 5.2.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_sheet_name | book 내부에 관리되고 있는 sheet 를 구분하기 위한 sheet 의 name 이다. 또한 Excel로 open 시 sheet(탭) 의 이름으로 사용된다. 따라서 탭 이름으로 사용 불가능 한 문자는 사용하면 안된다. |


## 5.3 get_cell
### 5.3.1 Description
sheet가 관리하는 cell 의 instance reference를 return 한다.

### 5.3.2 Function declaration
```cpp
cell& sheet::get_cell(const unsigned int a_col,
                      const unsigned int a_row,
                      const utility::trace& a_trace = utility::trace());

cell& sheet::get_cell(const unsigned int a_col,
                      const unsigned int a_row,
                      const unsigned int a_merge_across,
                      const unsigned int a_merge_down,
                      const utility::trace& a_trace = utility::trace());
                      
```

### 5.3.3 Argument
| Argument name | Argument description |
|------|------|
| const unsigned int a_col | sheet 에서 cell 의 column 위치를 나타낸다. 가장 좌측 column 의 값은 1이다. |
| const unsigned int a_row | sheet 에서 cell 의 row 위치를 나타낸다. 가장 상단 row 의 값은 1이다. |
| const unsigned int a_merge_across | 병합된 cell 을 표현할 때 사용한다. a_col 기준으로 오른쪽으로 병합될 cell 의 개수를 의미한다. |
| const unsigned int a_merge_down | 병합된 cell 을 표현할 때 사용한다. a_row 기준으로 아래쪽으로 병합될 cell 의 개수를 의미한다. |
| const utility::trace& a_trace | 이 정보는 simple_xmlss 동작 중 Error 발생시 throw simple_xmlss::utility::error 를 수행하는데, 이 때 std::string file_name, std::string function_name, std::string line 정보로써 전달 된다. optional 이다. 만약 Degugging 정보를 Detail 하게 전달하기 위해서 해당 parameter 를 전달 한다면 "TRACE()" 매크로를 사용하는 것을 권장한다. |

### 5.3.4 Return / Error
성공시: cell instance 의 reference 를 return 한다.

실패시: utility::error instance를 throw 한다.

       case 1) 이미 다른 cell 에 의해서 merge 된 cell 을 요청 하였을 경우.
       
       case 2) 이미 다른 곳에서 get_cell 을 수행(최초 생성) 하였지만 이것과 다른 configuration 으로 get_cell 을 수행 한 경우.


## 5.4 set_string
### 5.4.1 Description
cell 에 string 을 write 한다.

### 5.4.2 Function declaration
```cpp
cell& book::set_string(const std::string& a_string,
                       const std::string& a_sheet_name,
                       const unsigned int a_col,
                       const unsigned int a_row,
                       const utility::trace& a_trace = utility::trace());

cell& book::set_string(const std::string& a_string,
                       const unsigned int a_font_id,
                       const std::string& a_sheet_name,
                       const unsigned int a_col,
                       const unsigned int a_row,
                       const utility::trace& a_trace = utility::trace());
                       
cell& book::set_string(const std::string& a_string,
                       const std::string& a_sheet_name,
                       const unsigned int a_col,
                       const unsigned int a_row,
                       const unsigned int a_merge_across,
                       const unsigned int a_merge_down,
                       const utility::trace& a_trace = utility::trace());

cell& book::set_string(const std::string& a_string,
                       const unsigned int a_font_id,
                       const std::string& a_sheet_name,
                       const unsigned int a_col,
                       const unsigned int a_row,
                       const unsigned int a_merge_across,
                       const unsigned int a_merge_down,
                       const utility::trace& a_trace = utility::trace());

cell& book::set_string(const model::cell_string& a_string,
                       const std::string& a_sheet_name,
                       const unsigned int a_col,
                       const unsigned int a_row,
                       const utility::trace& a_trace = utility::trace());

cell& book::set_string(const model::cell_string& a_string,
                       const std::string& a_sheet_name,
                       const unsigned int a_col,
                       const unsigned int a_row,
                       const unsigned int a_merge_across,
                       const unsigned int a_merge_down,
                       const utility::trace& a_trace = utility::trace());

cell& sheet::set_string(const std::string& a_string,
                        const unsigned int a_col,
                        const unsigned int a_row,
                        const utility::trace& a_trace = utility::trace());

cell& sheet::set_string(const std::string& a_string,
                        const unsigned int a_font_id,
                        const unsigned int a_col,
                        const unsigned int a_row,
                        const utility::trace& a_trace = utility::trace());

cell& sheet::set_string(const std::string& a_string,
                        const unsigned int a_col,
                        const unsigned int a_row,
                        const unsigned int a_merge_across,
                        const unsigned int a_merge_down,
                        const utility::trace& a_trace = utility::trace());

cell& sheet::set_string(const std::string& a_string,
                        const unsigned int a_font_id,
                        const unsigned int a_col,
                        const unsigned int a_row,
                        const unsigned int a_merge_across,
                        const unsigned int a_merge_down,
                        const utility::trace& a_trace = utility::trace());

cell& sheet::set_string(const model::cell_string& a_string,
                        const unsigned int a_col,
                        const unsigned int a_row,
                        const utility::trace& a_trace = utility::trace());

cell& sheet::set_string(const model::cell_string& a_string,
                        const unsigned int a_col,
                        const unsigned int a_row,
                        const unsigned int a_merge_across,
                        const unsigned int a_merge_down,
                        const utility::trace& a_trace = utility::trace());

cell& cell::set_string(const std::string& a_string,
                       const unsigned int a_font_id,
                       const utility::trace& a_trace = utility::trace());

cell& cell::set_string(const model::cell_string& a_string,
                       const utility::trace& a_trace = utility::trace());
```

### 5.4.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_string | cell 에 넣을 string 정보이다. |
| const model::cell_string& a_string | advancedsettings된 cell 에 넣을 string 정보이다. builder::string 클래스를 이용하여 구성하는 것을 권장한다. |
| const unsigned int a_font_id | string의 font 정보이다. builder::font 클래스를 이용하여 builde 한 정보를 넣어야 한다. |
| const std::string& a_sheet_name | book 내부 의 특정 sheet 를 지정하는 name 이다. |
| const unsigned int a_col | sheet 에서 cell 의 column 위치를 나타낸다. 가장 좌측 column 의 값은 1이다. |
| const unsigned int a_row | sheet 에서 cell 의 row 위치를 나타낸다. 가장 상단 row 의 값은 1이다. |
| const unsigned int a_merge_across | 병합된 cell 을 표현할 때 사용한다. a_col 기준으로 오른쪽으로 병합될 cell 의 개수를 의미한다. |
| const unsigned int a_merge_down | 병합된 cell 을 표현할 때 사용한다. a_row 기준으로 아래쪽으로 병합될 cell 의 개수를 의미한다. |
| const utility::trace& a_trace | 이 정보는 simple_xmlss 동작 중 Error 발생시 throw simple_xmlss::utility::error 를 수행하는데, 이 때 std::string file_name, std::string function_name, std::string line 정보로써 전달 된다. optional 이다. 만약 Degugging 정보를 Detail 하게 전달하기 위해서 해당 parameter 를 전달 한다면 "TRACE()" 매크로를 사용하는 것을 권장한다. |

### 5.4.4 Return / Error
성공시: cell instance 의 reference 를 return 한다. 이는 builder pattern 을 위함이다.

실패시: utility::error instance를 throw 한다.

       case 1) merge 한 cell 에 set_stirng 을 시도하는 경우
       
       case 2) 이미 set_string 을 수행한 cell 에 set_string 을 시도하는 경우
       
       case 3) 이미 set_number 을 수행한 cell 에 set_string 을 시도하는 경우
       
       case 4) 이미 set_date_time 을 수행한 cell 에 set_string 을 시도하는 경우
       
       case 5) 이미 set_formula 를 수행한 cell 에 set_string 을 시도하는 경우

### 5.4.5 Code example & output
```cpp
#include "simple_xmlss.hpp"

using namespace simple_xmlss;

int main(void) {
    //use book instance
    book workbook;
    workbook.set_string("A1 Data", "Sheet No 1", 1, 1);
    workbook.set_string("C3 Data", "Sheet No 1", 3, 3, 2, 2);
    
    //use sheet instance
    sheet& worksheet = workbook.get_sheet("Sheet No 1");
    worksheet.set_string("G1 Data", 7, 1);
    worksheet.set_string("G7 Data", 7, 7, 1, 1);
    
    //use cell instance
    cell& workcell_a10 = workseet.get_cell(1, 10);
    workcell_a10.set_string("A10 Data");
    cell& workcell_j10 = workseet.get_cell(10,10);
    workcell_j10.set_string("J10 Data");
    
    workbook.print_xmlss("./report.xml");

    return 0;
}
```


## 5.5 set_number
### 5.5.1 Description
cell 에 number 를 write 한다. write 하는 값은 숫자 형식의 string 이어야 한다.

### 5.5.2 Function declaration
```cpp
cell& book::set_number(const std::string& a_number,
                       const std::string& a_sheet_name,
                       const unsigned int a_col,
                       const unsigned int a_row,
                       const utility::trace& a_trace = utility::trace());

cell& book::set_number(const std::string& a_number,
                       const std::string& a_sheet_name,
                       const unsigned int a_col,
                       const unsigned int a_row,
                       const unsigned int a_merge_across,
                       const unsigned int a_merge_down,
                       const utility::trace& a_trace = utility::trace());

cell& sheet::set_number(const std::string& a_number,
                        const unsigned int a_col,
                        const unsigned int a_row,
                        const utility::trace& a_trace = utility::trace());

cell& sheet::set_number(const std::string& a_number,
                        const unsigned int a_col,
                        const unsigned int a_row,
                        const unsigned int a_merge_across,
                        const unsigned int a_merge_down,
                        const utility::trace& a_trace = utility::trace());

cell& cell::set_number(const std::string& a_number,
                       const utility::trace& a_trace = utility::trace());
```

### 5.5.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_number | cell 에 넣을 숫자 형식의 string 정보이다. |
| const std::string& a_sheet_name | book 내부 의 특정 sheet 를 지정하는 name 이다. |
| const unsigned int a_col | sheet 에서 cell 의 column 위치를 나타낸다. 가장 좌측 column 의 값은 1이다. |
| const unsigned int a_row | sheet 에서 cell 의 row 위치를 나타낸다. 가장 상단 row 의 값은 1이다. |
| const unsigned int a_merge_across | 병합된 cell 을 표현할 때 사용한다. a_col 기준으로 오른쪽으로 병합될 cell 의 개수를 의미한다. |
| const unsigned int a_merge_down | 병합된 cell 을 표현할 때 사용한다. a_row 기준으로 아래쪽으로 병합될 cell 의 개수를 의미한다. |
| const utility::trace& a_trace | 이 정보는 simple_xmlss 동작 중 Error 발생시 throw simple_xmlss::utility::error 를 수행하는데, 이 때 std::string file_name, std::string function_name, std::string line 정보로써 전달 된다. optional 이다. 만약 Degugging 정보를 Detail 하게 전달하기 위해서 해당 parameter 를 전달 한다면 "TRACE()" 매크로를 사용하는 것을 권장한다. |

### 5.5.4 Return / Error
성공시: cell instance 의 reference 를 return 한다. 이는 builder pattern 을 위함이다.

실패시: utility::error instance를 throw 한다.

       case 1) merge 한 cell 에 set_number 을 시도하는 경우
       
       case 2) 이미 set_string 을 수행한 cell 에 set_number 을 시도하는 경우
       
       case 3) 이미 set_number 을 수행한 cell 에 set_number 을 시도하는 경우
       
       case 4) 이미 set_date_time 을 수행한 cell 에 set_number 을 시도하는 경우
       
       case 5) 이미 set_formula 를 수행한 cell 에 set_number 을 시도하는 경우

### 5.5.5 Code example & output
TBD


## 5.6 set_date_time
### 5.6.1 Description
cell 에 날짜/시간 정보를 write 한다. write 하는 값은 날짜/시간 형식의 string 이어야 한다.

### 5.6.2 Function declaration
```cpp
cell& book::set_date_time(const std::string& a_date_time,
                          const std::string& a_sheet_name,
                          const unsigned int a_col,
                          const unsigned int a_row,
                          const utility::trace& a_trace = utility::trace());

cell& book::set_date_time(const std::string& a_date_time,
                          const std::string& a_sheet_name,
                          const unsigned int a_col,
                          const unsigned int a_row,
                          const unsigned int a_merge_across,
                          const unsigned int a_merge_down,
                          const utility::trace& a_trace = utility::trace());

cell& sheet::set_date_time(const std::string& a_date_time,
                           const unsigned int a_col,
                           const unsigned int a_row,
                           const utility::trace& a_trace = utility::trace());

cell& sheet::set_date_time(const std::string& a_date_time,
                           const unsigned int a_col,
                           const unsigned int a_row,
                           const unsigned int a_merge_across,
                           const unsigned int a_merge_down,
                           const utility::trace& a_trace = utility::trace());

cell& cell::set_date_time(const std::string& a_date_time,
                          const utility::trace& a_trace = utility::trace());
```

### 5.6.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_date_time | cell 에 넣을 날짜/시간 형식의 string 정보이다. |
| const std::string& a_sheet_name | book 내부 의 특정 sheet 를 지정하는 name 이다. |
| const unsigned int a_col | sheet 에서 cell 의 column 위치를 나타낸다. 가장 좌측 column 의 값은 1이다. |
| const unsigned int a_row | sheet 에서 cell 의 row 위치를 나타낸다. 가장 상단 row 의 값은 1이다. |
| const unsigned int a_merge_across | 병합된 cell 을 표현할 때 사용한다. a_col 기준으로 오른쪽으로 병합될 cell 의 개수를 의미한다. |
| const unsigned int a_merge_down | 병합된 cell 을 표현할 때 사용한다. a_row 기준으로 아래쪽으로 병합될 cell 의 개수를 의미한다. |
| const utility::trace& a_trace | 이 정보는 simple_xmlss 동작 중 Error 발생시 throw simple_xmlss::utility::error 를 수행하는데, 이 때 std::string file_name, std::string function_name, std::string line 정보로써 전달 된다. optional 이다. 만약 Degugging 정보를 Detail 하게 전달하기 위해서 해당 parameter 를 전달 한다면 "TRACE()" 매크로를 사용하는 것을 권장한다. |

### 5.6.4 Return / Error
성공시: cell instance 의 reference 를 return 한다. 이는 builder pattern 을 위함이다.

실패시: utility::error instance를 throw 한다.

       case 1) merge 한 cell 에 set_date_time 을 시도하는 경우
       
       case 2) 이미 set_string 을 수행한 cell 에 set_date_time 을 시도하는 경우
       
       case 3) 이미 set_number 을 수행한 cell 에 set_date_time 을 시도하는 경우
       
       case 4) 이미 set_date_time 을 수행한 cell 에 set_date_time 을 시도하는 경우
       
       case 5) 이미 set_formula 를 수행한 cell 에 set_date_time 을 시도하는 경우

### 5.6.5 Code example & output
TBD


## 5.7 set_formula
### 5.7.1 Description
cell 에 formula (엑셀 계산 수식) 정보를 write 한다.

### 5.7.2 Function declaration
```cpp
cell& book::set_formula(const std::string& a_formula,
                        const std::string& a_sheet_name,
                        const unsigned int a_col,
                        const unsigned int a_row,
                        const utility::trace& a_trace = utility::trace());

cell& book::set_formula(const std::string& a_formula,
                        const std::string& a_sheet_name,
                        const unsigned int a_col,
                        const unsigned int a_row,
                        const unsigned int a_merge_across,
                        const unsigned int a_merge_down,
                        const utility::trace& a_trace = utility::trace());

cell& sheet::set_formula(const std::string& a_formula,
                         const unsigned int a_col,
                         const unsigned int a_row,
                         const utility::trace& a_trace = utility::trace());

cell& sheet::set_formula(const std::string& a_formula,
                         const unsigned int a_col,
                         const unsigned int a_row,
                         const unsigned int a_merge_across,
                         const unsigned int a_merge_down,
                         const utility::trace& a_trace = utility::trace());

cell& cell::set_formula(const std::string& a_formula,
                        const utility::trace& a_trace = utility::trace());
```

### 5.7.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_formula | cell 에 넣을 계산 수식 형식의 string 정보이다. |
| const std::string& a_sheet_name | book 내부 의 특정 sheet 를 지정하는 name 이다. |
| const unsigned int a_col | sheet 에서 cell 의 column 위치를 나타낸다. 가장 좌측 column 의 값은 1이다. |
| const unsigned int a_row | sheet 에서 cell 의 row 위치를 나타낸다. 가장 상단 row 의 값은 1이다. |
| const unsigned int a_merge_across | 병합된 cell 을 표현할 때 사용한다. a_col 기준으로 오른쪽으로 병합될 cell 의 개수를 의미한다. |
| const unsigned int a_merge_down | 병합된 cell 을 표현할 때 사용한다. a_row 기준으로 아래쪽으로 병합될 cell 의 개수를 의미한다. |
| const utility::trace& a_trace | 이 정보는 simple_xmlss 동작 중 Error 발생시 throw simple_xmlss::utility::error 를 수행하는데, 이 때 std::string file_name, std::string function_name, std::string line 정보로써 전달 된다. optional 이다. 만약 Degugging 정보를 Detail 하게 전달하기 위해서 해당 parameter 를 전달 한다면 "TRACE()" 매크로를 사용하는 것을 권장한다. |

### 5.7.4 Return / Error
성공시: cell instance 의 reference 를 return 한다. 이는 builder pattern 을 위함이다.

실패시: utility::error instance를 throw 한다.

       case 1) merge 한 cell 에 set_formula 을 시도하는 경우
       
       case 2) 이미 set_string 을 수행한 cell 에 set_formula 을 시도하는 경우
       
       case 3) 이미 set_number 을 수행한 cell 에 set_formula 을 시도하는 경우
       
       case 4) 이미 set_date_time 을 수행한 cell 에 set_formula 을 시도하는 경우
       
       case 5) 이미 set_formula 를 수행한 cell 에 set_formula 을 시도하는 경우

### 5.7.5 Code example & output
TBD


## 5.8 set_comment
### 5.8.1 Description
cell 에 comment 정보를 write 한다.

### 5.8.2 Function declaration
```cpp
cell& book::set_comment(const std::string& a_comment,
                        const std::string& a_sheet_name,
                        const unsigned int a_col,
                        const unsigned int a_row,
                        const utility::trace& a_trace = utility::trace());
                        
cell& book::set_comment(const std::string& a_comment,
                        const unsigned int a_font_id,
                        const std::string& a_sheet_name,
                        const unsigned int a_col,
                        const unsigned int a_row,
                        const utility::trace& a_trace = utility::trace());

cell& book::set_comment(const model::cell_comment& a_comment,
                        const std::string& a_sheet_name,
                        const unsigned int a_col,
                        const unsigned int a_row,
                        const utility::trace& a_trace = utility::trace());

cell& sheet::set_comment(const std::string& a_comment,
                         const unsigned int a_col,
                         const unsigned int a_row,
                         const utility::trace& a_trace = utility::trace());

cell& sheet::set_comment(const std::string& a_comment,
                         const unsigned int a_font_id,
                         const unsigned int a_col,
                         const unsigned int a_row,
                         const utility::trace& a_trace = utility::trace());

cell& sheet::set_comment(const model::cell_comment& a_comment,
                         const unsigned int a_col,
                         const unsigned int a_row,
                         const utility::trace& a_trace = utility::trace());

cell& cell::set_comment(const std::string& a_comment,
                        const utility::trace& a_trace = utility::trace());

cell& cell::set_comment(const std::string& a_comment,
                        const unsigned int a_font_id,
                        const utility::trace& a_trace = utility::trace());

cell& cell::set_comment(const model::cell_comment& a_comment,
                        const utility::trace& a_trace = utility::trace());
```

### 5.8.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_comment | cell의 comment에 넣을 string 정보이다. |
| const model::cell_comment& a_comment | advancedsettings된 cell의 comment 에 넣을 string 정보이다. builder::comment 클래스를 이용하여 구성하는 것을 권장한다. |
| const std::string& a_sheet_name | book 내부 의 특정 sheet 를 지정하는 name 이다. |
| const unsigned int a_col | sheet 에서 cell 의 column 위치를 나타낸다. 가장 좌측 column 의 값은 1이다. |
| const unsigned int a_row | sheet 에서 cell 의 row 위치를 나타낸다. 가장 상단 row 의 값은 1이다. |
| const unsigned int a_merge_across | 병합된 cell 을 표현할 때 사용한다. a_col 기준으로 오른쪽으로 병합될 cell 의 개수를 의미한다. |
| const unsigned int a_merge_down | 병합된 cell 을 표현할 때 사용한다. a_row 기준으로 아래쪽으로 병합될 cell 의 개수를 의미한다. |
| const utility::trace& a_trace | 이 정보는 simple_xmlss 동작 중 Error 발생시 throw simple_xmlss::utility::error 를 수행하는데, 이 때 std::string file_name, std::string function_name, std::string line 정보로써 전달 된다. optional 이다. 만약 Degugging 정보를 Detail 하게 전달하기 위해서 해당 parameter 를 전달 한다면 "TRACE()" 매크로를 사용하는 것을 권장한다. |

### 5.8.4 Return / Error
성공시: cell instance 의 reference 를 return 한다. 이는 builder pattern 을 위함이다.

실패시: utility::error instance를 throw 한다.

       case 1) merge 한 cell 에 set_comment 을 시도하는 경우
       
       case 2) 이미 set_comment 을 수행한 cell 에 set_comment 을 시도하는 경우

### 5.8.5 Code example & output
TBD


## 5.9 set_hyperlink
### 5.9.1 Description
cell 에 Hyperlink 정보를 write 한다.

### 5.9.2 Function declaration
```cpp
cell& book::set_hyperlink(const std::string& a_hyper_link_url,
                          const std::string& a_sheet_name,
                          const unsigned int a_col,
                          const unsigned int a_row,
                          const utility::trace& a_trace = utility::trace());

cell& book::set_hyperlink(const std::string &a_hyperlink_sheet_name,
                          const unsigned int a_hyperlink_col,
                          const unsigned int a_hyperlink_row,
                          const std::string& a_sheet_name,
                          const unsigned int a_col,
                          const unsigned int a_row,
                          const utility::trace& a_trace = utility::trace());

cell& sheet::set_hyperlink(const std::string& a_hyper_link_url,
                           const unsigned int a_col,
                           const unsigned int a_row,
                           const utility::trace& a_trace = utility::trace());

cell& sheet::set_hyperlink(const std::string &a_hyperlink_sheet_name,
                           const unsigned int a_hyperlink_col,
                           const unsigned int a_hyperlink_row,
                           const unsigned int a_col,
                           const unsigned int a_row,
                           const utility::trace& a_trace = utility::trace());

cell& cell::set_hyperlink(const std::string &a_hyperlink_sheet_name,
                          const unsigned int a_hyperlink_col,
                          const unsigned int a_hyperlink_row,
                          const utility::trace& a_trace = utility::trace());

cell& cell::set_hyperlink(const std::string& a_hyper_link_url,
                          const utility::trace& a_trace = utility::trace());
```

### 5.9.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_hyper_link_url | cell의 hyper link url 정보 |
| const std::string& a_sheet_name | book 내부 의 특정 sheet 를 지정하는 name 이다. |
| const unsigned int a_col | sheet 에서 cell 의 column 위치를 나타낸다. 가장 좌측 column 의 값은 1이다. |
| const unsigned int a_row | sheet 에서 cell 의 row 위치를 나타낸다. 가장 상단 row 의 값은 1이다. |
| const std::string &a_hyperlink_sheet_name | 동일 book 내의 다른 시트로 hyperlink 할 경우 해당 sheet 의 name |
| const unsigned int a_hyperlink_col | 동일 book 내의 다른 시트로 hyperlink 할 경우 해당 sheet 의 col |
| const unsigned int a_hyperlink_row | 동일 book 내의 다른 시트로 hyperlink 할 경우 해당 sheet 의 row |
| const utility::trace& a_trace | 이 정보는 simple_xmlss 동작 중 Error 발생시 throw simple_xmlss::utility::error 를 수행하는데, 이 때 std::string file_name, std::string function_name, std::string line 정보로써 전달 된다. optional 이다. 만약 Degugging 정보를 Detail 하게 전달하기 위해서 해당 parameter 를 전달 한다면 "TRACE()" 매크로를 사용하는 것을 권장한다. |

### 5.9.4 Return / Error
성공시: cell instance 의 reference 를 return 한다. 이는 builder pattern 을 위함이다.

실패시: utility::error instance를 throw 한다.

       case 1) merge 한 cell 에 set_hyperlink 를 시도하는 경우
       
       case 2) 해당 cell 에 string, number,, date/time, formula 가 설정 되어 있지 않은 경우

### 5.9.5 Code example & output
TBD


## 5.10 set_style_id
### 5.10.1 Description
cell 의 style을 설정 한다.

### 5.10.2 Function declaration
```cpp
cell& book::set_style_id(const unsigned int a_style_id,
                         const std::string& a_sheet_name,
                         const unsigned int a_col,
                         const unsigned int a_row,
                         const utility::trace& a_trace = utility::trace());

cell& sheet::set_style_id(const unsigned int a_style_id,
                          const unsigned int a_col,
                          const unsigned int a_row,
                          const utility::trace& a_trace = utility::trace());

cell& cell::set_style_id(const unsigned int a_style_id,
                         const utility::trace& a_trace = utility::trace());set_row_height
```

### 5.10.3 Argument
| Argument name | Argument description |
|------|------|
| const unsigned int a_style_id | builder::style 클래스를 이용하여 생성한 style id 정보이다.  |
| const std::string& a_sheet_name | book 내부 의 특정 sheet 를 지정하는 name 이다. |
| const unsigned int a_col | sheet 에서 cell 의 column 위치를 나타낸다. 가장 좌측 column 의 값은 1이다. |
| const unsigned int a_row | sheet 에서 cell 의 row 위치를 나타낸다. 가장 상단 row 의 값은 1이다. |
| const utility::trace& a_trace | 이 정보는 simple_xmlss 동작 중 Error 발생시 throw simple_xmlss::utility::error 를 수행하는데, 이 때 std::string file_name, std::string function_name, std::string line 정보로써 전달 된다. optional 이다. 만약 Degugging 정보를 Detail 하게 전달하기 위해서 해당 parameter 를 전달 한다면 "TRACE()" 매크로를 사용하는 것을 권장한다. |

### 5.10.4 Return / Error
성공시: cell instance 의 reference 를 return 한다. 이는 builder pattern 을 위함이다.

실패시: utility::error instance를 throw 한다.

       case 1) merge 한 cell 에 set_style_id 을 시도하는 경우

### 5.10.5 Code example & output
TBD


## 5.11 set_row_height
### 5.11.1 Description
sheet 의 특정 row 에 대한 높이를 지정한다.

### 5.11.2 Function declaration
```cpp
sheet& book::set_row_height(const unsigned int a_row,
                            const float a_height,
                            const std::string& a_sheet_name,
                            const utility::trace& a_trace = utility::trace());

sheet& sheet::set_row_height(const unsigned int a_row,
                             const float a_height,
                             const utility::trace& a_trace = utility::trace());
```

### 5.11.3 Argument
| Argument name | Argument description |
|------|------|
| const unsigned int a_row | sheet 에서 높이를 설정할 cell 의 row 위치를 나타낸다. 가장 상단 row 의 값은 1이다. |
| const float a_height | 높이 값  |
| const std::string& a_sheet_name | book 내부 의 특정 sheet 를 지정하는 name 이다. |
| const utility::trace& a_trace | 이 정보는 simple_xmlss 동작 중 Error 발생시 throw simple_xmlss::utility::error 를 수행하는데, 이 때 std::string file_name, std::string function_name, std::string line 정보로써 전달 된다. optional 이다. 만약 Degugging 정보를 Detail 하게 전달하기 위해서 해당 parameter 를 전달 한다면 "TRACE()" 매크로를 사용하는 것을 권장한다. |

### 5.11.4 Return / Error
성공시: sheet instance 의 reference 를 return 한다. 이는 builder pattern 을 위함이다.

실패시: utility::error instance를 throw 한다.

       case 1) 이미 set_row_height를 수행한 곳에 다시 set_row_height를 시도하는 경우.

### 5.11.5 Code example & output
TBD


## 5.12 set_col_width
### 5.12.1 Description
sheet 의 특정 column 에 대한 너비를 지정한다.

### 5.12.2 Function declaration
```cpp
sheet& book::set_col_width(const unsigned int a_col,
                           const float a_width,
                           const std::string& a_sheet_name,
                           const utility::trace& a_trace = utility::trace());

sheet& sheet::set_col_width(const unsigned int a_col,
                            const float a_width,
                            const utility::trace& a_trace = utility::trace());
```

### 5.12.3 Argument
| Argument name | Argument description |
|------|------|
| const unsigned int a_col | sheet 에서 너비를 설정할 cell 의 column 위치를 나타낸다. 가장 좌측 column 의 값은 1이다. |
| const float a_width | 너비 값  |
| const std::string& a_sheet_name | book 내부 의 특정 sheet 를 지정하는 name 이다. |
| const utility::trace& a_trace | 이 정보는 simple_xmlss 동작 중 Error 발생시 throw simple_xmlss::utility::error 를 수행하는데, 이 때 std::string file_name, std::string function_name, std::string line 정보로써 전달 된다. optional 이다. 만약 Degugging 정보를 Detail 하게 전달하기 위해서 해당 parameter 를 전달 한다면 "TRACE()" 매크로를 사용하는 것을 권장한다. |

### 5.12.4 Return / Error
성공시: sheet instance 의 reference 를 return 한다. 이는 builder pattern 을 위함이다.

실패시: utility::error instance를 throw 한다.

       case 1) 이미 set_col_width 를 수행한 곳에 다시 set_col_width 를 시도하는 경우.

### 5.12.5 Code example & output
TBD


## 5.13 print_xmlss
### 5.13.1 Description
book 에 저장된 데이들을 xmlss 형식으로 파일에 write 한다.

### 5.13.2 Function declaration
```cpp
void book::print_xmlss(const std::string& a_file_name,
                                       const utility::trace& a_trace = utility::trace());
```

### 5.13.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_file_name | spread sheet로 저장될 file name |
| const utility::trace& a_trace | 이 정보는 simple_xmlss 동작 중 Error 발생시 throw simple_xmlss::utility::error 를 수행하는데, 이 때 std::string file_name, std::string function_name, std::string line 정보로써 전달 된다. optional 이다. 만약 Degugging 정보를 Detail 하게 전달하기 위해서 해당 parameter 를 전달 한다면 "TRACE()" 매크로를 사용하는 것을 권장한다. |


# 6. builder::font class & member function
## 6.1 instance
### 6.1.1 Description
builder::font class 의 singleton instance를 가져온다.

### 6.1.2 Function declaration
```cpp
namespace builder {
static font& font::instance(void);
}
```

## 6.2 build
### 6.2.1 Description
builder::font class 에 저장된 member 변수 데이터를 이용하여 model::font 를 build(std::map 에 insert) 하고 build 한 id 를 return 한다.

### 6.2.2 Function declaration
```cpp
namespace builder {
unsigned int font::build(void);
}
```

### 6.2.3 Return
font id 를 return 한다. 이 font id 는 set_string 등의 argument로써 사용할 수 있다.

### 6.2.4 Code example & output
TBD


## 6.3 clear
### 6.3.1 Description
builder::font class 에 저장된 member 변수 데이터를 clear 한다.

### 6.3.2 Function declaration
```cpp
namespace builder {
font& font::clear(void);
}
```

### 6.3.3 Return
font singleton instance 의 reference 를 return 한다.

### 6.3.4 Code example & output
TBD


## 6.4 set_name
### 6.4.1 Description
builder::font class 의 member 변수에 name 을 set 한다. 

### 6.4.2 Function declaration
```cpp
namespace builder {
font& font::set_name(const std::string& a_name);
}
```

### 6.4.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_name | font 의 이름 |

### 6.4.4 Return
font singleton instance 의 reference 를 return 한다.

### 6.4.5 Code example & output
TBD


## 6.5 set_char_set
### 6.5.1 Description
builder::font class 의 member 변수에 char set 을 지정한다.

### 6.5.2 Function declaration
```cpp
namespace builder {
font& font::set_char_set(const model::FONT_CHAR_SET a_char_set);
}
```

### 6.5.3 Argument
| Argument name | Argument description |
|------|------|
| const model::FONT_CHAR_SET a_char_set | char set 의 enum |

```cpp
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

}
```

### 6.5.4 Return
font singleton instance 의 reference 를 return 한다.

### 6.5.5 Code example & output
TBD


## 6.6 set_family_name
### 6.6.1 Description
builder::font class 의 member 변수에 font 의 family name 을 설정 한다.

### 6.6.2 Function declaration
```cpp
namespace builder {
font& font::set_family_name(const std::string& a_family_name)
}
```

### 6.6.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_family_name | font 의 family name |

### 6.6.4 Return
font singleton instance 의 reference 를 return 한다.

### 6.6.5 Code example & output
TBD


## 6.7 set_color
### 6.7.1 Description
builder::font class 의 member 변수에 font color 를 설정한다.

### 6.7.2 Function declaration
```cpp
namespace builder {
font& font::set_color(const std::string& a_color);
}
```

### 6.7.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_color | font 의 rgb color 를 지정 |

### 6.7.4 Return
font singleton instance 의 reference 를 return 한다.

### 6.7.5 Code example & output
TBD


## 6.8 set_size
### 6.8.1 Description
builder::font class 의 member 변수에 font size 를 설정한다.

### 6.8.2 Function declaration
```cpp
namespace builder {
font& font::set_size(const unsigned int a_size);
}
```

### 6.8.3 Argument
| Argument name | Argument description |
|------|------|
| const unsigned int a_size | font 의 size 값 |

### 6.8.4 Return
font singleton instance 의 reference 를 return 한다.

### 6.8.5 Code example & output
TBD


## 6.9 set_underline
### 6.9.1 Description
builder::font class 의 member 변수에 underline 속성을 설정한다.

### 6.9.2 Function declaration
```cpp
namespace builder {
font& font::set_underline(const model::FONT_UNDERLINE a_underline);
}
```

### 6.9.3 Argument
| Argument name | Argument description |
|------|------|
| const model::FONT_UNDERLINE a_underline | font 의 underline 속성 |

```cpp
namespace model {

enum class FONT_UNDERLINE {
  NONE = 0,
  SINGLE = 1,
  DOUBLE = 2,
  SINGLE_ACCOUNTING = 3,
  DOUBLE_ACCOUNTING = 4,
};

}
```

### 6.9.4 Return
font singleton instance 의 reference 를 return 한다.

### 6.9.5 Code example & output
TBD


## 6.10 set_superscript_subscript
### 6.10.1 Description
builder::font class 의 member 변수에 superscript, subscript 속성을 지정한다.

### 6.10.2 Function declaration
```cpp
namespace builder {
font& font::set_superscript_subscript(const model::FONT_SUPERSCRIPT_SUBSCRIPT a_superscript_subscript);
}
```

### 6.10.3 Argument
| Argument name | Argument description |
|------|------|
| const model::FONT_SUPERSCRIPT_SUBSCRIPT a_superscript_subscript | font 의 superscript, subscript 속성 |

```cpp
namespace model {

enum class FONT_SUPERSCRIPT_SUBSCRIPT {
  NONE = 0,
  SUPERSCRIPT = 1,
  SUBSCRIPT = 2,
};

}
```

### 6.10.4 Return
font singleton instance 의 reference 를 return 한다.

### 6.10.5 Code example & output
TBD


## 6.11 set_italic
### 6.11.1 Description
builder::font class 의 member 변수에 italic 여부를 지정한다.

### 6.11.2 Function declaration
```cpp
namespace builder {
font& font::set_italic(const bool a_italic);
}
```

### 6.11.3 Argument
| Argument name | Argument description |
|------|------|
| const bool a_italic | font 의 italic 여부 |

### 6.11.4 Return
font singleton instance 의 reference 를 return 한다.

### 6.11.5 Code example & output
TBD


## 6.12 set_bold
### 6.12.1 Description
builder::font class 의 member 변수에 bold 여부를 지정한다.

### 6.12.2 Function declaration
```cpp
namespace builder {
font& font::set_bold(const bool a_bold);
}
```

### 6.12.3 Argument
| Argument name | Argument description |
|------|------|
| const bool a_bold | font 의 bold 여부 |

### 6.12.4 Return
font singleton instance 의 reference 를 return 한다.

### 6.12.5 Code example & output
TBD


## 6.13 set_strikethrough
### 6.13.1 Description
builder::font class 의 member 변수에 strikethrough 여부를 지정한다.

### 6.13.2 Function declaration
```cpp
namespace builder {
font& font::set_strikethrough(const bool a_strikethrough);
}
```

### 6.13.3 Argument
| Argument name | Argument description |
|------|------|
| const bool a_strikethrough | font 의 strikethrough 여부 |

### 6.13.4 Return
font singleton instance 의 reference 를 return 한다.

### 6.13.5 Code example & output
TBD


# 7. builder::style class & member function
## 7.1 instance
### 7.1.1 Description
builder::style class 의 singleton instance를 가져온다.

### 7.1.2 Function declaration
```cpp
namespace builder {
static style& style::instance(void);
}
```

## 7.2 build
### 7.2.1 Description
builder::style class 에 저장된 member 변수 데이터를 이용하여 model::style 를 build(std::map 에 insert) 하고 build 한 id 를 return 한다.

### 7.2.2 Function declaration
```cpp
namespace builder {
unsigned int style::build(void);
}
```

### 7.2.3 Return
style id 를 return 한다. 이 style id 는 set_style_id의 argument로써 사용할 수 있다.

### 7.2.4 Code example & output
TBD


## 7.3 clear
### 7.3.1 Description
builder::style class 에 저장된 member 변수 데이터를 clear 한다.

### 7.3.2 Function declaration
```cpp
namespace builder {
style& style::clear(void);
}
```

### 7.3.3 Return
style singleton instance 의 reference 를 return 한다.

### 7.3.4 Code example & output
TBD


## 7.4 set_number_format
### 7.4.1 Description
builder::style class 의 member 변수에 number format 을 설정한다.

### 7.4.2 Function declaration
```cpp
namespace builder {
style& style::set_number_format(const std::string& a_format);
}
```

### 7.4.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_format | number format string 을 지정한다. |

### 7.4.4 Return
style singleton instance 의 reference 를 return 한다.

### 7.4.5 Code example & output
TBD


## 7.5 set_number_comma
### 7.5.1 Description
builder::style class 의 member 변수에 number 형식에 콤마 설정 여부를 지정한다.

### 7.5.2 Function declaration
```cpp
namespace builder {
style& style::set_number_comma(const bool a_number_comma_flag);
}
```

### 7.5.3 Argument
| Argument name | Argument description |
|------|------|
| const bool a_number_comma_flag | 숫자 형식에 콤마 설정 여부를 전달함. |

### 7.5.4 Return
style singleton instance 의 reference 를 return 한다.

### 7.5.5 Code example & output
TBD


## 7.6 set_alignment_horizontal
### 7.6.1 Description
builder::style class 의 member 변수에 가로 방향의 alignment(정렬) 속성을 지정한다.

### 7.6.2 Function declaration
```cpp
namespace builder {
style& style::set_alignment_horizontal(const model::STYLE_ALIGNMENT_HORIZONTAL a_horizontal);
}
```

### 7.6.3 Argument
| Argument name | Argument description |
|------|------|
| const model::STYLE_ALIGNMENT_HORIZONTAL a_horizontal | style 의 가로 방향 alignment 속성. |

```cpp
namespace model {

enum class STYLE_ALIGNMENT_HORIZONTAL {
  NONE = 0,
  LEFT = 1,
  CENTER = 2,
  RIGHT = 3,
  FILL = 4,
  JUSTIFY = 5,
  CENTER_ACROSS_SELECTION = 6,
  DISTRIBUTED = 7,
};

}
```

### 7.6.4 Return
style singleton instance 의 reference 를 return 한다.

### 7.6.5 Code example & output
TBD


## 7.7 set_alignment_horizontal_indent
### 7.7.1 Description
builder::style class 의 member 변수에 가로 방향 alignment 의 offset 속성을 지정 한다.

### 7.7.2 Function declaration
```cpp
namespace builder {
style& style::set_alignment_horizontal_indent(const unsigned int a_indent);
}
```

### 7.7.3 Argument
| Argument name | Argument description |
|------|------|
| const unsigned int a_indent | 가로 방향의 alignment 의 ffset 값 |

### 7.7.4 Return
style singleton instance 의 reference 를 return 한다.

### 7.7.5 Code example & output
TBD


## 7.8 set_alignment_vertical
### 7.8.1 Description
builder::style class 의 member 변수에 세로 방향의 alignment(정렬) 속성을 지정한다.

### 7.8.2 Function declaration
```cpp
namespace builder {
style& style::set_alignment_vertical(const model::STYLE_ALIGNMENT_VERTICAL a_vertical);
}
```

### 7.8.3 Argument
| Argument name | Argument description |
|------|------|
| const model::STYLE_ALIGNMENT_VERTICAL a_vertical | style 의 세로 방향 alignment 속성. |

```cpp
namespace model {

enum class STYLE_ALIGNMENT_VERTICAL {
  NONE = 0,
  TOP = 1,
  CENTER = 2,
  BOTTOM = 3,
  JUSTIFY = 4,
  DISTRIBUTED = 5,
};

}
```

### 7.8.4 Return
style singleton instance 의 reference 를 return 한다.

### 7.8.5 Code example & output
TBD


## 7.9 set_alignment_text_control
### 7.9.1 Description
builder::style class 의 member 변수에 text control 속성을 지정한다.

### 7.9.2 Function declaration
```cpp
namespace builder {
style& style::set_alignment_text_control(const model::STYLE_ALIGNMENT_TEXT_CONTROL a_text_control);
}
```

### 7.9.3 Argument
| Argument name | Argument description |
|------|------|
| const model::STYLE_ALIGNMENT_TEXT_CONTROL a_text_control | style 의 text control 속성. |

```cpp
namespace model {

enum class STYLE_ALIGNMENT_TEXT_CONTROL {
  NONE = 0,
  WRAP_TEXT = 1,
  SHRINK_TO_FIT = 2,
};

}
```

### 7.9.4 Return
style singleton instance 의 reference 를 return 한다.

### 7.9.5 Code example & output
TBD


## 7.10 set_alignment_rotate
### 7.10.1 Description
builder::style class 의 member 변수에 text 의 rotate 각도 정보를 저장한다.

### 7.10.2 Function declaration
```cpp
namespace builder {
style& style::set_alignment_rotate(const int a_rotate,
                                   const utility::trace& a_trace = utility::trace());
}
```

### 7.10.3 Argument
| Argument name | Argument description |
|------|------|
| const unsigned int a_rotate | text 의 rotate 각도 -90~90 사이의 숫자 |
| const utility::trace& a_trace | 이 정보는 simple_xmlss 동작 중 Error 발생시 throw simple_xmlss::utility::error 를 수행하는데, 이 때 std::string file_name, std::string function_name, std::string line 정보로써 전달 된다. optional 이다. 만약 Degugging 정보를 Detail 하게 전달하기 위해서 해당 parameter 를 전달 한다면 "TRACE()" 매크로를 사용하는 것을 권장한다. |

### 7.10.4 Return
성공시: style singleton instance 의 reference 를 return 한다.

실패시: utility::error instance를 throw 한다.

       case 1) 전달되는 값이 -90 ~ 90 사이의 숫자가 아닐 경우
       

### 7.10.5 Code example & output
TBD


## 7.11 set_font_id
### 7.11.1 Description
builder::style class 의 member 변수에 font id 를 설정한다.

### 7.11.2 Function declaration
```cpp
namespace builder {
style& style::set_font_id(const unsigned int a_font_id);
}
```

### 7.11.3 Argument
| Argument name | Argument description |
|------|------|
| const unsigned int a_font_id | font id 를 설정 한다. 이 font id 는 builder::font에서 build 한 값을 사용한다. |

### 7.11.4 Return
style singleton instance 의 reference 를 return 한다.

### 7.11.5 Code example & output
TBD


## 7.12 set_default_borders
### 7.12.1 Description
builder::style class 의 member 변수의 boarder 를 default 로 설정한다 (검은색 선을 사용하여 상,하,좌,우의 box 형태)

### 7.13.2 Function declaration
```cpp
namespace builder {
style& style::set_default_borders(void);
}
```

### 7.13.3 Return
style singleton instance 의 reference 를 return 한다.

### 7.13.4 Code example & output
TBD


## 7.14 set_border_color
### 7.14.1 Description
builder::style class 의 member 변수에 border 의 line color 를 설정한다.

### 7.14.2 Function declaration
```cpp
namespace builder {
style& style::set_border_color(const model::STYLE_BORDER_POSITION a_position,
                               const std::string &a_color);
}
```

### 7.14.3 Argument
| Argument name | Argument description |
|------|------|
| const model::STYLE_BORDER_POSITION a_position | border 의 위치. |
| const std::string &a_color | border 의 RGB 색깔 값. |

```cpp
namespace model {

enum class STYLE_BORDER_POSITION {
  NONE = 0,
  LEFT = 1,
  TOP = 2,
  RIGHT = 3,
  BOTTOM = 4,
  DIAGONAL_RIGHT = 5,
  DIAGONAL_LEFT = 6,
};

}
```

### 7.14.4 Return
style singleton instance 의 reference 를 return 한다.

### 7.14.5 Code example & output
TBD


## 7.15 set_border_line_type
### 7.15.1 Description
builder::style class 의 member 변수에 border 의 line 형식을 지정한다.

### 7.15.2 Function declaration
```cpp
namespace builder {
style& style::set_border_line_type(const model::STYLE_BORDER_POSITION a_position,
                                   const model::STYLE_BORDER_LINE_TYPE a_line_type);
}
```

### 7.15.3 Argument
| Argument name | Argument description |
|------|------|
| const model::STYLE_BORDER_POSITION a_position | border 의 위치. |
| const model::STYLE_BORDER_LINE_TYPE a_line_type | border 의 속성. |

```cpp
namespace model {

enum class STYLE_BORDER_POSITION {
  NONE = 0,
  LEFT = 1,
  TOP = 2,
  RIGHT = 3,
  BOTTOM = 4,
  DIAGONAL_RIGHT = 5,
  DIAGONAL_LEFT = 6,
};

enum class STYLE_BORDER_LINE_TYPE {
  NONE = 0,
  DOT = 1,
  DASHDOTDOT = 2,
  DASHDOT = 3,
  DASH = 4,
  CONTINUOUS = 5,
  SLANTDASHDOT = 6,
  DOUBLE = 7,
};

}
```

### 7.15.4 Return
style singleton instance 의 reference 를 return 한다.

### 7.15.5 Code example & output
TBD


## 7.16 set_border_weight
### 7.16.1 Description
builder::style class 의 member 변수에 border 의 weight 를 저장한다.

### 7.16.2 Function declaration
```cpp
namespace builder {
style& set_border_weight(const model::STYLE_BORDER_POSITION a_position,
                         const model::STYLE_BORDER_WEIGHT a_weight);
}
```

### 7.16.3 Argument
| Argument name | Argument description |
|------|------|
| const model::STYLE_BORDER_POSITION a_position | border 의 위치. |
| const model::STYLE_BORDER_WEIGHT a_weight | border 의 weight 값. |

```cpp
namespace model {

enum class STYLE_BORDER_POSITION {
  NONE = 0,
  LEFT = 1,
  TOP = 2,
  RIGHT = 3,
  BOTTOM = 4,
  DIAGONAL_RIGHT = 5,
  DIAGONAL_LEFT = 6,
};

enum class STYLE_BORDER_WEIGHT {
  HAIRLINE = 0,
  THIN = 1,
  MEDIUM = 2,
  THICK = 3,
};

}
```

### 7.16.4 Return
style singleton instance 의 reference 를 return 한다.

### 7.16.5 Code example & output
TBD


## 7.17 set_fill_background_color
### 7.17.1 Description
builder::style class 의 member 변수에 바탕 color 를 설정한다.

### 7.17.2 Function declaration
```cpp
namespace builder {
style& style::set_fill_background_color(const std::string& a_color);
}
```

### 7.17.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_color | 바탕(cell 의 바탕) color RGB 값  |

### 7.17.4 Return
style singleton instance 의 reference 를 return 한다.

### 7.17.5 Code example & output
TBD


## 7.18 set_fill_pattern_color
### 7.18.1 Description
builder::style class 의 member 변수에 pattern color 를 설정한다.

### 7.18.2 Function declaration
```cpp
namespace builder {
style& style::set_fill_pattern_color(const std::string& a_color);
}
```

### 7.18.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_color | cell 의 pattern color RGB 값  |

### 7.18.4 Return
style singleton instance 의 reference 를 return 한다.

### 7.18.5 Code example & output
TBD


## 7.19 set_fill_pattern_style
### 7.19.1 Description
builder::style class 의 member 변수에 cell 의 pattern style 을 지정한다.

### 7.19.2 Function declaration
```cpp
namespace builder {
style& set_fill_pattern_style(model::STYLE_FILL_PATTERN a_pattern);
}
```

### 7.19.3 Argument
| Argument name | Argument description |
|------|------|
| const model::STYLE_FILL_PATTERN a_pattern | pattern 의 종류 |

```cpp
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

}
```

### 7.19.4 Return
style singleton instance 의 reference 를 return 한다.

### 7.19.5 Code example & output
TBD


# 8. builder::string class & member function
## 8.1 instance
### 8.1.1 Description
builder::string class 의 singleton instance를 가져온다.

### 8.1.2 Function declaration
```cpp
namespace builder {
static string& string::instance(void);
}
```

## 8.2 build
### 8.2.1 Description
builder::string class 에 저장된 member 변수 데이터를 이용하여 model::cell_string 를 만들어서 return 한다.

### 8.2.2 Function declaration
```cpp
namespace builder {
const model::cell_string& string::build(void);
}
```

### 8.2.3 Return
model::cell_string 를 return 한다. 이 model::cell_string 는 set_string 의 argument로써 사용할 수 있다.

### 8.2.4 Code example & output
TBD


## 8.3 clear
### 8.3.1 Description
builder::string class 에 저장된 member 변수 데이터를 clear 한다.

### 8.3.2 Function declaration
```cpp
namespace builder {
string& string::clear(void);
}
```

### 8.3.3 Return
string singleton instance 의 reference 를 return 한다.

### 8.3.4 Code example & output
TBD


## 8.4 set_string
### 8.4.1 Description
builder::string class 의 member 변수에 string 을 add 한다.

### 8.4.2 Function declaration
```cpp
namespace builder {
string& string::set_string(const std::string& a_string);
string& string::set_string(const std::string& a_string,
                           const unsigned int a_font_id);
}
```

### 8.4.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_string | cell 에 넣을 string 값 |
| const unsigned int a_font_id | string 에 mapping 되는 font id. builder::font로 만들어진 값을 사용한다. |

### 8.4.4 Return
string singleton instance 의 reference 를 return 한다.

### 8.4.5 Code example & output
TBD


# 9. builder::comment class & member function
## 9.1 instance
### 9.1.1 Description
builder::comment class 의 singleton instance를 가져온다.

### 9.1.2 Function declaration
```cpp
namespace builder {
static comment& comment::instance(void);
}
```

## 9.2 build
### 9.2.1 Description
builder::comment class 에 저장된 member 변수 데이터를 이용하여 model::cell_comment 를 만들어서 return 한다.

### 9.2.2 Function declaration
```cpp
namespace builder {
const model::cell_comment& comment::build(void);
}
```

### 9.2.3 Return
model::cell_comment 를 return 한다. 이 model::cell_comment 는 set_comment 의 argument로써 사용할 수 있다.

### 9.2.4 Code example & output
TBD


## 9.3 clear
### 9.3.1 Description
builder::comment class 에 저장된 member 변수 데이터를 clear 한다.

### 9.3.2 Function declaration
```cpp
namespace builder {
comment& comment::clear(void);
}
```

### 9.3.3 Return
string singleton instance 의 reference 를 return 한다.

### 9.3.4 Code example & output
TBD


## 9.4 set_comment
### 9.4.1 Description
builder::comment class 의 member 변수에 comment를 add 한다.

### 9.4.2 Function declaration
```cpp
namespace builder {
comment& comment::set_comment(const std::string& a_comment);
comment& comment::set_comment(const std::string& a_comment,
                              const unsigned int a_font_id);
}
```

### 9.4.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_comment | cell 에 넣을 comment 값 |
| const unsigned int a_font_id | comment 에 mapping 되는 font id. builder::font로 만들어진 값을 사용한다. |

### 9.4.4 Return
comment singleton instance 의 reference 를 return 한다.

### 9.4.5 Code example & output
TBD


## 9.5 set_author
### 9.5.1 Description
builder::comment class 의 member 변수에 author 를 지정한다.

### 9.5.2 Function declaration
```cpp
namespace builder {
comment& comment::set_author(const std::string& a_author,
                             const utility::trace& a_trace = utility::trace());
comment& comment::set_author(const std::string& a_author,
                             const unsigned int a_font_id,
                             const utility::trace& a_trace = utility::trace());
}
```

### 9.5.3 Argument
| Argument name | Argument description |
|------|------|
| const std::string& a_author | cell 에 넣을 comment 의 author 값 |
| const unsigned int a_font_id | comment 에 mapping 되는 font id. builder::font로 만들어진 값을 사용한다. |
| const utility::trace& a_trace | 이 정보는 simple_xmlss 동작 중 Error 발생시 throw simple_xmlss::utility::error 를 수행하는데, 이 때 std::string file_name, std::string function_name, std::string line 정보로써 전달 된다. optional 이다. 만약 Degugging 정보를 Detail 하게 전달하기 위해서 해당 parameter 를 전달 한다면 "TRACE()" 매크로를 사용하는 것을 권장한다. |

### 9.5.4 Return
성공시: comment singleton instance 의 reference 를 return 한다.

실패시: utility::error instance를 throw 한다.
       
       case 1) 이미 set_author 을 수행한 뒤 다시 set_author 를 수행한 경우 (clear 를 수행하면 set_author 값이 clear 된다.)



### 9.5.5 Code example & output
TBD