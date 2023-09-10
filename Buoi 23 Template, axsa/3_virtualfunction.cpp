#include <iostream>
#include "test.cpp"

class DoiTuong{
    public:
        virtual char  *cmd(){
            return (char*)"Doi Tuong\n";
        }
        void display(){
            printf("%s", cmd()); // display gọi cmd, tại cmd return "Doi Tuong"
        }
};

class SinhVien : public DoiTuong{
    char *cmd(){
        return (char*)"SinhVien\n";
    }

};
//overwrite overload
int main(int argc, char const *argv[])
{
    DoiTuong dt;
    dt.display();

    SinhVien sv;
    sv.display();  //cmd xem thử ở class con có overide không, virtual function kiểm tra xem class con có định nghĩa lại cmd. Load lại mới nhất gọi là overload   

    //Khi thiết kế chương trình nếu cho phép class con load lại cái mới nhất thì ta sử dụng virtual function

    return 0;
}


