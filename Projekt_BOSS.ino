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
  analogWrite(L_PWM, 40); 
  analogWrite(R_PWM, 43);
  delay(time);
  stop_silnik();
}

void back(int time){
  digitalWrite(L_DIR, 1); 
  digitalWrite(R_DIR, 1); 
  analogWrite(L_PWM, 40); 
  analogWrite(R_PWM, 43);
  delay(time);
  stop_silnik(); 
}

void stop_silnik(){
  analogWrite(L_PWM, 0); //Wylaczenie silnika
  analogWrite(R_PWM, 0); //Wylaczenie silnika
}
void obrot_L(int time){
  digitalWrite(L_DIR, 0); 
  digitalWrite(R_DIR, 1);
  analogWrite(L_PWM, 70); 
  analogWrite(R_PWM, 73);
  delay(time);
  stop_silnik();
}

void obrot(int time){
  digitalWrite(L_DIR, 1); 
  digitalWrite(R_DIR, 0);
  analogWrite(L_PWM, 70); 
  analogWrite(R_PWM, 73);
  delay(time);
  stop_silnik();
}

void podnies_servo(){
  serwo.write(25);
}

void opusc_servo(){
  serwo.write(0);
}

void litera_B(){
  opusc_servo();
  przod(1200); //dlugi B
  podnies_servo();
  obrot(500); //brot 90st
  opusc_servo();
  arch(1800, 45);
  arch_back(1600, 65);
  stop_silnik();
  delay(1000);

}

void litera_R(){
  opusc_servo();
  przod(1200); //dlugi B
  podnies_servo();
  obrot(500); //brot 90st
  opusc_servo();
  arch(2000, 45);
  back(1500);
  stop_silnik();
  delay(1000);

}
void arch_back(int time, int v){
  digitalWrite(L_DIR, 1); 
  digitalWrite(R_DIR, 1); 
  analogWrite(L_PWM, v); 
  analogWrite(R_PWM, 5);
  delay(time);
  stop_silnik();
}

void arch(int time, int velocity){
  digitalWrite(L_DIR, 0); 
  digitalWrite(R_DIR, 0); 
  analogWrite(L_PWM, 5); 
  analogWrite(R_PWM, velocity);
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
  delay(1500);
  litera_B(); 
  przod(800);
  obrot_L(260);
  litera_B();
  przod(800);
  obrot_L(260);
  litera_R();
  delay(10000);
}
