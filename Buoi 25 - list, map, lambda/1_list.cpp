#include <iostream>
#include <list>


using namespace std;

int test[] = {1, 3, 5, 7, 9};

int main(int argc, char const *argv[])
{
    list<int> array =  {1, 2, 3, 4, 5, 6};
    list<int>::iterator it = array.begin();

    advance(it, 2); // Dịch con trỏ tới vị trí 3
    array.insert(it, 10); // chèn 10 vào vị trí 3

    for(int i : array){
        cout<<"i = "<<i <<endl;
    }
    //Hoặc thông qua iterator
    for (list<int>::iterator it = array.begin(); it != array.end(); it++) //it sẽ dịch địa chỉ qua ô    
    {
       cout<<" i = "<<*it<<endl;
    }
    
    //Đối với list thì phải dùng các này. Chứ không thể dùng vòng for như bình thường( i<array.size())
    // Vector giống như malloc, realloc khác với List là kiểu linked list

    array.begin();
    test[1];
    return 0;
}


