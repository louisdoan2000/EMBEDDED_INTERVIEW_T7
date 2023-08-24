#include <string>
//using namespace std;

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
