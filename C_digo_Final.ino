#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <RTClib.h>
#include <LCDWIKI_GUI.h> 
#include <LCDWIKI_SPI.h> 

#define MODEL ILI9341
#define CS   A5    
#define CD   A3
#define RST  A4
#define LED  A0

LCDWIKI_SPI mylcd(MODEL,CS,CD,RST,LED); 
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

int rly1=3;
int rly2=4;
int IN1=7;
int ENA=8;
int interruptor=9;
int motor;
int SWITCH;
int pinCS = 10;

File archivo;
void text_test(){
  mylcd.Set_Rotation(1);
  mylcd.Set_Text_Mode(0);
  
  mylcd.Fill_Screen(MAGENTA);  
  mylcd.Set_Text_Back_colour(MAGENTA);
  mylcd.Set_Text_colour(WHITE);
  mylcd.Set_Text_Size(2.5);
  mylcd.Print_String("BIENVENIDO USUARIO, ", 0, 15);
  
 

  mylcd.Set_Text_colour(WHITE);
  mylcd.Set_Text_Size(2);
  mylcd.Print_String("  Listo paara realizar", 0, 90);

  mylcd.Set_Text_Size(2);
  mylcd.Print_String("  tu terapia...", 0, 112);
  mylcd.Print_String("  entonces,", 0, 152);
  mylcd.Print_String("    COMENCEMOS!", 0, 200);
}

void homescreen() {
  mylcd.Fill_Screen(BLACK);
  mylcd.Set_Text_Back_colour(RED);
  mylcd.Set_Text_colour(WHITE);
 
  mylcd.Set_Text_Size(2);
  
  mylcd.Fill_Rectangle(0, 120, mylcd.Get_Display_Width()-1,60);
  mylcd.Print_String("NEBULIZACION",90,80); 
  mylcd.Fill_Rectangle(0, 200, mylcd.Get_Display_Width()-1,140);
  mylcd.Print_String("TERAPIA PEP",90,160);
  }

void temporizador(){
  mylcd.Fill_Screen(BLACK);
  mylcd.Set_Text_Back_colour(BLACK);
  mylcd.Set_Text_Size(4);
  mylcd.Set_Text_colour(WHITE);
  mylcd.Print_String("<--",0,0);
  mylcd.Set_Text_Size(3);
  mylcd.Set_Text_colour(WHITE);
  mylcd.Print_String("10:00",100,80);
  mylcd.Set_Text_Back_colour(GREEN);
  mylcd.Set_Text_colour(BLACK);
  mylcd.Print_String(" COMENZAR! ",90,140);
}

void recomendaciones(){
  mylcd.Fill_Screen(BLACK);
  mylcd.Set_Text_Back_colour(BLACK);
  mylcd.Set_Text_Size(3);
  mylcd.Set_Text_colour(WHITE);
  mylcd.Print_String("OJO",140,70);
  mylcd.Set_Text_Size(2);
  mylcd.Print_String("Asegurate que el deposito",15,130);
   mylcd.Print_String("se encuentre lleno. ",70,150);
}
void setup() {
  
  Serial.begin(9600);
  pinMode(rly1,OUTPUT);
  pinMode(rly2,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(pinCS, OUTPUT);
  pinMode(interruptor,INPUT);

  mylcd.Init_LCD();
  text_test();
  delay(5000);
  homescreen();
  delay(4000);
  recomendaciones();
  delay(4000);
  temporizador();
  delay(3000);
  homescreen();
  delay(2000);
  temporizador();
  delay(2000);
  homescreen();
  delay(5000);
  
  if(SD.begin()){
    Serial.println("SD card esta lista para usar");
  }else{
    Serial.println("SD card fallo inicializando");
    return;
  }
  Serial.println("inicializacion correcta");
  archivo = SD.open("datos.txt",FILE_WRITE);

  if(archivo){
    for(int i=1; i<30; i++){
      SWITCH=digitalRead(interruptor);

      archivo.print(i);
      archivo.print(";");
      archivo.print(SWITCH);

      Serial.print(i);
      Serial.print(";");
      Serial.print(SWITCH);

      delay(1000);
    }
    archivo.close();
    Serial.println("escritura correcta");   
  } else{
    Serial.println("error en apertura en datos.txt");
  }  
}

void loop() {

    motor=digitalRead(interruptor);
  
  if(motor==HIGH){
    digitalWrite(rly1,HIGH);
    digitalWrite(rly2,LOW);
    digitalWrite(IN1,HIGH);
    digitalWrite(ENA,HIGH);
    Serial.println("relee accionado\n");
    delay(1000);
    return;
  }
  if(motor==LOW){
    digitalWrite(rly1,LOW);
    digitalWrite(rly2,HIGH);
    digitalWrite(IN1,LOW);
    Serial.println("relee no accionado\n");
    delay(1000);
    return;
  }
/* if(mylcd.data()){
    mylcd.read();
    x=mylcd.getX();
    y=mylcd.getY();

    if((x>=90)&&(x<=100)&&(y>=80)&&(y<=100)){
      
    }

    if((x>=90)&&(x<=100)&&(y>=140)&&(y<=160)){
      
    }
  }
  */


}
