// 1: Thêm SinhVien
// 2: Cập nhật tt sv bằng ID( nhập ID vào để sửa tên, tuổi,....)
// 3: Xóa SV bởi ID( bấm phím 3 thì sẽ hiện danh sách sv, sau đó nhập mssv để xóa sinh viên đó) 
// 4: Tìm kiếm SV theo tên(nhập tên thì hiện ra các thông tin còn lại )
// 5: Sắp xếp SV theo điểm TB (ban đầu sẽ lưu vào 1 vector sau đó sắp xếp các sinh viên tăng dần)
// 6: Sắp xếp SV theo tên (có thể dùng hàm so sánh tên)
// 7: Hiển thị Danh sách SV 
// 0: quay lại chương trình


#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum{
    ADD = 1,
    UPDATE = 2,
    ERASE = 3,
    FIND = 4,
    SORTBYDIEMTB = 5,
    SORTBYNAME = 6,
    PRINT= 7,
    EXIT = 0
    
};

typedef enum{
    GIOI,
    KHA,
    TB,
    YEU
} typeHocLuc;

typedef enum{
    NAM = 1,
    NU = 2
} typeGioiTinh;

class SinhVien{
    private:
        int ID;
        string NAME;
        int TUOI;
        typeGioiTinh GIOITINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;
        typeHocLuc HOCLUC;
    public:
        SinhVien(string name, int tuoi, typeGioiTinh gioitinh, double diem_toan, double diem_ly, double diem_hoa);

        void setName(string name);
        void setTuoi(int tuoi);
        void setGioiTinh(typeGioiTinh gioitinh);
        void setDiemToan(double diem_toan);
        void setDiemLy(double diem_ly);
        void setDiemHoa(double diem_hoa);


        int getID();
        string getName();
        int getTuoi();
        typeGioiTinh getGioiTinh();
        double getDiemToan();
        double getDiemTb();
        typeHocLuc getHocLuc();
};

SinhVien::SinhVien(string name, int tuoi, typeGioiTinh gioitinh, double diem_toan, double diem_ly, double diem_hoa){
    static int id = 1000;
    this->ID = id;
    id++;

    this->NAME = name;
    this->TUOI = tuoi;
    this->GIOITINH = gioitinh;
    this->DIEM_TOAN = diem_toan;
    this->DIEM_LY = diem_ly;
    this->DIEM_HOA = diem_hoa;
}


void SinhVien::setName (string name){
    NAME = name;
};

void SinhVien::setTuoi(int tuoi){
    TUOI = tuoi;
};

void SinhVien::setGioiTinh(typeGioiTinh gioitinh){
    GIOITINH = gioitinh;
};

void SinhVien::setDiemToan(double diem_toan){
    DIEM_TOAN = diem_toan;
};

void SinhVien::setDiemLy(double diem_ly){
    DIEM_LY = diem_ly;
};

void SinhVien::setDiemHoa(double diem_hoa){
    DIEM_HOA = diem_hoa;
};

int SinhVien::getID() {
    return ID;
}

string SinhVien::getName(){
    return NAME;
}

int SinhVien::getTuoi(){
    return TUOI;
}

typeGioiTinh SinhVien::getGioiTinh(){
    return GIOITINH;
}

double SinhVien::getDiemToan(){
    return DIEM_TOAN;
}
        
double SinhVien::getDiemTb(){
    return (DIEM_TOAN + DIEM_LY + DIEM_HOA)/3;
}
        
typeHocLuc SinhVien::getHocLuc(){
    if(getDiemTb() >=8) return GIOI;
    else if(getDiemTb() >=6.5) return KHA;
    else if(getDiemTb() >=5) return TB;
    else return YEU;
}
// hiển thị
string hienthiHocLuc(int i) {
    if( i == GIOI)
        return "GIOI";
    else if( i == KHA)
        return "KHA";
    else if( i == TB)
        return "TB";
    else 
        return "YEU";
}

string hienthiGioiTinnh(int i ){
    if ( i== NAM)
        return "NAM";
    else if (i == NU)
        return "NU";
}

