#include <Servo.h>
#define L_DIR 4
#define R_DIR 9
#define L_PWM 5
#define R_PWM 6
#define SERVO 11

Servo serwo;

void define(){
  pinMode(L_DIR, OUTPUT);
  pinMode(R_DIR, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(R_PWM, OUTPUT);
}

void przod(int time){
  digitalWrite(L_DIR, 0); 
  digitalWrite(R_DIR, 0); 
  analogWrite(L_PWM, 50); 
  analogWrite(R_PWM, 50);
  delay(time);
  stop_silnik();
}

void stop_silnik(){
  analogWrite(L_PWM, 0); //Wylaczenie silnika
  analogWrite(R_PWM, 0); //Wylaczenie silnika
}

void obrot(int time){
  digitalWrite(L_DIR, 0); 
  digitalWrite(R_DIR, 1);
  analogWrite(L_PWM, 20); 
  analogWrite(R_PWM, 20);
  delay(time);
  stop_silnik();
}

void podnies_servo(){
  serwo.write(180);
}

void opusc_servo(){
  serwo.write(0);
}

void litera_B(){
  przod(800); //dlugi B
  obrot(320); //brot 90st
}

void arch(int time){
  digitalWrite(L_DIR, 0); 
  digitalWrite(R_DIR, 0); 
  analogWrite(L_PWM, 40); 
  analogWrite(R_PWM, 5);
  delay(time);
  stop_silnik();
}


void setup() {
  define();
  serwo.attach(SERVO);
}

// 0 do przodu
// 1 do tyłu
 
void loop() {
  litera_B();
  arch(1350);
  obrot(640);
  delay(10000);
}
