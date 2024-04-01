#include "mbed.h"
#include "MotorControl.hpp"

MotorCtrl motor(D4, D5, D7, D8);

float setpoint = 40.0;

int main() {
    
    motor.motor.set_pid_gain(20.0, 0.001, 0.005, 0.0);

    motor.set_encoder_resolution(0.0007633);
    motor.init();
    motor.start();

    while(1) {
        motor.update();
        motor.setSpeed(setpoint);

        printf("%f, %f\n",setpoint, motor.getMotorSpeed());
        wait_us(1000);
    }
    
}