//In thông tin sinh viên
void printISV(vector<SinhVien> &databaseSV, int i) 
{
    
    cout << " -----------------------------------" << endl;
    cout << "|    ID   |   Name   | Tuoi |Diem TB| Gioi Tinh |" << endl;
	
		
		cout <<"|     " <<databaseSV[i].getID() 
            << "   | " << databaseSV[i].getName() 
            << "     | " << databaseSV[i].getTuoi() 
            << "   | "<< databaseSV[i].getDiemTb()
            << "     | " << hienthiHocLuc(databaseSV[i].getHocLuc())
            << "   | " <<hienthiGioiTinnh(databaseSV[i].getGioiTinh())<<endl;
	
    cout << " -----------------------------------" << endl;
    
}


//In danh sách sinh viên
void printSV(vector<SinhVien> &databaseSV) 
{
    cout << " -----------------------------------" << endl;
    cout << "|    ID   |   Name   | Tuoi |Diem TB| Gioi Tinh |" << endl;
	for (int i = 0; i < databaseSV.size(); i++)
	{
		
		cout <<"|     " <<databaseSV[i].getID() 
            << "   | " << databaseSV[i].getName() 
            << "     | " << databaseSV[i].getTuoi() 
            << "   | "<< databaseSV[i].getDiemTb()
            << "     | " << hienthiHocLuc(databaseSV[i].getHocLuc())
            << "   | " <<hienthiGioiTinnh(databaseSV[i].getGioiTinh())<<endl;
	}
    cout << " -----------------------------------" << endl;
    
}


//Thêm sinh viên
void addSinhVien(vector<SinhVien> &databaseSV) {
    
    int i = 0;
    do{
    cout<< "\nNhap name: ";
    string name; 
    cin >> name;

    int tuoi;
    while (1){
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        if(tuoi > 10 && tuoi < 100) break;
        else cout << "Error !!!\n";
    }

    cout << "\n1: NAM\n2: NU\nNhap lua chon: ";
    typeGioiTinh gioitinh;

    int key = 0; cin >> key;
    switch (key)
    {
    case 1:
        gioitinh = NAM;
        break;
    case 2:
        gioitinh = NU;
        break;
    default:
        break;
    }
    double diem_toan;

    do
    {
        cout<< "Nhập điểm Toán: "<< endl;
        cin>> diem_toan;
    } while (diem_toan<=0 || diem_toan >10);

    double diem_ly;
    do
    {
        cout<< "Nhập điểm Ly: "<< endl;
        cin>> diem_ly;
    } while (diem_ly<=0 || diem_ly >10);

    double diem_hoa;
    do
    {
        cout<< "Nhập điểm Hoa: "<< endl;
        cin>> diem_hoa;
    } while (diem_hoa<=0 || diem_hoa >10);

    
    
    typeHocLuc getHocLuc;
    
    SinhVien sv = {name, tuoi, gioitinh, diem_toan, diem_ly, diem_hoa};

    databaseSV.push_back(sv);
    cout<<"\nADD sucessfully\n\n";
    do
    {
        cout <<"1: Tiep tuc\n0: Quay lai |  Chon ---> ";
    cin >>i;
    } while (i !=1 && i !=0);

    } while(i == 1);
}

//Cập nhật thông tin sinh viên theo ghi nhập vào ID
 void updateSinhVien(vector<SinhVien>&databaseSV, int id){
        cout<<"Nhập vào ID muốn cập nhật thông tin"<<endl;
        cin>> id;
        for (int i = 0; i < databaseSV.size(); i++){
         
            if(databaseSV[i].getID() == id){
            cout<<"Cập nhật thông tin mới"<<endl;
            cout<< "\nNhap name: ";
            string ten;
            cin>> ten;
            int tuoi;
            while (1)
            {
               cout<< "Nhap tuoi: ";
                cin>> tuoi;
                if(tuoi >10 && tuoi < 100) break;
                else cout << "Error !!!\n";
            }
            
            cout<<"\n1: NAM\n2: NU\nNhap lua chon: ";
            typeGioiTinh gioitinh;
            int key = 0;
            // while (1)
            // {  menu (key);
            switch (key)
            {
            case 1:
                gioitinh =  NAM;
                break;
            case 2: 
                gioitinh = NU;
                break;
            default:
                break;
            }
            // }
            double diem_toan;

            do
            {
                cout<< "Nhập điểm Toán: "<< endl;
                cin>> diem_toan;
            } while (diem_toan<=0 || diem_toan >10);

            double diem_ly;
            do
            {
                cout<< "Nhập điểm Ly: "<< endl;
                cin>> diem_ly;
            } while (diem_ly<=0 || diem_ly >10);

            double diem_hoa;
            do
            {
                cout<< "Nhập điểm Hoa: "<< endl;
                cin>> diem_hoa;
            } while (diem_hoa<=0 || diem_hoa >10);
            
            databaseSV[i].setName(ten);
            databaseSV[i].setTuoi(tuoi);
            databaseSV[i].setGioiTinh(gioitinh);
            databaseSV[i].setDiemToan(diem_toan);
            databaseSV[i].setDiemLy(diem_ly);
            databaseSV[i].setDiemHoa(diem_hoa);
            cout<<"Sucessfully updated!!!"<<endl;
            }
            else cout<<"Your ID is INVALID. Enter another ID";        
        }         
}
//3. Hàm xóa Sinh Viên
// void eraseSV(vector<SinhVien> &databaseSV){
//     int selectedID, count = 0;
//     cout<< endl<< "Nhap sinh vien muon xoa: ";
//     cin>> selectedID;
//     for (int i = 0; i < databaseSV.size(); i++){
//         if (databaseSV[i].getID()== selectedID)
//         {   
//             databaseSV.erase(databaseSV.begin() + count);
//             return;
//         }
//         else
//         count++;
//     }
    
