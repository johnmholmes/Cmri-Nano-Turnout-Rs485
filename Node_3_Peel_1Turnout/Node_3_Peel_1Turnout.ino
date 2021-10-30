/*pins 0 - 1 are usedfor Rx and Tx no trigger pin required due to using
  TTL to RS485 Module Serial Port MCU Automatic Flow Control Module.
  i do not use pin 2 as it may be needed with 3 wire RS485 Units
  simple servo cmri node which moves 1 servo and the sends back a bit back to jmri to indicate
  the servo has been moved
  also will control 8 off signal leds
  it will also read 5 sensors/switchs
*/
#include <CMRI.h>
#include <Servo.h>

// ddefine node address each node needs its own address
#define CMRI_ADDR 3

// define turnout required positions each turnout will need calibrating
#define turnout1ClosedPosition 70
#define turnout1ThrownPosition 108

// define signal leds turnout 1
#define throughApproachGreenLed 4 //jmri 3002
#define throughApproachRedLed 5
#define divergingApproachGreenLed 6
#define divergingApproachRedLed 7
#define throughGreenLed 8
#define throughRedLed 9
#define divergingGreenLed 10
#define divergingRedLed 11

//define infrared detection peel
#define Sensor1 A0  //jmri 3002
#define Sensor2 A1
#define Sensor3 A2
#define Sensor4 A3
#define Sensor5 A4

//setup themove speed of servo
#define turnoutMoveSpeed 20   // [ms] lower number is faster

int t1state = 0; //0 = closed 1 = thrown
int turnout1 = 0;
unsigned long turnoutMoveDelay;

CMRI cmri(CMRI_ADDR, 24, 48); // defaults to a SMINI with address 0. SMINI = 24 inputs, 48 outputs
Servo turnOut1;

byte turnout1Position = turnout1ClosedPosition;
byte turnout1Target   = turnout1ClosedPosition;


void setup() {
  delay(2000);
  //setup output pins
  pinMode(throughApproachGreenLed, OUTPUT);
  pinMode(throughApproachRedLed, OUTPUT);
  pinMode(divergingApproachGreenLed, OUTPUT);
  pinMode(divergingApproachRedLed, OUTPUT);
  pinMode(throughGreenLed, OUTPUT);
  pinMode(throughRedLed, OUTPUT);
  pinMode(divergingGreenLed, OUTPUT);
  pinMode(divergingRedLed, OUTPUT);

  //setup input pins
  pinMode(Sensor1, INPUT_PULLUP);
  pinMode(Sensor2, INPUT_PULLUP);
  pinMode(Sensor3, INPUT_PULLUP);
  pinMode(Sensor4, INPUT_PULLUP);
  pinMode(Sensor5, INPUT_PULLUP);

  digitalWrite(throughApproachGreenLed, LOW);  // light led 1 on start up  to show its working
  delay(2000);
  digitalWrite(throughApproachGreenLed, HIGH);
  turnOut1.attach(3);
  turnOut1.write(turnout1ClosedPosition);


  Serial.begin(9600);
}

void loop() {
  cmri.process();
  turnout1 = (cmri.get_bit(0)); //turnout 3001 jmri address

  if (turnout1 == 1 && t1state == 0) {
    turnout1Target = turnout1ThrownPosition;   //  changed to set the target
    t1state = 1;
    cmri.set_bit(0, HIGH); //3001 jmri address output
  }
  if (turnout1 == 0 && t1state == 1) {
    turnout1Target = turnout1ClosedPosition;    //  changed to set the target
    t1state = 0;
    cmri.set_bit(0, LOW);
  }

  // read the cmri bit and switch on led ! used as i am using + commom leds tmc signals
  digitalWrite (throughApproachGreenLed, !cmri.get_bit(1)); //jmri 3002 
  digitalWrite (throughApproachRedLed, !cmri.get_bit(2)); 
  digitalWrite (divergingApproachGreenLed, !cmri.get_bit(3)); 
  digitalWrite (divergingApproachRedLed, !cmri.get_bit(4)); 
  digitalWrite (throughGreenLed, !cmri.get_bit(5)); //SH3
  digitalWrite (throughRedLed, !cmri.get_bit(6)); //SH3
  digitalWrite (divergingGreenLed, !cmri.get_bit(7)); //SH4
  digitalWrite (divergingRedLed, !cmri.get_bit(8)); //SH4 jmri 3009

  // get senors status and send to jmri
  cmri.set_bit(1, !digitalRead(A0)); //jmri 3002
  cmri.set_bit(2, !digitalRead(A1));
  cmri.set_bit(3, !digitalRead(A2));
  cmri.set_bit(4, !digitalRead(A3));
  cmri.set_bit(5, !digitalRead(A4));

  if (turnout1Position != turnout1Target) {
    if (millis() > turnoutMoveDelay) {
      turnoutMoveDelay = millis() + turnoutMoveSpeed;
      if (turnout1Position < turnout1Target) turnout1Position++;
      if (turnout1Position > turnout1Target) turnout1Position--;
      turnOut1.write(turnout1Position);
    }
  } // end of setting turnout1
}
