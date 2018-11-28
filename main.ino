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

int pos[3];
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
	int N0= 100; int N1= 50;

}

void moana() {


}

int sonicBOOM() {
	

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
