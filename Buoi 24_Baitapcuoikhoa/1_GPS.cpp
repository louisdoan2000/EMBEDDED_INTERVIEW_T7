#include <iostream>
#include <stdbool.h>
#include <math.h>



using namespace std;
const double EARTH_RADIUS = 6371;

class GPSPoint{
    private:
        double LATITUDE;
        double LONGITUDE;
    public:
        void input();
        bool isValid();
        double toRadian(double degree);
        double distanceTo(GPSPoint gpspoint1, GPSPoint gpspoint2);
        double getLatitude();
        double getLongitude();
};
double GPSPoint::getLatitude(){
    return LATITUDE; 
}

double GPSPoint::getLongitude(){
    return LONGITUDE;
}
void GPSPoint::input(){  
    cout << "Nhập vĩ độ: "<<endl; cin >> LATITUDE;
    cout << "Nhap kinh độ: "<<endl; cin>> LONGITUDE;
}

bool GPSPoint::isValid(){
    return (LATITUDE >=-90.0 && LATITUDE <= 90.0) && (LONGITUDE >=-180.0 && LONGITUDE <= 180.0);
    
}

double GPSPoint::toRadian(double degree){
   return (degree*M_PI)/180.0;
}

double GPSPoint::distanceTo(GPSPoint gpspoint1, GPSPoint gpspoint2){
    
    
    double lat1 = toRadian(gpspoint1.getLatitude());
    double lat2 = toRadian(gpspoint2.getLongitude());

    double lng1 = toRadian(gpspoint1.getLatitude());
    double lng2 = toRadian(gpspoint2.getLatitude());

    return 6371*2*asin(sqrt(pow(sin((lat2-lat1)/2),2)+cos(lat1)*cos(lat2)*pow(sin((lng2-lng1)/2),2)));
}

int main(int argc, char const *argv[])
{
    GPSPoint gpspoint1, gpspoint2;

    cout<< "Nhập vào tọa độ điểm 1"<<endl;
    do{ 
        gpspoint1.input();
        if(!gpspoint1.isValid()) 
        {cout <<" Tọa độ điểm khong hợp lệ. Vui long nhap lai"<<endl;}
    } while (!gpspoint1.isValid());


    cout<< "Nhập vào tọa độ điểm 2"<<endl;
    do{
        gpspoint2.input();
        if(!gpspoint2.isValid()) cout <<" Tọa độ điểm không hợp lệ "<<endl;
    } while (!gpspoint2.isValid());
    
    cout<<"Khoảng cách 2 điểm tọa độ bằng "<< gpspoint1.distanceTo(gpspoint1, gpspoint2)<< " km"<<endl;
    return 0;
}

