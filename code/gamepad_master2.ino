#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1);  // указываем пины, которые будут выполнять роль rx и tx
int tank_forward = 2;
int tank_back = 3;
int tank_right = 4;
int tank_left = 5;
int change = 6;
int gun_up = 2;
int gun_down = 3;
int gun_right = 4;
int gun_left = 5;
int fire = 7;

int flag = 0;
int flag_fire = 0;
int flag2 = 0;
int flag_change = 0;
int flag_tf = 0;
int flag_gu = 0;
int flag_gd = 0;



void setup() {
  pinMode(tank_forward, OUTPUT);
  pinMode(tank_back, OUTPUT);
  pinMode(tank_right, OUTPUT);
  pinMode(tank_left, OUTPUT);
  pinMode(gun_up, OUTPUT);
  pinMode(gun_down, OUTPUT);
  pinMode(gun_right, OUTPUT);
  pinMode(gun_left, OUTPUT);
  pinMode(fire, OUTPUT);
  pinMode(change, OUTPUT);
  mySerial.begin(38400);

}


void loop() {
  
  if (digitalRead(tank_forward) || digitalRead(gun_up)){
    mySerial.write('F');
  }
  else if (digitalRead(tank_back) || digitalRead(gun_down)){
    mySerial.write('B');
  }
  else if (digitalRead(tank_right) || digitalRead(gun_right)){
    mySerial.write('R');
  }
  else if (digitalRead(tank_left) || digitalRead(gun_left)){
    mySerial.write('L');
  }
  else{
    mySerial.write('S');
  }

  
  if (digitalRead(fire) && flag_fire == 0){
    mySerial.write('V');
    flag_fire = 1;
  }
  else if (!digitalRead(fire)){
    flag_fire = 0;
  }
  
  if (digitalRead(change) && flag2 == 0){
    if (flag_change == 0){
      flag_change = 1;
      mySerial.write('W');
    }
    else if (flag_change == 1){
      flag_change = 0;
      mySerial.write('w');
    }
    flag2 = 1;
  }
  else if (!digitalRead(change)){
    flag2 = 0;
  }
  
  /*if (!digitalRead(tank_forward) && !digitalRead(tank_back) && !digitalRead(tank_right) && !digitalRead(tank_left) && !digitalRead(gun_up) && !digitalRead(gun_down) && !digitalRead(gun_left) && !digitalRead(gun_right)){
    mySerial.write('S');
  }/*

  
  /*if (digitalRead(pres) == HIGH && flag == 0){
    mySerial.write('A');
    flag = 1;
  }
  if (digitalRead(pres) == LOW && flag == 1){
    mySerial.write('a');
    flag = 0;
  }*/ // на нажатие и отжатие кнопки подаётся по одной букве
  /*if (digitalRead() == HIGH){
    mySerial.write('B');
  }*/ // пока кнопка нажата, подаётся буква
}
