#include <iostream>
#include <string>
#include <vector>
#include <stdbool.h>
using namespace std;

typedef enum{
    EMPTY,
    SEATED
} typeStatus;

//MANAGER
//------------------------------------------------------------------

class Menu{
    private:
        int ID;
        string DISH;
        int PRICE;
        int QUANTITY ;
    public:
        Menu(string dish, int price);

        Menu(int ID, string dish, int price, int quantity);
        void setDish(string dish);
        void setPrice(int price);
        void setQuantity(int quantity);

        int getID();
        string getDish();
        int getPrice();
        int getquantity();
};

Menu::Menu(string dish, int price){
    static int id = 1000;
    this->ID = id;
    id++;


    this->DISH = dish;
    this->PRICE = price;
    
}

Menu::Menu(int ID, string dish, int price, int quantity){
    static int id = 1000;
    this->ID = id;
    id++;


    this->DISH = dish;
    this->PRICE = price;
    this->QUANTITY = quantity;
}
void Menu::setDish(string dish){
    DISH = dish;
};

void Menu::setPrice(int price){
    PRICE = price;
};

void Menu::setQuantity(int quantity){
    QUANTITY = quantity;
};

int Menu::getID(){
    return ID;
}

string Menu::getDish(){
    return DISH;
}

int Menu::getPrice(){
    return PRICE;
}

int Menu::getquantity(){
    return QUANTITY;
}
//------------------------------------------------------------------
//------------------------------------------------------------------
class Table{
    private:
        vector<Menu> DATABASEBILL;
        int POSITION;
        typeStatus STATUS;

    public:
        Table(int position, typeStatus status);
        Table(int position, typeStatus status, vector<Menu> databaseBILL);
        
        
        void setStatus(typeStatus status);
        void setDatabaseBill(Menu& databaseBILL);

        int getPosition();
        typeStatus getStatus();
        vector<Menu>& getDatabaseBill();
};
//-------------------------------------------------------------------
Table::Table(int position, typeStatus status){
    this -> POSITION = position;
    this -> STATUS = status;

}

Table::Table(int position, typeStatus status, vector<Menu> databaseBILL){
    this -> POSITION = position;
    this -> STATUS = status;
    this -> DATABASEBILL = databaseBILL;
}
//Set-------------------------------------------------------------------------
void Table::setStatus(typeStatus status){
    STATUS = status;
};

void Table::setDatabaseBill(Menu& bill){
    DATABASEBILL.push_back(bill);
}


//Get--------------------------------------------------------------------------
int Table::getPosition(){
    return POSITION;
}

typeStatus Table::getStatus(){
    return STATUS;
}

