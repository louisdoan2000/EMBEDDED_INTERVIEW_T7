//Tính trừa tượng giống như static 
// Vd như khi chương trình giải ptb2 người dùng chỉ có thể nhập data và lấy data người dùng không thể truy cập vào quá trình giải

#include <iostream>
#include <string>
//Tính đa hình
using namespace std;
// VD giải ptb2
class Toanhoc{
    public:
        void setData();
        int result();
    private:
        int delta();
};

int main(int argc, char const *argv[])
{
    Toanhoc th;
    th.tong(8,3);

    th.tong(7, 3, 5);
    cout<<"Tong a va b: "<<th.tong(8, 12.5)<<endl;
    
    return 0;
}
