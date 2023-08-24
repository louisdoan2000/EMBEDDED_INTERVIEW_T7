//#include "SinhVien.hpp"
#include <iostream>
#include <string>
using namespace std;

class SinhVien{
    public:
        void setInfor(string ten, int tuoi);
        void display();
    //protected:
    //private:
        string TEN;
        int TUOI;
};

//Class Hocsinh kế thừa từ Sinhvien
class HocSinh : public SinhVien{
    public:
        void setInfor(string ten, int tuoi, int mshs);
        void display();
        int MSHS;
};

void SinhVien::setInfor(string ten, int tuoi){
    TEN = ten;
    TUOI = tuoi;
}

void SinhVien::display(){
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Tuoi: "<<TUOI<<endl;
}

void HocSinh::setInfor(string ten, int tuoi, int mshs){
    TEN = ten;
    TUOI = tuoi;
    MSHS = mshs;
}

void HocSinh::display(){
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Tuoi: "<<TUOI<<endl;
    cout<<"MSHS: "<<MSHS<<endl;
}

int main(){

    // SinhVien sv("Hoang", 16);
    // SinhVien sv2("Tuan", 16);
    // sv.display();

    // cout<<sv.ID<<end;
    SinhVien sv;

        sv.setInfor("Hoang", 17);
        sv.display();

        HocSinh hs;
        hs.setInfor("Tuan", 14, 1000);
        hs.display();
        
    return 0;
}

// Giả sử viết thư viện class giải ptb2 sau này muốn bổ sung thêm vô nghiệm, vs nghiệm, thì những biến như x1, x2, delta nằm trong protected để sau này có thể kế thừa được 