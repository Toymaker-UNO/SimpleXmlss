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
TBD


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

## 6.2 initialize
### 6.2.1 Description
builder::font class 의 member 변수를 초기화 한다.

### 6.2.2 Function declaration
```cpp
namespace builder {
void font::initialize(void);
}
```