vector<Menu>& Table::getDatabaseBill(){
    return DATABASEBILL;
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//Hàm hiện kí hiệu trạng thái
string displayStatusTable(typeStatus status){
    if(status == EMPTY) return "0";
    else if(status == SEATED) return "X";
    return " ";
}
//Hàm in bảng1
void printTables(vector<Table> databaseTB){

    cout<<"\tTablePosition\t"<<"\t|\t";
    for (int i = 0; i < databaseTB.size(); i++)
    {
        cout<<databaseTB[i].getPosition()<<"\t|\t";
    }

    cout<<endl<<"\t--------------------------------------------------------------------------------------------------------------------"<<endl;

    cout<<"\tStatus\t"<<"\t\t|\t";
    for (int i = 0; i < databaseTB.size(); i++)
    {
    cout<<displayStatusTable(databaseTB[i].getStatus())<<"\t|\t";
    
    }
    }


//1. Hàm thiết lập số lượng bàn ban đầu
void setQuantityOfTable(vector<Table> &databaseTB){
    cout<<"MANAGER"<<endl;
    cout<<"Enter the total of Table: ";

    int totalTable;
    int tablePosition;
    typeStatus statusTable = EMPTY;
    cin>> totalTable;

for (int i = 1; i <= totalTable; i++)
{
    tablePosition = i;
    Table tb ={tablePosition, statusTable};
    databaseTB.push_back(tb);
}
    printTables(databaseTB);
} 

// Thay đổi trạng thái bàn
void changeStatusTable(vector<Table>&databaseTB){
    int table, key;
    cout<<"Enter the table you want to change status from 1 to " << databaseTB.size()<<endl;
    cin>> table; 
    for (int i = 1; i < databaseTB.size(); i++){
        if (databaseTB[i].getPosition() ==i){
            cout<<"\nEnter your choice\n0: Empty (0)\n1: Seated (X)"<<endl;
            cin>> key;
            switch(key){
                case EMPTY:
                    databaseTB[i].setStatus(EMPTY);
                    break;
                case SEATED:
                    databaseTB[i].setStatus(SEATED);
                    break;
                default:
                    break;
            }
        }     
    }
}
 
//1.Quản lí bàn
void manageTable(vector<Table>&databaseTB){

    cout<<"Enter your choice "<<endl<<"\n1. Thiết lập bàn\n2. Thay đổi trạng thái bàn"<<endl;
    int key;
    cin>> key;
    switch (key)
    {
    case 1:
        setQuantityOfTable(databaseTB);
        break;
    case 2:
         changeStatusTable(databaseTB);
         break;
    default:
        break;
    }
}

//2. Thêm món vào menu
void addDish(vector<Menu>&databaseMN){

    int i = 0;
    do
    {
        cout<<"\nEnter dish: ";
        string dish;
        cin>> dish;

        int price;
        cout<<"Enter price: ";\
        cin>> price;
        
        Menu mn = {dish, price};
        databaseMN.push_back(mn);
    do
    {
        cout <<"1: Continue\n0: Back |  Choose ---> ";
        cin >>i;
    } while (i !=1 && i !=0);
    } while (i==1);    
}

// Sửa món ăn
void editDish(vector<Menu>&databaseMN){
    do
    {int selectedID, changeprice, key;
    string changedish;
    cout<<"\n --nhap 0 de thoat-- \n Enter Dish's ID: ";
    cin >> selectedID;
    if (selectedID == 0) return;
    cout<<"\n1: Change dish\n2: Change price\n You choose--> ";
    cin>> key; 
    
    switch (key)
    {
    case 1:
        cout<<"Ban muon doi ten mon thanh: ";
        cin>> changedish;
        databaseMN[selectedID].setDish(changedish);
        break;
    case 2:
        cout<<"Ban muon doi gia tien thanh: ";
        cin>> changeprice;
        databaseMN[selectedID].setPrice(changeprice);
        break;
    default:
        break;
    }
    } while (1);
}

//Xóa món trong menu
void eraseDish(vector<Menu>&databaseMN){
    int selectedID, found = 0;
    cout<<endl<<"Nhap ID mon muon xoa";
    cin>> selectedID;
    for (int i = 0; i < databaseMN.size(); i++){
        if(databaseMN[i].getID()== selectedID)
        {
            found++;
            databaseMN.erase(databaseMN.begin() + i);
            return;
        }
    }
    if(found != 0) cout<<"ID not found"<<endl;
}

//In Menu 
void printMenu(vector<Menu>databaseMN){
   cout << "--------------------------------------------"<<endl;
   cout <<"|\tSTT\t|\tID\t|\tDISH\t|\tPRICE\t|"<<endl;
   for (int i = 0; i < databaseMN.size(); i++){

    cout<<"|\t"<<i+1<<"\t|\t"<<databaseMN[i].getID()<<"\t|\t"<<databaseMN[i].getDish()<<"\t|\t"<<databaseMN[i].getPrice()<<"\t|\t"<<endl;
   }
    cout << "--------------------------------------------"<<endl;
}

void MANAGER(vector<Menu>databaseMN, vector<Table>&databaseTB){
   
    int key = 0;  

    while(1){
    cout<<"\nNhap lua chon"<<endl;
    cin>>key;
    switch (key)
    {
    case 1:
        manageTable(databaseTB);
        break;
    case 2:
        changeStatusTable(databaseTB);
        break;
    case 3:
        addDish(databaseMN); 
        break;
    case 4:
        editDish(databaseMN);
        break;
    case 5:
        break;
    case 6:
        printTables(databaseTB);
        break;
    case 7: 
        printMenu(databaseMN);
        break;
    case 0:
        return;
    default:
        break;
    }
    }  
}

//Staff
//1. Thêm món ăn vào bill
void addDishToBill(vector<Menu> &databaseMN, vector<Table> &databaseETB, Table table){
    int i = 0;
    do
    {
    int dishID;
    int price, quantity;
    string name;
    cout<<"Enter the Dish's ID: "<<endl;
    cin>> dishID;
    cout<<"Nhap so luong: "<<endl;
    cin >> quantity;

    

    for (int i = 0; i < databaseMN.size(); i++)
    {
        if(databaseMN[i].getID() == dishID){
        
        price = databaseMN[i].getPrice();
        //quantity = databaseMN[i].getquantity();
        name = databaseMN[i].getDish();
        }    
        Menu bill = {dishID, name, price, quantity};
        table.setDatabaseBill(bill);
        //databaseETB[0].setDatabaseBill(bill); 
    }
    do{
        cout<<"1: Continue\n0: Back | Choose --> ";
        cin >>i;
    } while( i!= 1 && i!=0);
    } while (i == 1);

    for( int i = 0; i < table.getDatabaseBill().size(); i++ ){
    }


    table.getDatabaseBill();
    //cout<< databaseETB[0].getDatabaseBill()[0].getDish();
    } 
    

//Hàm in
void printBill(vector<Menu> &databaseMN,  vector<Table>databaseETB){

    cout<< "\t---------------------------------------------------------------------------------\t\n";

    cout<<"\t|\tStt\t|\tID\t|\tName\t|\tCost\t|\tQuanity\t|\t\n";

    //for (int i = 0; i < databaseETB.size(); i++)
    //{
        //cout<<"|\t"<<i+1<<"\t|\t"<<databaseTB[i].getDatabaseBill()<<"\t|\t"<<databaseETB[i].getDish()<<"\t|\t"<<databaseETB[i].getPrice()<<"\t|\t"<<endl;
    cout<< (databaseETB[0].getDatabaseBill())[0].getDish();
    //cout<<(databaseETB[i].getDatabaseBill())[i].getID();
    //cout<<(databaseETB[i].getDatabaseBill())[i].getPrice();
    //}
}



int main(int argc, char const *argv[])
{
    vector<Table> databaseTB;
    vector<Menu> databaseMN;
    int key;

    while (1)
    {
    cout<<"(Ham main)Enter your choice ";
    cin>>key;
    switch (key)
    {
    case 1:
        MANAGER(databaseMN, databaseTB);
        break;
    case 2:
        addDishToBill(databaseMN, databaseTB);
        break;
    case 3: 
        printBill(databaseMN, databaseTB);
    default:
        break;
    }
    }
    
    
    return 0;
}


