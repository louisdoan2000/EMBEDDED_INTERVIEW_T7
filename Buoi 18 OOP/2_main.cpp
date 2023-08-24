#include <iostream>
#include <string>
//Tính đa hình
using namespace std;

class Toanhoc{
    public:
        void tong(int a, int b){
            cout<<"tong a va b: "<<a+b<<endl;
        }
        void tong(int a, int b, int c){
            cout<<"tong a, b va c: "<<a+b+c<<endl;
        }
    
        int tong(int a, double b){
            return a+(int)b;//ép kiểu
        }
};
//C++ có thể tạo ra 2 hàm trùng tên chỉ cần khác input parameter
int main(int argc, char const *argv[])
{
    Toanhoc th;
    th.tong(8,3);

    th.tong(7, 3, 5);
    cout<<"Tong a va b: "<<th.tong(8, 12.5)<<endl;
    
    return 0;
}
