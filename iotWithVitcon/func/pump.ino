#include <stdio.h>
#include <stdbool.h>

#define PUMP 16

void setup(){
    pinMode(PUMP, OUTPUT);
}

void ctrPUMP(bool c){
    if(c){
        digitalWrite(PUMP, HIGH); // RELAY ON
    }
    else{
        digitalWrite(PUMP, LOW); // RELAY OFF
    }
}
