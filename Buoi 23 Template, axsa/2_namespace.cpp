#include <iostream>
#include "test.cpp"


using namespace ConOngA;
namespace ConOngA{
    int Teo = 20;

}
// Chỉ được 1 biến Teo. Không được khai báo thêm 1 biến Teo 

namespace ConOngB{
    int Teo = 30;
}

//Để sử dụng 2 biến ConOngA và ConOngB thì ta sử dụng namespace  


using namespace ConOngA; // thì lúc này ở hàm main có thể gọi trực tiếp Teo, không cần phải gọi ConOngA nữa



int main(int argc, char const *argv[])
{
    std::cout<<ConOngA::Teo<< std::endl; 
    std::cout<<ConOngB::Teo<<std::endl;

    // Là biến bình thường chỉ khác địa chỉ vùng nhớ nó lưu

    ConOngA::SinhVien sv;
    sv.TEN = 10;
    std::cout<<Teo<<std::endl;

    // ConOngA ở file test và ở file này là 1 vùng nhớ chung nên những member phía trong sẽ không được trùng nhau
    // Khi ngta thiết kế thư viện có những thứ bên trong trùng nhau vd như độ ẩm ( độ ẩm của đất hoặc không khí), thì người ta sẽ thiết kế các namespace khác nhau
    
    return 0;
}
    