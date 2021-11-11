// Willaston Station minic panel led controller to display the turnout status for each route served by willaston
// also to controll 8 leds for signals and 10 route switches
// may also controlthe servo for T10
// pins 0 , 1 & 2 are used to control the crmi bus leaving 18 possible devices

//      MIMIC PANEL LEDS
// pin 3 T1 peel T1C
// pin 4 T1 peel T1T
// pin 5 T2 safe T2C
// pin 6 T5 dock city T5C
// pin 7 T5 dock city T5T
// pin 8 T6 closed T6C
// pin 9 T6 Thrown T6T
// pin 10 T7 safe T7C
// pin 11 T8 safe T8C
// pin 12 T9 closed T9C
// pin 13 T9 thrown T9T
// pin 14 T10 closed T10C
// pin 15 T10 thrown T10T
// pin 16 T11 closed T11C
// pin 17 T13 thrown T13T

//        willaston block detection for peel and dock city
// pin 18 peel p1 occupied PEEL1
// pin 19 peel p2 occupied PEEL2
// pin 20 dock city 1 occupied DC1
// pin 21 dock city 2 occupied DC2
// pin 22 upper level occupied UPPERL

//        willaton turnout T10 signals 8 output required
// pin 23 willaston p1 closed WP1C
// pin 24 willaston p1 thrown WP1T
// pin 25 willaston p2 closed WP2C
// pin 26 willaston p2 thrown WP2T
// pin 37 willaston p1 approach closed WAP1C
// pin 38 willaston pi approach thrown WAP1T
// pin 39 willaston p2 approach closed WAP2C
// pin 40 willaston p2 approach thrown WAP2C

#include <CMRI.h>

#define CMRI_ADDR 4
//willaston mimic panel leds
#define T1C 3       //jmri address 4001
#define T1T 4       //4002
#define T2C 5       //4003
#define T5C 6       //4004
#define T5T 7       //4005
#define T6C 8       //4006
#define T6T 9       //4007
#define T7C 10      //4008
#define T8C 11      //4009
#define T9C 12      //4010
#define T9T 13      //4011
#define T10C 14     //4012 
#define T10T 15     //4013  
#define T11C 16     //4014  
#define T13T 17     //4015

//      willaston mimic blocks for peel and dock city
#define PEEL1 18    //4016  
#define PEEL2 19    //4017   
#define DC1 20      //4018 
#define DC2 21      //4019
#define UPPERL 22   //4020 

//      willaston signals
#define WP1C 23    // 4021
#define WP1T 24    // 4022
#define WP2C 25    // 4023
#define WP2T 26    // 4024
#define WPA1C 27   // 4025
#define WPA1T 28   // 4026
#define WPA2C 29   // 4027
#define WPA2T 30   // 4028

#define IO34 31    // siwtch 1
#define IO35 32    // switch 2
#define IO32 33    // switch 3
#define IO33 34    // switch 4
#define IO31 35    // switch 5
//willaston siding routes
#define IO40 36    // siwtch 6
#define IO41 37    // switch 7
#define IO38 38    // switch 8
#define IO39 39    // switch 9
#define IO37 40    // switch 10

#define DE_PIN 2   // used for interupt

CMRI cmri(CMRI_ADDR, 64, 128); // defaults to a SMINI with address 0. SMINI = 24 inputs, 64 outputs

