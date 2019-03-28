/*
      RoboCore - Motor Driver 2x2A example
                    (01/07/2015)

  Written by FranÃ§ois.
  
  Example of how to use the Motor Driver 2x2A.
  Open a Serial Monitor and enter the comands:
    - u : for PWM 0 to 150
    - d : for PWM 150 to 0
    - o : for ON
    - f : for OFF
    - 1 : for Direction 1
    - 2 : for Direction 2

*/
//Include the SoftwareSerial library
#include "SoftwareSerial.h"

//Create a new software  serial
SoftwareSerial bluetooth(2, 3); //TX, RX (Bluetooth)
  
int incomingByte;      // a variable to read incoming serial data into

const int motorA = 5;
const int motorB = 6;
const int dirA = 7;
const int dirB = 8;
const int led1 = 13;
const int led2 = 12;

byte b;

// ------------------------------------------------

void setup(){

  //Initialize the software serial
  bluetooth.begin(38400);
  
  bluetooth.println("Start");
  
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
}

// ------------------------------------------------

void loop(){
  // see if there's incoming serial data:
  if (bluetooth.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = bluetooth.read();
    
    b = incomingByte;
    
    switch(b){
      // PWM Up
      case 'u':
        for(int i=0 ; i <= 150 ; i++){
          analogWrite(motorA, i);
          analogWrite(motorB, i);
          delay(20);
        }
        bluetooth.println("\tok");
        break;
      
      // PWM Down
      case 'd':
        for(int i=150 ; i >= 0 ; i--){
          analogWrite(motorA, i);
          analogWrite(motorB, i);
          delay(20);
        }
        bluetooth.println("\tok");
        break;
      
      
      // On
      case 'o':
        digitalWrite(motorA, HIGH);
        digitalWrite(motorB, HIGH);
        bluetooth.println("ON");
        break;
      
      // Off
      case 'f':
        digitalWrite(motorA, LOW);
        digitalWrite(motorB, LOW);
        bluetooth.println("OFF");
        break;
      
      
      // Dir-1
      case '1':
        digitalWrite(dirA, HIGH);
        digitalWrite(dirB, HIGH);
        bluetooth.println("\tdir-1");
        break;
      
      // Dir-2
      case '2':
        digitalWrite(dirA, LOW);
        digitalWrite(dirB, LOW);
        bluetooth.println("\tdir-2");
        break;
      
      
      // PWM Max
      case '>':
          analogWrite(motorA, 240);
          analogWrite(motorB, 240);
        bluetooth.println("\tMax");
        break;
      
      // PWM Min
      case '<':
          analogWrite(motorA, 20);
          analogWrite(motorB, 20);
        bluetooth.println("\tMin");
        break;
      
      // Esquerda
      case 'E':
          analogWrite(motorA, 150);
          analogWrite(motorB, 80);
        bluetooth.println("\tok");
        break;

      // Direita
      case 'D':
          analogWrite(motorA, 80);
          analogWrite(motorB, 150);
        bluetooth.println("\tok");
        break; 
     
      // Frente
      case 'F':
          analogWrite(motorA, 150);
          analogWrite(motorB, 150);
        bluetooth.println("\tok");
        break;
      
      // Liga Leds
      case 'h':
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
        bluetooth.println("\tok");
        break;
     
      // Desliga Leds
        case 'l':
          digitalWrite(led1, LOW);
          digitalWrite(led2, LOW);
        bluetooth.println("\tok");
        break;                          
                
      default:
        bluetooth.println("nothing");
        break;
    }
  }
  
}

// ------------------------------------------------









