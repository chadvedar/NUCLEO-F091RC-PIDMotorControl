#include "mbed.h"
#include "RotaryEncoder.hpp"
#include "PIDmotor.hpp"

PIDmotor pidMotor(D5, D4);
RotaryEncoder enc(D7, D8);

float setpoint = 40.0;

int main() {
    
    pidMotor.set_pid_gain(20.0, 0.001, 0.005, 0.0);

    enc.encoder_resolution = 0.000625;
    enc.init();
    pidMotor.init();

    enc.start();
    pidMotor.start();

    while(1) {
        pidMotor.update_current_speed(enc.rpm);
        pidMotor.set_target_speed(setpoint);

        printf("%f, %f\n",setpoint, enc.rpm);
        ThisThread::sleep_for(1ms);
    }
    
}