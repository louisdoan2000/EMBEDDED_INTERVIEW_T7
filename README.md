# EMBEDDED_INTERVIEW_T7

## 1. C Basic 
**1.1 Typedef**
**1.2 Struct**
**1.3 For**
**1.4 While**
**1.5 Do**
**1.6 If Else**
**1.7 Switch case**


## 2. Pointer

**2.1 Con trỏ**
- Là một biến mà nó lưu địa chỉ của những biến khác

Ex 1:

![Alt text](image.png)

- Biến number có giá trị là 50, địa chỉ là fff4
- Trong đó p là biến con trỏ trỏ đến địa chỉ fff4 của biến number

Ex 2:
```c
#include <stdio.h>

int a = 10;

void test(){
    printf("this is test\n");
}
int main(int argc, char const *argv[])
{
    int *ptr = &a;
    printf("dia chi %p\n", &test); 
    printf("dia chi a %p\n", &a );

    printf("gia tri ptr %p\n", ptr);

    printf("gia tri cua bien ma con tro dang quan li %d ", *ptr);
    return 0;
}
```


**Kích thước con trỏ**
Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là **như nhau**. Kích thước này phụ thuộc vào môi trường hệ thống máy tính:
- Môi trường Windows 32 bit: 4 bytes
- Môi trường Windows 64 bit: 8 bytes
```c
int main(int argc, char const *argv[])
{

void *ptr= &tong;
printf("size: %d\n", sizeof(ptr));
// Kích thước biến con trỏ phụ thuộc vào kiến trúc của vi xử lí
//64 /8bit = 8 byte
//32/8 = 4

return 0;
}
```


**2.2 Con trỏ Void (Void Pointer)**

- Con trỏ void là con trỏ đặc biệt, có thể trỏ đến mọi địa chỉ
- Dùng con trỏ void thì phải ép kiểu
```c
int main(int argc, char const *argv[])
{
    int i = 10;
    double d = 10.3;
    char c = 'A';
    //int *ptr = &d; : máy sẽ báo lỗi vì không cùng kiểu dữ liệu  
    void *ptr; // là con trỏ đặc biệt, nó sẽ trỏ đến địa chỉ của mọi đối tượng không cần biết đó là kiểu dữ liệu gì 
    ptr = &i; 
    // printf(" gia tri cua ptr %p\n", *ptr); : in ra lỗi vì nó chỉ biết địa chỉ của i chứ không biết nó mang kiểu dữ liệu gì nên ta phải ÉP KIỂU
    printf("test i = %d\n", *(int*)ptr ); // (int*)ptr: giá trị của địa chỉ này là kiểu integer   
    ptr = &d;
    printf("test d = %f\n", *(double*)ptr);
    ptr = &c;
    printf("test c = %c\n", *(char*)ptr);
 return 0;
}

```
**2.3 Function Pointer**
- Trỏ đến địa chỉ của hàm
- Dùng để gọi hàm thông qua con trỏ
`kiểu trả về hàm(*tên con trỏ hàm)(kiểu input, kiểu input )`
Ex:
```c
// con trỏ hàm sẽ trỏ đến địa chỉ của hàm
void tong(int a, int b){
    printf("tong %d va %d = %d\n", a, b, a+b);
}

void hieu(int a, int b){
    printf("hieu %d va %d = %d\n", a, b, a-b);
}

int tich(int a, int b){
    return a*b;
}
int main(int argc, char const *argv[])
{
    void(*ptr)(int,int); 
    ptr = &tong;
    ptr(8,7);
    ptr = &hieu;
    ptr(10,6);
    
    int (*ptrtich)(int,int) = &tich; // Con trỏ ptr trỏ tới hàm tích
    printf("tich %d\n", ptrtich(6,5));
    return 0;
}

```
**2.3.1 Con trỏ hàm làm input parameter**

