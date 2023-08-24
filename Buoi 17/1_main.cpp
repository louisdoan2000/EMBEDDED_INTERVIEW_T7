#include <iostream>
#include <string>

using namespace std;
// class này là header 
class SinhVien{
    public:
        static int MSSV;
        string TEN;
        string LOP;
};

int SinhVien::MSSV;


int main(int argc, char const *argv[])
{
    SinhVien sv1, sv2;
    return 0;

    printf("Dia chi sv1: %p\n", &(sv1.MSSV));
    printf("Dia chi sv1: %p\n", &(sv2.MSSV));
    
}