void setup() {

  //   mimic led setup
  pinMode (T1C, OUTPUT);
  pinMode (T1T, OUTPUT);
  pinMode (T2C, OUTPUT);
  pinMode (T5C, OUTPUT);
  pinMode (T5T, OUTPUT);
  pinMode (T6C, OUTPUT);
  pinMode (T6T, OUTPUT);
  pinMode (T7C, OUTPUT);
  pinMode (T8C, OUTPUT);
  pinMode (T9C, OUTPUT);
  pinMode (T9T, OUTPUT);
  pinMode (T10C, OUTPUT);
  pinMode (T10T, OUTPUT);
  pinMode (T11C, OUTPUT);
  pinMode (T13T, OUTPUT);

  //      block leds setup
  pinMode (PEEL1, OUTPUT);
  pinMode (PEEL2, OUTPUT);
  pinMode (DC1, OUTPUT);
  pinMode (DC2, OUTPUT);
  pinMode (UPPERL, OUTPUT);

  //        signal setup
  pinMode (WP1C, OUTPUT);
  pinMode (WP1T, OUTPUT);
  pinMode (WP2C, OUTPUT);
  pinMode (WP2T, OUTPUT);
  pinMode (WPA1C, OUTPUT);
  pinMode (WPA1T, OUTPUT);
  pinMode (WPA2C, OUTPUT);
  pinMode (WPA2T, OUTPUT);

  //willaston platform 1 routes
  pinMode (IO34, INPUT_PULLUP);// peel 1
  pinMode (IO35, INPUT_PULLUP);// peel 2
  pinMode (IO32, INPUT_PULLUP);// dock city 1
  pinMode (IO33, INPUT_PULLUP);// dock city 2
  pinMode (IO31, INPUT_PULLUP);// upper level
  //// willaston siding routes
  pinMode (IO40, INPUT_PULLUP);// peel 1
  pinMode (IO41, INPUT_PULLUP);// peel 2
  pinMode (IO38, INPUT_PULLUP);// dock city 1
  pinMode (IO39, INPUT_PULLUP);// dock city 2
  pinMode (IO37, INPUT_PULLUP);// upper level

  //willaston platform 1 routes
  pinMode (IO34, INPUT_PULLUP);// peel 1
  pinMode (IO35, INPUT_PULLUP);// peel 2
  pinMode (IO32, INPUT_PULLUP);// dock city 1
  pinMode (IO33, INPUT_PULLUP);// dock city 2
  pinMode (IO31, INPUT_PULLUP);// upper level
// willaston siding routes
  pinMode (IO40, INPUT_PULLUP);// peel 1
  pinMode (IO41, INPUT_PULLUP);// peel 2
  pinMode (IO38, INPUT_PULLUP);// dock city 1
  pinMode (IO39, INPUT_PULLUP);// dock city 2
  pinMode (IO37, INPUT_PULLUP);// upper level

  Serial.begin(9600);
}

void loop() {

  cmri.process();
  digitalWrite (T1C, cmri.get_bit(0));       //jmri address 4001
  digitalWrite (T1T, cmri.get_bit(1));       //jmri address 4002
  digitalWrite (T2C, cmri.get_bit(2));       //jmri address 4003
  digitalWrite (T5C, cmri.get_bit(3));       //jmri address 4004
  digitalWrite (T5T, cmri.get_bit(4));       //jmri address 4005
  digitalWrite (T6C, cmri.get_bit(5));       //jmri address 4006
  digitalWrite (T6T, cmri.get_bit(6));       //jmri address 4007
  digitalWrite (T7C, cmri.get_bit(7));       //jmri address 4008
  digitalWrite (T8C, cmri.get_bit(8));       //jmri address 4009
  digitalWrite (T9C, cmri.get_bit(9));       //jmri address 4010
  digitalWrite (T9T, cmri.get_bit(10));      //jmri address 4011
  digitalWrite (T10C, cmri.get_bit(11));     //jmri address 4012
  digitalWrite (T10T, cmri.get_bit(12));     //jmri address 4013
  digitalWrite (T11C, cmri.get_bit(13));     //jmri address 4014
  digitalWrite (T13T, cmri.get_bit(14));     //jmri address 4015

  // block detection leds
  digitalWrite (PEEL1, cmri.get_bit(15));    //jmri address 4016
  digitalWrite (PEEL2, cmri.get_bit(16));    //jmri address 4017
  digitalWrite (DC1, cmri.get_bit(17));      //jmri address 4018
  digitalWrite (DC2, cmri.get_bit(18));      //jmri address 4019
  digitalWrite (UPPERL, cmri.get_bit(19));   //jmri address 4020

  // signal leds

  digitalWrite (WP1C, cmri.get_bit(20));      //jmri address 4021
  digitalWrite (WP1T, cmri.get_bit(21));      //jmri address 4022
  digitalWrite (WP2C, cmri.get_bit(22));      //jmri address 4023
  digitalWrite (WP2T, cmri.get_bit(23));      //jmri address 4024
  digitalWrite (WPA1C, cmri.get_bit(24));      //jmri address 4025
  digitalWrite (WPA1T, cmri.get_bit(25));      //jmri address 4026
  digitalWrite (WPA2C, cmri.get_bit(26));      //jmri address 4027
  digitalWrite (WPA2T, cmri.get_bit(27));      //jmri address 4028

  //willaston 1
  cmri.set_bit(0, !digitalRead(31)); //jmri 4001
  cmri.set_bit(1, !digitalRead(32)); //jmri 4002
  cmri.set_bit(2, !digitalRead(33)); //jmri 4003
  cmri.set_bit(3, !digitalRead(34)); //jmri 4004
  cmri.set_bit(4, !digitalRead(35)); //jmri 4005
  //willaston siding
  cmri.set_bit(5, !digitalRead(36)); //jmri 4006
  cmri.set_bit(6, !digitalRead(37)); //jmri 4007
  cmri.set_bit(7, !digitalRead(38)); //jmri 4008
  cmri.set_bit(8, !digitalRead(39)); //jmri 4009
  cmri.set_bit(9, !digitalRead(40)); //jmri 4010

}
