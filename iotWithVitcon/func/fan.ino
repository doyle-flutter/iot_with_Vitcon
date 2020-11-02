#include <stdio.h>
#include <stdbool.h>
#include <SoftPWM.h>

SOFTPWM_DEFINE_CHANNEL(A3); // FAN

void setup(){
    SoftPWM.begin(490); // FAN
}

void loop(){
    
}

void ctrFAN(boolean b){
    if(b){
        SoftPWM.set(100);
    }
    else{
        SoftPWM.set(0);
    }
    return;
}

