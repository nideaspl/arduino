#include <Servo.h>

Servo duoji1;
Servo duoji2;
int dReact =10;
const int L = 1524;
const int R = 1550;
const int a =100;
int TL;
int TR;
int trigPin = 8;
int echoPin = 9;
int cm;
int time90=1900;
int time92=1450;
int time1 =3000;
int time2 =7000;
void setup() {
  Serial.begin(9600);
pinMode (A0,INPUT);
 pinMode (A5,INPUT);
duoji1.attach(5);
duoji2.attach(6);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);// put your setup code here, to run once:
cm=100;

}

void loop() {
  digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
cm = pulseIn(echoPin, HIGH)/58.0;
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(10);
if (cm<=dReact){
 duoji1.writeMicroseconds(L+50);
 duoji2.writeMicroseconds(R+50);
 delay(time90); 
  duoji1.writeMicroseconds(L+50);
 duoji2.writeMicroseconds(R-50);
 delay(time1); 
  duoji1.writeMicroseconds(L-50);
 duoji2.writeMicroseconds(R-50);
 delay(time92); 
   duoji1.writeMicroseconds(L+50);
 duoji2.writeMicroseconds(R-50);
 delay(time2); 
   duoji1.writeMicroseconds(L-50);
 duoji2.writeMicroseconds(R-50);
 delay(time92); 
 duoji1.writeMicroseconds(L+50);
 duoji2.writeMicroseconds(R-50);
 delay(time1); 
 duoji1.writeMicroseconds(L+50);
 duoji2.writeMicroseconds(R+50);
 delay(time90);
}
else
 TL = analogRead(A0);
TR = analogRead(A5);
if (TL>=a && TR>=a ){
duoji1.writeMicroseconds(L+50);
duoji2.writeMicroseconds(R-50);
delayMicroseconds(25);
}else if(TL >= a && TR <= a){
duoji1.writeMicroseconds(L);
duoji2.writeMicroseconds(R-50);
delay(100);
}else if (TL <= a && TR <= a){

duoji1.writeMicroseconds(L+50);
duoji2.writeMicroseconds(R-50);
delayMicroseconds(10);
}else{
duoji1.writeMicroseconds(L+50);
duoji2.writeMicroseconds(R);
delay(100);
}
}




// put your main code here, to run repeatedly:


