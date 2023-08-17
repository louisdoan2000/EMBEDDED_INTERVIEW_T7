#include <iostream>
#include <string>
// Không .h bộ thư viện cho C++
using namespace std;

// Là kiểu dữ liệu do người dùng tự định nghĩa trong C++
// Class khác với struct là class có hàm
class SinhVien{
    public:
        int MSSV;//Biến là property
        string TEN;
        string LOP;
        int NAM_SINH;
        int TUOI(){
            return 2023 -NAM_SINH;
        }
        //hàm là method
};

void display(SinhVien sv){
    cout<<"MSSV" <<sv.MSSV<<endl;
    cout<<"TEN: "<<sv.TEN<<endl;
    cout<<"LOP: "<<sv.LOP<<endl;
    cout<<"NAM SINH: "<<sv.NAM_SINH<<endl; 
    cout<<"TUOI: "<<sv.TUOI()<<endl;
}


int main(int argc, char const *argv[])
{
    SinhVien sv1; // class SinhVien 
                  // sv1 là object

    sv1.LOP = "CDT12";
    sv1.MSSV = 100101;
    sv1.NAM_SINH = 2000;
    sv1.TEN = "HOANG";

    SinhVien sv2 = {1003, "Hoang", "CDT32", 1999};
    display(sv1);
    display(sv2);
    return 0;
}
