#include "DHT.h"
#define DHTPIN A1 
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    dht.begin();
}

// 3.1f
float ctrGetTemp(){
    return dht.readTemperature();
}
