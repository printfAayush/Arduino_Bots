#include <NewPing.h>
#include<Servo.h>
//wheels 
#define m1 2
#define m2 3
#define m3 4
#define m4 5
#define LED 9

#define trigPin 12
#define echoPin 13
#define max_distance 200
boolean goesFoward = false;
int distance = 100;

NewPing sonar(trigPin, echoPin, max_distance);
Servo servo; //servo motor

void setup(){
  servo.attach(8);
  servo.write(90);
  delay(2000);
   distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  pinMode(LED,OUTPUT);
   }

   //look right
int lookRight(){
  servo.write(10);
  delay(500);
  int distance = readPing();
  delay(100);
  servo.write(90);
  return distance;
 }

   //look left
 int lookLeft(){
  servo.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo.write(90);
  return distance;
  }
  //reading ping
 int readPing(){
    delay(70);
    int cm = sonar.ping_cm();
    if(cm==0){
      cm =250;}
    return cm;
    }
    //movement
void moveStop(){
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
  digitalWrite(LED, HIGH);
  }

void moveFoward(){
   digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
  }
void moveBackwards(){
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
  }
void moveRight(){
   digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
  delay(500);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
  
  }
 void moveLeft(){
   digitalWrite(m1,LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
  delay(500);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
  }

//LOOP
void loop(){
  
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);
  if (distance <= 20){
    moveStop();
    delay(300);
    moveBackwards();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

   if (distanceRight >= distanceLeft){
    moveRight();
    moveStop();
    }
   else{
    moveLeft();
    moveStop();
    }
   } 
 else{
  moveFoward();
  digitalWrite(LED,LOW);
  } 
  distance = readPing();
  
}


  
