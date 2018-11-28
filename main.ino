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
	int N0= 100; int N1= 160; int opt;
	//variable decleration
	
	delay(250);

	mvFWD(N0); delay(100);
	opt= moana();
	mvFWD(N0); delay(100);
	
        Serial.print(pos[0]); Serial.print("\t");
        Serial.print(pos[1]); Serial.print("\t");
        Serial.print(pos[2]); Serial.print("\t");
	//troubleshooting data display

	switch (opt) {
		case 0:
			Serial.print("LEFT \n");
			mvLFT(N1);
		break;
		case 1:
			Serial.print("FOWARD \n");
    		break;
		case 2:
			Serial.print("RIGHT \n");
			mvRGT(N1);
    		break; 
		default:
			Serial.print("FUCK \n");
	}
	//car movement
}

int moana() {
	int opt; float pos[3];
	/variable and matrix decleration 

	head.write(90); delay(250);
	pos[1]= sonicBOOM(); delay(1000);
	//recording foward distance

	head.write(165); delay(250);
	pos[0]= sonicBOOM(); delay(1000);
	//recording left distance

	head.write(10); delay(250);
	pos[2]= sonicBOOM(); delay(1000);	
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

void mvFWD(int N) {
	digitalWrite(6, HIGH); digitalWrite(7, LOW);
	digitalWrite(8, LOW); digitalWrite(9, HIGH);
	//setting motor rotations

	analogWrite(5, N); analogWrite(11, N);
	delay(500);
	digitalWrite(5, LOW); digitalWrite(11, LOW);
	//motor pulse
}

void mvBWD(int N) {
        digitalWrite(6, LOW); digitalWrite(7, HIGH);
        digitalWrite(8, HIGH); digitalWrite(9, LOW);
        //setting motor rotations

        analogWrite(5, N); analogWrite(11, N);
        delay(500);
        digitalWrite(5, LOW); digitalWrite(11, LOW);
        //motor pulse        
}

void mvRGT(int N) {
        digitalWrite(6, LOW); digitalWrite(7, HIGH);
        digitalWrite(8, LOW); digitalWrite(9, HIGH);
        //setting motor rotations

        analogWrite(5, N); analogWrite(11, N);
        delay(500);
        digitalWrite(5, LOW); digitalWrite(11, LOW);
        //motor pulse

	delay(500);        
}

void mvLFT(int N) {
        digitalWrite(6, HIGH); digitalWrite(7, LOW);
        digitalWrite(8, HIGH); digitalWrite(9, LOW);
        //setting motor rotations

        analogWrite(5, N); analogWrite(11, N);
        delay(500);
        digitalWrite(5, LOW); digitalWrite(11, LOW);
        //motor pulse

	delay(100);        
}
