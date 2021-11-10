int relee1=2;
int relee2=4;
int IN1=1;
int IN2=3;
int ENA=5;

void setup() {
  pinMode(relee1,OUTPUT);
  pinMode(relee2,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENA,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(relee1,HIGH);
  digitalWrite(relee2,HIGH);
  Serial.println("Relee accionado");
  
  digitalWrite(ENA,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  Serial.println("motor accionado");
  delay(600000);

  digitalWrite(ENA,LOW);
  delay(600000);
}
