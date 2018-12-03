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

int ctFWD= 0; int ctRGT= 0; int ctLFT= 0;
//counter intialization

Servo head;
//defining servo object for sensor head

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
	int N0= 116; int N1= 100;
	int N2= 146; int N3= 130; 
	int opt;
	//variable decleration

	mvFWD(N0, N1);
	opt= moana();
	
	switch (opt) {
		case 0:
			ctLFT ++; Serial.print("\nctLFT: "); Serial.print(ctLFT);
			if (ctLFT == 9) {mvLFT(N2, N3); delay(100); ctLFT= 0;}
			else {delay(10);}
		break;
		case 1:
			ctLFT= 0; ctRGT= 0;
			delay(100);
    		break;
		case 2:
			ctRGT ++; Serial.print("\nctRGT: "); Serial.print(ctRGT);
			if (ctRGT == 8) {mvRGT(N2, N3); delay(100); ctRGT= 0;}
			else{delay(10);}
    		break;
		default:
			Serial.print("FUCK \n");
	}
	//car movement
}

int moana() {
	int opt; float pos[3];
	//variable and matrix decleration 

	head.write(90); delay(500);
	pos[1]= sonicBOOM(); delay(300);
	//recording foward distance

	head.write(165); delay(500);
	pos[0]= sonicBOOM(); delay(300);
	//recording left distance

	head.write(10); delay(500);
	pos[2]= sonicBOOM(); delay(300);	
	//recording right distance

	head.write(90);
	//setting head foward

	if(pos[1] > pos[0] & pos[1] > pos[2]) {opt= 1;}
	else if(pos[0] > pos[1] & pos [0] > pos[2]) {opt= 0;}
 	else if(pos[2] > pos[0] & pos[2] > pos[1]) {opt= 2;}
 	else {opt= 5;}
	//testing distance data

	return opt;
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

void mvFWD(int N0, int N1) {
	digitalWrite(6, HIGH); digitalWrite(7, LOW);
	digitalWrite(8, LOW); digitalWrite(9, HIGH);
	//setting motor rotations

	analogWrite(5, N0); analogWrite(11, N1);
	Serial.print("\n\nFOWARD"); delay(122);
	digitalWrite(5, LOW); digitalWrite(11, LOW);
	//motor pulse
}

void mvBWD(int N0, int N1) {
 	digitalWrite(6, LOW); digitalWrite(7, HIGH);
	digitalWrite(8, HIGH); digitalWrite(9, LOW);
	//setting motor rotations

	analogWrite(5, N0); analogWrite(11, N1);
	delay(400);
	digitalWrite(5, LOW); digitalWrite(11, LOW);
        //motor pulse        
}

void mvRGT(int N0, int N1) {
        digitalWrite(6, LOW); digitalWrite(7, HIGH);
        digitalWrite(8, LOW); digitalWrite(9, HIGH);
        //setting motor rotations

        analogWrite(5, N0); analogWrite(11, N1);
        Serial.println("\n\nRIGHT"); delay(626);
        digitalWrite(5, LOW); digitalWrite(11, LOW);
        //motor pulse

	delay(100);
}

void mvLFT(int N0, int N1) {
        digitalWrite(6, HIGH); digitalWrite(7, LOW);
        digitalWrite(8, HIGH); digitalWrite(9, LOW);
        //setting motor rotations

        analogWrite(5, N0); analogWrite(11, N1);
        Serial.println("\n\nLEFT"); delay(696);
        digitalWrite(5, LOW); digitalWrite(11, LOW);
        //motor pulse

	delay(100);
}
