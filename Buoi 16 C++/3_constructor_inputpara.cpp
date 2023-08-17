#include <iostream>
#include <string>
using namespace std;
class SinhVien{
    public:
//constructor có tham số đầu vào 
        SinhVien(string ten, int nam_sinh, string lop){
            TEN = ten;
            LOP = lop;
            NAM_SINH = nam_sinh;
            static int id = 1000;
            MSSV = id;
            id++;
        }
        int MSSV;
        string TEN;
        string LOP;
        int NAM_SINH;
        int TUOI(){
            return 2023 -NAM_SINH;
        }
        
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
    SinhVien sv1("Hoang", 1998, "KHMT12");

    SinhVien sv2("Tuan", 2000, "KHMT14"); 
 


    display(sv1);
    display(sv2);
    return 0;
}
