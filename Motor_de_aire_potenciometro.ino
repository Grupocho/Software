int pin_motor = ?;
float motor;

void setup() {
  // put your setup code here, to run once:
  serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor = analogRead(?)/4;
  analogWrite(pin_motor,motor);
  Serial.print("motor: ");
  Serial.println(motor);
}
