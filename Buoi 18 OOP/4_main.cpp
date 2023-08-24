//Tính đóng gói


#include <iostream>
#include <string>
using namespace std;
// VD giải ptb2
class Toanhoc{
    public:
        void setTEN(int ten){
            TEN = ten;
        }

    private:
        int TEN; //property
        int TUOI;
};
//object không được truy câp trực tiếp đến các property mà phải thông qua method


int main(int argc, char const *argv[])
{
    Toanhoc th;
    th.tong(8,3);

    th.tong(7, 3, 5);
    cout<<"Tong a va b: "<<th.tong(8, 12.5)<<endl;
    
    return 0;
}