```c
// con trỏ hàm sẽ trỏ đến địa chỉ của hàm
//input là 1 hàm dùng 1 con trỏ hàm
// cú pháp: void tenham(void(*tencontro)(kieu dau vao, kieu dau vao), tham so dau vao, tham so dau vao)
void tinhtoan(void(*func)(int, int), int a, int b ){
    printf("Tinh toan\n");
    func(a,b);
}
int main(int argc, char const *argv[])
{
  tinhtoan(&tong, 4, 9);   
  tinhtoan(&hieu, 8, 2);
  tinhtoan(&tich, 2, 6);
    return 0;
}

```
**2.3.2 Dùng con trỏ void trỏ đến địa chỉ của con trỏ hàm để hiển thị**
```c
void *ptr = &tong;
((void(*)(int,int))ptr)(7,5);

```


**2.4 Con trỏ NULL**
- Là con trỏ có địa chỉ và giá trị bằng 0
- Vì khai báo con trỏ bất kì thò phải có giá trị nếu không thì con trỏ sẽ trỏ tới giá trị rác
Ex:
```
```


**2.5 Pointer to Pointer**
- **Pointer to pointer** là một loại con trỏ dùng để lưu trữ địa chỉ của biến con trỏ.

VD: 
- ina = 10// 0xc1       
//giá trị 10, địa chỉ 0xc1
 int*ptr = &a // 0xc1; 0xa5
 //giá trị 0xc1, địa chỉ 0xa5``


- int**ptr ( giá trị của biến trỏ ) = &ptr= 0xa5
 *(0xa5)= 0xc1 --> **(0xa5)= 10



## 3. Memory Allocation


| Stack |
|:-----:|
|   ↓   |
|   ↑   |	
|  Heap |
|  Bss(Uninitialized data)  |
|  Data(Initialized data)   |
|  Text |

- ***Text:*** Quyền truy cập chỉ có thể Read
	- Chứa khai báo các hằng số(.rodata)
	- Nó chưa lệnh thực thi nên tránh sửa đổi instruction
- ***Data:*** Quyền truy cập Read-Write
	- Chứa biến toàn cục hoặc biến static: Có giá trị khởi tạo khác 0
	- Được giải phóng khi kết thúc chương trình
- ***Bss:*** Quyền truy cập Read-Write
	- Chứa biến toàn cục hoặc các biến static: Có giá trị khởi tạo bằng 0 hoặc không khởi tạo
	- Được giải phóng khi kết thúc chương trình
- ***Stack:*** Quyền truy cập là Read-Write.
	- Được sử dụng cấp phát cho biến local, input parameter của hàm,...
	- Sẽ được giải phóng khi ra khỏi block code/hàm
- ***Heap:*** Quyền truy cập là Read-Write.
	- Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc,...
	- Sẽ được giải phóng khi gọi hàm free,...


**Cấp phát động**
- khai báo 1 mảng mà chưa rõ phải sử dụng kích thước là bao nhiêu --> cấp phát động
- Cấp phát động bộ nhớ chính là việc cấp phát/giải phóng, thay đổi kích thước bộ nhớ một cách linh hoạt. Giúp chúng ta điều khiển được việc sử dụng bộ nhớ của chương trình.

- **Malloc:**  
Ex: tạo 5 ô nhớ cho kiểu uint16
```c
 C1:   uint16_t *ptr = (uint16_t *)malloc(2*5)
 C2:   uint16_t *ptr2 = (uint16_t *)malloc(sizeof(uint16_t)*5);
```
- **Realloc:**
Ex: thay đổi size lên 7 ô nhớ
```c
    ptr2 = (uint16_t *)realloc(ptr2, sizeof(uint16_t)*7);
```
- **Free:** 
Ex:
```c
 free(ptr); // Thu hồi vùng nhớ
```

## 4. Variables 
**4.1 Biến Static**
- Biến static cục bộ: Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.


_Ex 1: Khi chưa khai báo biến static_
```c
void test(){
    static int a =10;  // giả sử có địa chỉ là 0xc1
    printf("a = %d\n", a);
    a++;
}

int main(int argc, char const *argv[])
{
    test(); // nó sẽ được lưu ở phân vùng nhớ đó 
    test(); // khi chạy lần 2 thì sẽ không khởi tạo lại mà tiếp tục thực hiện tức là a + 1 
    test(); // tương tự

    return 0;
}
```
Kết quả: 
10
10
10