//     if(count != 0) cout <<"ID not found"<<endl;
// }
void eraseSV(vector<SinhVien> &databaseSV){
    int selectedID;
    cout<< endl<< "Nhap sinh vien muon xoa: ";
    cin>> selectedID;
    for (int i = 0; i < databaseSV.size(); i++){
        if (databaseSV[i].getID()== selectedID)
        {   
            databaseSV.erase(databaseSV.begin() + i);
            return;
        }
       
    }
    
         cout <<"\n\t\tID not found\n"<<endl;
}


//4. Tìm kiếm SV
void findSV(vector<SinhVien> &databaseSV){
    string selectedName; 
    int found = 0;
    cout<<endl<<"Enter student's name you want to find information ";
    cin>>selectedName;
    for (int i = 0; i < databaseSV.size(); i++){
        if(selectedName == databaseSV[i].getName()){
            found++;
            printISV(databaseSV, i);
        }
    }
    if (found = 0) cout<< " Not Valid"<<endl;
}


//sắp xếp theo điểm trung bình Descending
void sortByDiemTB(vector<SinhVien> &databaseSV){
    for (int i = 0; i < databaseSV.size() -1; i++)
    {
        for (int j = i+1; j < databaseSV.size(); j++)
        {
            if (databaseSV[i].getDiemTb() < databaseSV[j].getDiemTb())
            {
                swap(databaseSV[i],databaseSV[j]);
            }
        }
        
    }
}

// sắp xếp theo tên
void sorByName(vector<SinhVien>&databaseSV){
    for (int i = 0; i < databaseSV.size(); i++){
        for (int j = i+1; j < databaseSV.size(); j++)
        {
            if(databaseSV[i].getName() >databaseSV[j].getName()){
                swap(databaseSV[i], databaseSV[j]);
            }
        }
        
    }
    
}


int main() {
    vector<SinhVien> databaseSV;

    int key = 0;
    
    while (1){
        cout<< "1:Them SV\n2:Cập nhật thông tin SV\n3: Xóa Sinh Viên\n4: Tìm kiếm thông tin SV\n5: Sắp xếp theo điểm trung bình\n6: Sắp xếp dữ liệu theo tên\n7: Xuất dữ liệu sinh viên\n0: Thoát chương trình"<<endl;
        cout<<"Enter your choice ";
        cin >>key;

        switch(key)
        {
        case ADD:
            addSinhVien(databaseSV);
            break;
        case UPDATE:
            int id;
            updateSinhVien(databaseSV, id);
            break;
        case ERASE:
            printSV(databaseSV);
            eraseSV(databaseSV);
            break;
        case FIND:
            findSV(databaseSV);
            break;
        case SORTBYDIEMTB:
            sortByDiemTB(databaseSV);
            printSV(databaseSV);
            break;
        case SORTBYNAME:
            sorByName(databaseSV);
            break;
        case PRINT:
            printSV(databaseSV);
            break;
        case EXIT:
            return 0;
        defaut:
            break;
        
        }
    }
}
