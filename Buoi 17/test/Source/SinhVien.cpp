#include "SinhVien.hpp"
#include <stdio.h>
#include <iostream>
#include <string>

void SinhVien::setInfor(string ten, int tuoi){
    TEN = ten;
    TUOI = tuoi;
}

void SinhVien::display(){
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Tuoi: "<<TUOI<<endl;
}

void HocSinh::setInfor(string ten, int tuoi, int mshs){
    TEN = ten;
    TUOI = tuoi;
    MSHS = mshs;
}

void HocSinh::display(){
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Tuoi: "<<TUOI<<endl;
    cout<<"MSHS: "<<MSHS<<endl;
}
