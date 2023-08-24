#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    private:
        string TEN;
        int TUOI;
    public:
        void nhapThongTin(string ten, int tuoi);
    //nên code bên ngoài
        void hienThi(){
        cout<<"Ten: "<<TEN<<endl;
        cout<<"Tuoi: "<<TUOI<<endl;
    }
};

//Kế th
class SinhVien: public DoiTuong{

};
void DoiTuong::nhapThongTin(string ten, int tuoi){
    this->TEN = ten; //con trỏ this, con này là con trỏ DoiTuong
    this->TUOI = tuoi;
}






int main(int argc, char const *argv[])
{
    DoiTuong dt;
    dt.nhapThongTin("Hoang", 20);
    dt.hienThi();

    SinhVien sv;
    sv.nhapThongTin("Tuyet", 18);
    sv.hienThi();
    return 0;
}
