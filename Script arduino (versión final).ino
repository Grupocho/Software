int rly1=3;
int rly2=4;
int IN1=7;
int ENA=8;
int interruptor=11;
int motor;

void setup() {
  Serial.begin(9600);
  pinMode(rly1,OUTPUT);
  pinMode(rly2,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(interruptor,INPUT);
}

void loop() {
  motor=digitalRead(interruptor);
  
  if(motor==HIGH){
    digitalWrite(rly1,HIGH);
    digitalWrite(rly2,LOW);
    digitalWrite(IN1,HIGH);
    digitalWrite(ENA,1000);
    delay(1000);
    Serial.print("relee accionado\n");
  }
  if(motor==LOW){
    digitalWrite(rly1,LOW);
    digitalWrite(rly2,HIGH);
    digitalWrite(IN1,LOW);
    delay(1000);
    Serial.print("relee no accionado\n");
  }
}
