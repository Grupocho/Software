#include <Servo.h>

int val = 0;

Servo servo;

void setup() {

  Serial.begin(115200);
  servo.attach(9);
  servo.write(0);
}

void loop() {
 
    if(Serial.available()>0){
      val=Serial.parseInt();
      val=90;
      if(val >= 0 and val <= 180){
        Serial.print("Enviados: ");
        Serial.println(val);
          servo.write(val);
      }
    }
    delay(600000);
}
