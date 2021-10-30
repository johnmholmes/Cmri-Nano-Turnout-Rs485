# Cmri-Nano-Turnout-Rs485 to TTL Bilateral Module UART Port Serial Converter Module 3.3/5V Power Signal
A simple Cmri node using arduino Nano and a TTL to RS485 RS485 to TTL Bilateral Module UART Port Serial Converter Module 3.3/5V Power Signal to control 1 turnout and 4 tmc 2 aspect signals.

This will require only 2 Libraries to be used "CMRI.h" + "Servo.h" CMRI.h will need to be downloaded from github and added to your 
Arduino libraries so you can use it.

The RS485 unit will be attched to Rx and Tx pins on the Arduino Nano pins 0 and 1.

The servo will be attched to pin 3 i have left pin 2 empty in this case as previously was used for the 3 wire Rs485 units.

The 8 leds will be atached to pins 4 to 11.

And i have 5 infra red modules atached  to pins A0 to A4.

In this exsample the node address will be 3 but can be  changed to any value not being used.

The Arduino Nano is simulating a Cmri SMINI node which can have 24 imputs and 48 outputs for Jmri use.

The TMC 2 asspect signals use a 5v commom positive to get the power to the leds and that goes onto the 5volt rail 4 off on the shield.
The remaining 8 wires go to the Arduino Nano pins 4 to 11.

In Jmri you will need 1 turnout to be created to use 1 bit steady state with address of 3001 in this case.
And also 4 Signal Heads to be created Signal head 1 will use create new and green with address 3002 and create new for red with address 3003.
This will need to be done for the remaining 3 signal heads.

The 5 infra red sensors will be attched to pins A0 to A4 and grounded to the gnd rail on the shield. these will uses address 3002 to 3006.

There is a bit message returned to jmri with address 3001 which i use for feedback on the turnout but not a micro switch in this case. this only uses the arduino code to create the message.


Hopefully it can help you to learn how to do it
