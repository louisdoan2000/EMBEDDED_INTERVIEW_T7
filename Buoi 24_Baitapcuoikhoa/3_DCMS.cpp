#include <iostream>
#include <stdbool.h>
#include <math.h>

using namespace std;

typedef enum {
    CLOCKWISE,
    COUNTERCLOCKWISE
}typeDirection;

class DCMotor {
    private:
        double VOLTAGE;
        double maxCURRENT;
        double SPEED;
        double TEMPERATURE;
        typeDirection DIRECTION;
        bool isRunning;
    public:
        void setSpeed( double speed);
        void setDirection(typeDirection direction);
        void setVoltage(double voltage);
        void setCurrent(double current);
        void setTemperature(double temperature);
        double getCurrent();
        double getTemperature();
        bool startWorking();
        bool stopWorking();
};

void DCMotor::setSpeed(double speed){
   this->SPEED = speed;
}

void DCMotor::setDirection(typeDirection direction){
    this->DIRECTION = direction;
}

void DCMotor::setVoltage(double voltage){
    this->VOLTAGE = voltage;
}

void DCMotor::setCurrent(double current){
    this->maxCURRENT = current;
} 

void DCMotor::setTemperature(double temperature){
    this->TEMPERATURE = temperature;
}

double DCMotor::getCurrent(){
    return maxCURRENT;
}

double DCMotor::getTemperature(){
    return TEMPERATURE;
}

bool DCMotor::startWorking(){
    return isRunning;
}

bool DCMotor::stopWorking(){
    return !isRunning;
}




class FeedbackSystem {
    private:
        DCMotor DCMOTOR;
    public:
        
        void overloadDetected(double currentFeedback);
        void overheatDetected(double temperatureFeedback);
        DCMotor& getDCmotor();
};

DCMotor& FeedbackSystem::getDCmotor(){
    return DCMOTOR;
}

void FeedbackSystem::overheatDetected(double temperatureFeedback){
    if(DCMOTOR.getTemperature() > temperatureFeedback) {

        DCMOTOR.stopWorking();
        cerr<<" Overheat detected!!!"<<endl;}
    else {

        DCMOTOR.startWorking();
        cerr<<" Working normally "<<endl;
        }
}
   

void FeedbackSystem::overloadDetected(double currentFeedback){
    if(DCMOTOR.getCurrent() > currentFeedback) {
    DCMOTOR.stopWorking();
    cerr<<" Overload detected!!!"<<endl;
    }
    else{
        DCMOTOR.startWorking();
        cerr<<" Working normally!!!"<<endl;
    } 
}



class DCMotorController {
    private:
        FeedbackSystem FEEDBACKSYSTEM;
        //DCMotor DCMOTOR;
    public:
        
        DCMotorController(double voltage, double maxcurrent, double temperature);
       
        void setMotorDirection(typeDirection direction);
        void setMotorSpeed(double speed);
        
        void controlMotor(double currentFeedback, double temperatureFeedback);
};


DCMotorController::DCMotorController(double voltage, double maxcurrent, double temperature){
        FEEDBACKSYSTEM.getDCmotor().setVoltage(voltage);
        FEEDBACKSYSTEM.getDCmotor().setCurrent(maxcurrent);
        FEEDBACKSYSTEM.getDCmotor().setTemperature(temperature);
}

void DCMotorController::setMotorDirection(typeDirection direction){
    FEEDBACKSYSTEM.getDCmotor().setDirection(direction);
}

void DCMotorController:: setMotorSpeed(double speed){
    FEEDBACKSYSTEM.getDCmotor().setSpeed(speed);
}

void DCMotorController::controlMotor(double currentFeedback, double temperatureFeedback){
    FEEDBACKSYSTEM.overheatDetected(temperatureFeedback);
    FEEDBACKSYSTEM.overloadDetected(currentFeedback);
}


int main(int argc, char const *argv[])
{
    DCMotorController dcController(12.0, 1.5, 70);

    dcController.setMotorDirection(CLOCKWISE);
    dcController.setMotorSpeed(1000);

    double currentFeedback = 1.4;
    double temperatureFeedback = 80; 
    dcController.controlMotor(currentFeedback,temperatureFeedback);

    return 0;
}
