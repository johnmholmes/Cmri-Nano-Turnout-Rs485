//Docks Mimic panel programme address 5
// pins 0 , 1  are used to control the crmi bus leaving 18 possible devices
//dock platform 1 has 2 routes avaiable
//dock platform 2 has 3 routes avaiable
//5 switches required 7 leds for turnouts 3 leds for block detection
//turnouts leds required t1 2 leds, t2 1 led, t3 2 leds, t4 2 leds 
//block detection leds required 3 red

//      MIMIC PANEL LEDS
// pin 3 //  T1C peel platform 1  5001
// pin 4 //  T1T peel platform 2  5002
// pin 5 //  T2T Dock approach    5003
// pin 6 //  T3C dock platform 1  5004
// pin 7 //  T3T dock platform 2  5005
// pin 8 //  T4C dock siding      5006
// pin 9 //  DS1 dock siding occuppied 5007
// pin 10 // PL1 peel platform 1 occuppied 5008
// pin 11 // PL2 peel platform 2 occuppied 5509
// pin 12 // D2DS dock platform 2 to siding         5005
// pin 13 // not used
// pin A0 // D1P1 dock platform 1 to peel 1 switch  5001
// pin A1 // D1P2 dock platform 1 to peel 2         5002
// pin A2 // D2P1 dock platform 2 to peel 1         5003
// pin A3 // D2P2 dock platform 2 to peel 2         5004

#include <CMRI.h>

#define CMRI_ADDR 5
//Docks mimic panel leds
#define T1C 3       //jmri address 5001 led 6 leds for turn outs
#define T1T 4       //5002
#define T2T 5       //5003
#define T3C 6       //5004
#define T3T 7       //5005
#define T4C 8       //5006
#define DS1 9       //5007 block occuppied led 3 leds for block detection
#define PL1 10      //5008
#define PL2 11      //5009
// pin 12 and 13 not used
#define D1P1 A0     //5001 
#define D1P2 A1     //5002  
#define D2P1 A2     //5003  
#define D2P2 A3     //5004
#define D2DS 12     //5005  

CMRI cmri(CMRI_ADDR, 24, 48); // defaults to a SMINI with address 0. SMINI = 24 inputs, 48 outputs
////////////////////////////////////////////////////////////////////////////////////////////to be changed/////////////////////////////////
void setup() {

  //   mimic led setup
  pinMode (T1C, OUTPUT);  //5001
  pinMode (T1T, OUTPUT);  //5002
  pinMode (T2T, OUTPUT);  //5003
  pinMode (T3C, OUTPUT);  //5004
  pinMode (T3T, OUTPUT);  //5005
  pinMode (T4C, OUTPUT);  //5006
  pinMode (DS1, OUTPUT);  //5007
  pinMode (PL1, OUTPUT);  //5008
  pinMode (PL2, OUTPUT);  //5009

  //willaston platform 1 routes
  pinMode (D1P1, INPUT_PULLUP);// peel 1  5001
  pinMode (D1P2, INPUT_PULLUP);// peel 2  5002
  pinMode (D2P1, INPUT_PULLUP);// peel 1  5003
  pinMode (D2P2, INPUT_PULLUP);// peel 2  5004
  pinMode (D2DS, INPUT_PULLUP);// peel 2  5005

  Serial.begin(9600);
}

void loop() {

  cmri.process();
  // set the leds from jmri
  digitalWrite (T1C, cmri.get_bit(0));       //jmri address 5001
  digitalWrite (T1T, cmri.get_bit(1));       //jmri address 5002
  digitalWrite (T2T, cmri.get_bit(2));       //jmri address 5003
  digitalWrite (T3C, cmri.get_bit(3));       //jmri address 5004
  digitalWrite (T3T, cmri.get_bit(4));       //jmri address 5005
  digitalWrite (T4C, cmri.get_bit(5));       //jmri address 5006
  digitalWrite (DS1, cmri.get_bit(6));       //jmri address 5007
  digitalWrite (PL1, cmri.get_bit(7));       //jmri address 5008
  digitalWrite (PL2, cmri.get_bit(8));       //jmri address 5009


  //read the 5 switchs and send to jmri
  cmri.set_bit(0, !digitalRead(A0)); //jmri 5001
  cmri.set_bit(1, !digitalRead(A1)); //jmri 5002
  cmri.set_bit(2, !digitalRead(A2)); //jmri 5003
  cmri.set_bit(3, !digitalRead(A3)); //jmri 5004
  cmri.set_bit(4, !digitalRead(12)); //jmri 5005

}
