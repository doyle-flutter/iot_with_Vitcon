#define SOILHUMI A6
int Soilhumi = 0; // 습도 기준

void setup() {
    pinMode(SOILHUMI, INPUT);
}

int crtGetHum(){ // typeCheck
    //토양 습도 단계를 0~1023에서 0~100으로 변환
    Soilhumi = map(analogRead(SOILHUMI), 0, 1023, 100, 0);
    return Soilhumi;
}
