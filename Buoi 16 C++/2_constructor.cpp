#include <iostream>
#include <string>
// Không .h bộ thư viện cho C++
using namespace std;
class SinhVien{
    public:
//constructor không có tham số đầu vào 
        SinhVien(){
            static int id =1000;  // Muốn mssv tự động tăng
            MSSV = id;
            id++;
        }
        
        
        int MSSV;// giống như biến toàn cục
        string TEN;
        string LOP;
        int NAM_SINH;
        int TUOI(){
            return 2023 -NAM_SINH;
        } //hàm là method
        
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
    SinhVien sv1; //constructor sẽ chạy ngay sau khi khởi tạo object
    sv1.LOP = "CDT12";
    sv1.NAM_SINH = 2000;
    sv1.TEN = "HOANG";

    SinhVien sv2; 
    sv2.LOP = "CDT52";
    sv2.NAM_SINH = 2001;
    sv2.TEN = "HOANG";


    display(sv1);
    display(sv2);
    return 0;
}
