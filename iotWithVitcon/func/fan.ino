#include <stdio.h>
#include <stdbool.h>
// 제공하는 라이브러리 사용
#include <SoftPWM.h>

SOFTPWM_DEFINE_CHANNEL(A3); // FAN

void setup(){
    SoftPWM.begin(490); // FAN
}

void loop(){
    
}

void ctrFAN(bool b){
    if(b){
        SoftPWM.set(100);
    }
    else{
        SoftPWM.set(0);
    }
    return;
}

