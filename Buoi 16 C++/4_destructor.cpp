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
            ptr = &id;
            MSSV = id;
            id++;
        }
        //destructor
        ~SinhVien(){
            cout<<"THOAT TEN: "<<TEN<<endl;
            *ptr =1000;   // gán lại cho id giá trị 1000
        }
        int *ptr;
        int MSSV;
        string TEN;
        string LOP;
        int NAM_SINH;
        void display(){
                cout<<"MSSV: " <<MSSV<<endl;
                cout<<"TEN: "<<TEN<<endl;
                cout<<"LOP: "<<LOP<<endl;
                cout<<"NAM SINH: "<<NAM_SINH<<endl; 
                cout<<"TUOI: "<<2023 - NAM_SINH<<endl;
            }
};


void test1(){
    SinhVien sv1("Hoang", 1998, "KHMT");
    SinhVien sv2("Kiet", 1998, "DTTVT");
    sv1.display();
    sv2.display();

}

void test2(){
    SinhVien sv1("Hoang", 1998, "KHMT");
    SinhVien sv2("Kiet", 1998, "DTTVT");
    sv1.display();
    sv2.display();

}

// Biết static dù toàn cục hay cục bộ chỉ khởi tạo 1 lần và các object id có chung 1 địa chỉ nên id nó lần lượt là 1000 1001 1002 1003 
// sv1, sv2 được lưa ở vùng nhớ stack
// khi chạy destructor ~SinhVien thì tên Kiet xuất hiện trước Hoàng vì tên Hoàng được xếp vào "thùng" trước Kiệt nên khi lấy ra thì Kiệt ra trước còn Hoàng ra sau
int main(int argc, char const *argv[])
{
    
   test1();
   cout<<"------------"<<endl;
   test2();
    return 0;
}
