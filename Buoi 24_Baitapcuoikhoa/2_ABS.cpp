#include <iostream>
#include <stdbool.h>
#include <math.h>


using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////
class Wheel {
    private:
        double SPEED;
    public:
       
        Wheel() : SPEED(0.0) {}
        void setSpeed(double speed);
        double getSpeed();
};


void Wheel::setSpeed(double speed){
    SPEED = speed;
}

double Wheel::getSpeed(){
    return SPEED;
}


/////////////////////////////////////////////////////////////////////////////////////////////////
class Car {
    private:
        Wheel WHEEL;
        const double WEIGHT;
        double PASSENGER;
    public:
   
        Car() : WEIGHT(1000.0), PASSENGER(0.0) {}
        void addPassenger(double weightPassenger) { PASSENGER += weightPassenger;}
        double getTotalWeight() ;
        Wheel& getWheel();
};

double Car::getTotalWeight(){
    return WEIGHT + PASSENGER ;
}

Wheel& Car::getWheel(){
    return WHEEL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
class ABS {
    private:
        Car& CAR;
        const double threshold = 20.0;
    public:
        ABS(Car& car): CAR(car) {}
        void applyABS();        
};

void ABS::applyABS(){

    double wheelSpeed =  CAR.getWheel().getSpeed();
    double carWeight  =  CAR.getTotalWeight();

    if( wheelSpeed < threshold ) 
    cerr<< "Warning: Your break is locking up! Adjusting the break system based on car weight"<<endl;
    else
    cerr<<"ABS is working"<<endl;
};

int main(int argc, char const *argv[])
{
    Car car;
    ABS abs(car);

    car.getWheel().setSpeed(40.0);
    abs.applyABS();

    double weightPassenger = 70.0;
    car.addPassenger(70.0);
    car.getWheel().setSpeed(25.0);
    abs.applyABS();

    return 0;
}