_Ex 2: Khi dùng biến static_
```c
void test(){
    static int a =10;  // giả sử có địa chỉ là 0xc1
    printf("a = %d\n", a);
    a++;
}

int main(int argc, char const *argv[])
{
    test(); // nó sẽ được lưu ở phân vùng nhớ đó 
    test(); // khi chạy lần 2 thì sẽ không khởi tạo lại mà tiếp tục thực hiện tức là a + 1 
    test(); // tương tự

    return 0;
} 
```
Kết quả: 
 10
 11
 12


- Biến static toàn cục: Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được. 



**4.2 Biến Extern** 
- Gọi hàm, biến từ một file khác
- Biến Static cục bộ không lấy được qua extern

VD: Muốn gọi biến a ở file test. sang file main.c, ta thực hiện ở file main.c như sau:

extern a;

Tại Terminal gõ: `gcc main.c test.c` --> `enter`
Gõ `./main` 



**4.3 Biến Volatile**
```c
volatile int test; // thông báo cho compiler không được phép tối ưu test
    while (1)
    {
        test = readdataUART(); // khi chạy sẽ bỏ qua bước này
        A();
        B();
        C();
    }  
    return 0;
```


**4.4 Biến Register**
- Tác dụng của từ khóa register, nói một cách ngắn gọn là làm tăng hiệu năng(performance) của chương trình.

![Alt text](image-5.png)

- Có register thì xử lí nhanh hơn.
- Hiện nay người ta không còn sủ dụng register nữa vì tốc độ xử lí của RAM đã nhanh hơn tuy nhiên một vài controller còn sử dụng.

Ex:
```c

int main(int argc, char const *argv[])
{
    clock_t start, end;
    double test;
    register  i; 
    start = clock();
    for (; i < 0xFFFFFFFF; i++);
    end = clock();
    test = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("time: %f\n", test);
    return 0;
}

// không có register: time: 7.550000
// có register        time: 0.951000

``` 

## 5. Struct and Union
Struct và Union là 2 cấu trúc dữ liệu do lập trình viên định nghĩa bao gồm các biến với kiểu dữ liệu khác nhau.

**5.1 Struct**

Cú Pháp:
```c
struct <tên kiểu cấu trúc>
{
<kiểu dữ liệu> <tên thành phần 1>;
… 
<kiểu dữ liệu> <tên thành phần n>;
} <tên biến 1>, <tên biến 2>;

```
Ex: 
```c
struct dulieuhocsinh {
    int tuoi;
    float chieucao;
    int namsinh;
}hocsinh1;
```

**5.2 Union**
- Được khai báo và sử dụng như cấu trúc
- Các thành phần của union có chung địa chỉ đầu (nằm chồng lên nhau trong bộ nhớ)

Cú Pháp
```c
union <tên kiểu cấu trúc>
{
<kiểu dữ liệu> <tên thành phần 1>;
… 
<kiểu dữ liệu> <tên thành phần n>;
} <tên biến 1>, <tên biến 2>;
 ```
Ex:

```c
typedef union{
        uint8_t var1[2];
        uint8_t var2[3];
        uint8_t var3[1];   
}typeunion;
```

**5.3 So sánh Struct và union**

Về mặt ý nghĩa, struct và union cơ bản giống nhau(đều là kiểu dữ liệu do người dùng tự định nghĩa). Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:

•	**Struct**: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding)

•	**Union** : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.


**5.4 Ví dụ về truyền data sử dụng union và struct**
```c
typedef union{
    struct{
        uint8_t id[2];
        uint8_t data[3];
        uint8_t checkSum[1];


    }object;
    uint8_t array[6];
   
}dataFrame;


int main(int argc, char const *argv[])
{
    //Gói data cần phải truyền: 1 byte ID
    //                          3 byte DATA
    //                          1 byte CS
    //                          0x01 0xC2 0xF8
    dataFrame test;
    test.object.id[0] = 0x01;
    test.object.id[1] = 0x02;

    test.object.data[0] = 0xC8;
    test.object.data[1] = 0xF8;
    test.object.data[2] = 0xF2;

    test.object.checkSum[0] = 0xA7;
    return 0;
}
```


## 6. Compiler 
Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:
•	Giai đoàn tiền xử lý (Pre-processor)
•	Giai đoạn dịch NNBC sang Asembly (Compiler)
•	Giai đoạn dịch asembly sang ngôn ngữ máy (Assembler)
•	Giai đoạn liên kết (Linker)

