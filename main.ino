/**********************
  Purdue University
  MET 482 Maze Car
  Arduino Control Code
  By: Christian Merkle
***********************/

#include<stdio.h>
#include <servo.h>
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

	if(pos[1] > pos[0] && pos[1] > pos[0]) {case= 1}
	elseif(pos[0] > pos[1] && pos [0] > pos[2]) {case= 0}
	elseif(pos[2] > pos[0] && pos[2] > pos[1]) {case= 2}
	else {case= 5}  

	switch (opt) {
		case '0':
			println(FOWARD);
		break;
		case '1':
                        ptintln(LEFT);
                break;
		case '2':
                        println(RIGHT);
                break;
		default:
			println(FUCK);
	}


}

void moana() {
	head.write(90); delay(5);
	pos[1]= sonicBOOM(); delay(5);
	//recording foward distance

	head.write(180); delay(5);
	pos[0]= sonicBOOM(); delay(5);
	//recordingleft distance

	head.write(10); delay(5);
	pos[2]= sonicBOOM(); delay(5);	
	//recording right distance
}

float sonicBOOM() {
	long duration; float distance;
	//variable decleration
	
	digitalWrite(A5, LOW); delayMicroseconds(2);
	digitalWrite(A5, HIGH); delayMicrosconds(10);
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

	analogWrite(5, N); analogWrite(11, N);
	delay(500);
	digitalWrite(5, LOW); digitalWrite(11, LOW);
	//motor pulse
}

void mvBWD(int N0) {
        digitalWrite(6, LOW); digitalWrite(7, HIGH);
        digitalWrite(8, HIGH); digitalWrite(9, LOW);
        //setting motor rotations

        analogWrite(5, N); analogWrite(11, N);
        delay(500);
        digitalWrite(5, LOW); digitalWrite(11, LOW);
        //motor pulse        
}

void mvRGT(int N1) {
        digitalWrite(6, LOW); digitalWrite(7, HIGH);
        digitalWrite(8, LOW); digitalWrite(9, HIGH);
        //setting motor rotations

        analogWrite(5, N); analogWrite(11, N);
        delay(500);
        digitalWrite(5, LOW); digitalWrite(11, LOW);
        //motor pulse        
}

void mvLFT(int N1) {
        digitalWrite(6, HIGH); digitalWrite(7, LOW);
        digitalWrite(8, HIGH); digitalWrite(9, LOW);
        //setting motor rotations

        analogWrite(5, N); analogWrite(11, N);
        delay(500);
        digitalWrite(5, LOW); digitalWrite(11, LOW);
        //motor pulse        
}
