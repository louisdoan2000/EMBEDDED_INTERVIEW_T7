#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef enum{
    ADD = 1,
    ERASE = 2,
    PRINT= 7
    
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
    public:
        SinhVien(string name, int tuoi, typeGioiTinh gioitinh, double diem_toan, double diem_ly, double diem_hoa);

        void setName(string name);
        void setTuoi(int tuoi);
        void setGioiTinh(typeGioiTinh gioitinh);
        void setDiemToan(double diem_toan);
        
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
};


void SinhVien::setName (string name){
    NAME = name;
};

void SinhVien::setTuoi(int tuoi){
    TUOI = tuoi;
};

void SinhVien::setGioiTinh(typeGioiTinh gioitinh){
    GIOITINH = gioitinh;
};

void SinhVien::setDiemToan(double diemtoan){
    DIEM_TOAN = diemtoan;
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
//Hàm xóa Sinh Viên
// void eraseSV(vector<SinhVien> &databaseSV){

//     for (uint8_t i = 0; i < databaseSV.size(); i++){
//         databaseSV[i].getId() = id;
//         databaseSV.erase[i];
//     }
// }

void addSinhVien(vector<SinhVien> &databaseSV) {

    int i = 0;
    do{
    cout<< "\nNhap name: ";
    string name; cin >> name;


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




    // SinhVien sv = {name, tuoi, gioitinh, 8, 9, 4};

    // databaseSV.push_back(sv);
    cout<<"\nADD sucessfully\n\n";

    cin >>i;
    cout <<"1: Tiep tuc\n0: Quay lai";
    } 
    while(i == 1);
    
}

    

//In danh sách sinh viên
void xuatSV(vector<SinhVien> &databaseSV) 
{

	for (int i = 0; i < databaseSV.size(); i++)
	{
		cout << " -------------------------------------------------------"<< endl;
		cout << "|    ID    |          Name         |  Tuoi  |  Diem TB  |" << endl;
		cout <<databaseSV[i].getID() << " | " << databaseSV[i].getName() << databaseSV[i].getTuoi() << " | " << databaseSV[i].getDiemTb() << " |" << endl;
		cout << " -------------------------------------------------------"<< endl;
	}

}



int main() {
    vector<SinhVien> databaseSV;

    int key = 0;
    
    while (1){
        cout<< "1:Them SV\n....\n7:Xuất";
        cin >>key;

        switch(key)
        {
        case ADD:
            addSinhVien(databaseSV);
        // case ERASE:
        //     break;
        case PRINT:
            xuatSV(databaseSV);
        defaut:
            break;
        }
    }
}
// 1: Thêm SinhVien
// 2: Cập nhật tt sv bằng ID( nhập ID vào để sửa tên, tuổi,....)
// 3: Xóa SV bởi ID( bấm phím 3 thì sẽ hiện danh sách sv, sau đó nhập mssv để xóa sinh viên đó) 
// 4: Tìm kiếm SV theo tên(nhập tên thì hiện ra các thông tin còn lại )
// 5: Sắp xếp SV theo điểm TB (ban đầu sẽ lưu vào 1 vector sau đó sắp xếp các sinh viên tăng dần)
// 6: Sắp xếp SV theo tên (có thể dùng hàm so sánh tên)
// 7: Hiển thị Danh sách SV 
// 0: quay lại chương trình