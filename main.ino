/**********************
  Purdue University
  MET 482 Maze Car
  Arduino Control Code
  By: Christian Merkle
***********************/

#include<stdio.h>
#include <Servo.h>
#include <math.h>
//including libraries

Servo head;
//defining servo object for sensor head

float pos[3];
//defining global array for distance data storage

void setup() {
	Serial.begin(9600);
	//establishing serial communication

	pinMode(A4, INPUT); pinMode(A5, OUTPUT);
	pinMode(5, OUTPUT); pinMode(11, OUTPUT);
	pinMode(6, OUTPUT); pinMode(7, OUTPUT);
	pinMode(8, OUTPUT); pinMode(9, OUTPUT);
	//pin setup

	head.attach(3);
	//attaching head servo object to control pin
}

void loop() {
	int N0= 100; int N1= 50; int opt;
	//variable decleration

	moana();

	if(pos[1] > pos[0] & pos[1] > pos[0]) {opt= 1;}
	else if(pos[0] > pos[1] & pos [0] > pos[2]) {opt= 0;}
	else if(pos[2] > pos[0] & pos[2] > pos[1]) {opt= 2;}
	else {opt= 5;}  

	switch (opt) {
		case '0':
			Serial.print("FOWARD \n");
		break;
		case '1':
      Serial.print("LEFT \n");
    break;
		case '2':
		  Serial.print("RIGHT \n");
    break;
		default:
			Serial.print("FUCK \n");
      Serial.print(pos[0]); Serial.print("\t");
      Serial.print(pos[1]); Serial.print("\t");
      Serial.print(pos[2]); Serial.print("\n");

    delay(100);
	}


}

void moana() {
	head.write(90); delay(250);
	pos[1]= sonicBOOM(); delay(1000);
	//recording foward distance

	head.write(165); delay(250);
	pos[0]= sonicBOOM(); delay(1000);
	//recording left distance

	head.write(10); delay(250);
	pos[2]= sonicBOOM(); delay(1000);	
	//recording right distance
}

float sonicBOOM() {
	long duration; float distance;
	//variable decleration
	
	digitalWrite(A5, LOW); delayMicroseconds(2);
	digitalWrite(A5, HIGH); delayMicroseconds(10);
	digitalWrite(A5, LOW);
	//creating sonic pulse

	duration= pulseIn(A4, HIGH);
	distance= (duration/2)/29.1;
	
	return distance;	
}

void mvFWD(int N0) {
	digitalWrite(6, HIGH); digitalWrite(7, LOW);
	digitalWrite(8, LOW); digitalWrite(9, HIGH);
	//setting motor rotations

	analogWrite(5, N0); analogWrite(11, N0);
	delay(500);
	digitalWrite(5, LOW); digitalWrite(11, LOW);
	//motor pulse
}

void mvBWD(int N0) {
        digitalWrite(6, LOW); digitalWrite(7, HIGH);
        digitalWrite(8, HIGH); digitalWrite(9, LOW);
        //setting motor rotations

        analogWrite(5, N0); analogWrite(11, N0);
        delay(500);
        digitalWrite(5, LOW); digitalWrite(11, LOW);
        //motor pulse        
}

void mvRGT(int N1) {
        digitalWrite(6, LOW); digitalWrite(7, HIGH);
        digitalWrite(8, LOW); digitalWrite(9, HIGH);
        //setting motor rotations

        analogWrite(5, N1); analogWrite(11, N1);
        delay(500);
        digitalWrite(5, LOW); digitalWrite(11, LOW);
        //motor pulse        
}

void mvLFT(int N1) {
        digitalWrite(6, HIGH); digitalWrite(7, LOW);
        digitalWrite(8, HIGH); digitalWrite(9, LOW);
        //setting motor rotations

        analogWrite(5, N1); analogWrite(11, N1);
        delay(500);
        digitalWrite(5, LOW); digitalWrite(11, LOW);
        //motor pulse        
}