![Alt text](image-4.png)

**6.1 Pre-processor (Giai đoạn tiền xử lý):** 

Nhận mã nguồn và xóa bỏ các dòng comments, xử lý các chỉ thị tiền xử lý có bắt đầu bằng kí hiệu `#`. Như `#include` (thay thế mã chương trình của một tệp tiêu để vào mã nguồn cần dịch), `#define` (thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình).
	-  Sau khi qua quá trình tiền xử lý thì file code lúc này sẽ có dạng `.i`.
	-  Dùng lệnh `gcc -E filename.c -o filename.i` hoặc `gcc -E filename.c` để xem code sau khi qua quá trình preprocessor.


**6.2 Compiler (Giai đoạn dịch NNBC sang ngôn ngữ Assembly)**

Kiểm tra các kiểu dữ liệu có lỗi hay không, phân tích cú pháp (syntax) của mã nguồn NNBC và tối ưu code.
	-  Quá trình này sẽ biên dịch từ code `.i` sang ngôn ngữ assembly `.s`.
	-  Dùng lệnh `gcc -S -o filename.s filename.c` để có thể xem code sau quá tình compiler.
 
**6.3 Assembler (Giai đoạn dịch ngôn ngữ Assembly sang ngôn ngữ máy):**

- Biên dịch ngôn ngữ Assembly sang ngôn ngữ máy (0 và 1). Và tạo ra tệp tin Object `.o` or `.obj`.
-  Dùng lệnh `gcc -c filename.c -o filename.o` để tạo ra file ".o" và dùng lệnh `objdump -d -Mintel filename.o` để xem code.

**6.4 Linker (Giải đoạn liên kết):** 
- Trong giai đoạn này mã máy của một chương trình `.o` dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích nhất. Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này. Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.

- File sau khi được gộp lại thì sẽ có đuôi mở rộng Executable `.exe`, còn trên Linux và MacOs thì có thể có đuối theo chỉ định hoặc không có đuôi mở rộng.

- Để chạy file code C trên `terminal` dùng lệnh `gcc -o filename filename.c` đẻ tạo ra tệp thực thi, sau đó dùng lệnh `./filename` để chạy tệp thực thi đó.


## 7. Macro and Function
**7.1 Macro**
 Macro không phải là kiểu dữ liệu mà là một định nghĩa 1 đoạn chương trình nào đó bằng một tên, khi gọi tên chương trình đó thì quá trình tiền xử lí sẽ copy chương trình đó bỏ vào.

**7.1.1 #ifndef** (if not define)
Ex:

`

`#ifndef STM32
#define STM32
*chương trình*


`

**7.1.2 Tạo chuỗi**
- Mỗi con chip có những thanh ghi khác nhau, ta định nghĩa cho mỗi con chip vì thế chương trình phía dưới chỉ cần thay đổi
- Để tạo chuỗi ta dùng #


**7.1.3 __VA_ARGS__**

**7.2 Function**
- Function là một khối lệnh thực hiện chức năng nào đó.
- Program counter: là bộ đếm
- Stack pointer: lưu bộ nhớ
- Vào 0x0000 sẽ khởi tạo Program count và Stack pointer
- Program count sẽ đếm từng địa chỉ và đọc giá trị của từng địa chỉ ra. Thì giá trị đó sẽ làm cho chương trình chạy.

**7.3 So sánh Macro và Function**


| |Macro  | Function |
|-|-      |-         |-                |
| **Được xử lí ở**| Preprocessor | Compiler|
|**Tóm tắt quá trình thực hiện** | Thay thế đoạn code macro vào chỗ được gọi trước khi được biên dịch | 	Khi thấy hàm được gọi, compiler sẽ phải lưu con trỏ chương trình PC (Program Counter) hiện tại vào stack(stack counter); chuyển PC tới hàm được gọi, thực hiện hàm đó xong và lấy kết quả trả về; sau đó quay lại vị trí ban đầu trong stack trước khi gọi hàm và tiếp tục thực hiện chương trình. |
| **Kích thước**|  lớn| nhỏ |
|**Tốc độ** |nhanh  | chậm |
