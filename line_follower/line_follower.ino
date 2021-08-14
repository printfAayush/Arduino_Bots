//wheels 
#define m1 2
#define m2 3
#define m3 4
#define m4 5

#define s0 7
#define s1 10
void setup(){ 
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  
 
pinMode(s0, INPUT); // initialize Right sensor as an inut
pinMode(s1, INPUT); // initialize Left sensor as as input

}

void loop(){
  int left = digitalRead(s0);
  int right = digitalRead(s1);
  //foward
  if (right == 1 && left == 1){
    digitalWrite(m1 , HIGH);
    digitalWrite(m2 , LOW);
    digitalWrite(m3 , HIGH);
    digitalWrite(m4 , LOW);
    }
  //stop
  else if (right == 0 && left == 0){
    digitalWrite(m1 , LOW);
    digitalWrite(m2 , LOW);
    digitalWrite(m3 , LOW);
    digitalWrite(m4 , LOW);
    delay(1000);
    }  
  //right 
  else if (right == 0 && left == 1){
    digitalWrite(m1 , LOW);
    digitalWrite(m2 , HIGH);
    digitalWrite(m3 , HIGH);
    digitalWrite(m4 , LOW);
    }
  else if (right == 1 && left == 0 ){
    digitalWrite(m1 , HIGH);
    digitalWrite(m2 , LOW);
    digitalWrite(m3 , LOW);
    digitalWrite(m4 , HIGH);
    
    }
  
  
  
  
  }
