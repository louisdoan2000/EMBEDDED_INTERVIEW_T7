#include <iostream>
#include<vector>

using namespace std;

void hello(vector<int>&v){
    v[0] = 10;
}



int main(int argc, char const *argv[])
{
    vector<int> v ={1, 2, 3};
    v.insert(v.begin() + 1, 4);// lấy 
    v.erase(v.begin() + 2);
    
    
    vector<int> v2 = {4, 5, 6,};
    v2 =v;

    hello(v);
    
    for (uint8_t i = 0; i< v.size(); i++){
        cout<< v.at(i)<<" ";
    }
    return 0;
}
//vector được lưu trên vùng nhớ HEAP, bên này thêm được và xóa được còn như array lưu trên STACK là cố định