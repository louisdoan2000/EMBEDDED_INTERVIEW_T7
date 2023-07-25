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
**2.3 Con trỏ hàm**
- Dùng để gọi hàm thông qua con trỏ
- 
**2.4 Con trỏ NULL**
- Là con trỏ có địa chỉ và giá trị bằng 0
- Vì khai báo con trỏ bất kì thò phải có giá trị nếu không thì con trỏ sẽ trỏ tới giá trị rác nên cần khai báo 

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




## 4. Variables 

- Biến static cục bộ: Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.
- Biến static toàn cục: Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được. 

## 5. Struct and Union

## 6. Compiler 

## 7. Macro 
