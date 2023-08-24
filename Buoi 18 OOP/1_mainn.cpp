#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    protected:
        string TEN;
        int TUOI;
    public:
        int TEST;
        void nhapThongTin(string ten, int tuoi);
    //code nhanh nên code bên ngoài
        void hienThi(){
            cout<<"Ten: "<<TEN<<endl;
            cout<<"Tuoi: "<<TUOI<<endl;
    }
};
//Hàm nhập thông tin
void DoiTuong::nhapThongTin(string ten, int tuoi){
    this->TEN = ten; //con trỏ this, con này là con trỏ DoiTuong
    this->TUOI = tuoi;
}

//Kế thừa public
class SinhVien: protected DoiTuong{
    private:
        int MSSV;
    public:
        void nhapThongTin(string ten, int tuoi, int mssv);
        void hienThi(){
            cout<<"Ten: "<<TEN<<endl;
            cout<<"Tuoi: "<<TUOI<<endl;
            cout<<"MSSV: "<<MSSV<<endl;
        }    
};
//Muốn kế thừa hay định nghĩa lại hàm thì sẽ gọi lại hàm đó và code lại được gọi là ghi đè
//những thứ public ở Doituong qua Sinhvien thành protected, protected qua Sinhvie thành protected 

// class Học sinh kế thừa sinh viên
class HocSinh: public SinhVien{
    public:
        void test(){
            TEST = 10;
        }
};
//Những public của SinhVien sẽ kế thừa được ở HocSinh, protected của SinhVien sẽ kế thừa được còn private sẽ không kế thừa được



//ghi đè
void SinhVien::nhapThongTin(string ten, int tuoi, int mssv){
    this->TEN = ten; 
    this->TUOI = tuoi;
    this->MSSV = mssv;
}


int main(int argc, char const *argv[])
{
    DoiTuong dt;
    dt.nhapThongTin("Hoang", 20);
    dt.hienThi();

    SinhVien sv;
    sv.nhapThongTin("Tuyet", 18, 1001);
    sv.hienThi();

    return 0;
}
