This node is  a simple node that will control 1 servo and 8 leds in JMRI and uses CMRI
pin 2 is not used in this sketch no reason it can not be used if required
1 bits have been setup for turnout feed
communication between jmri to the nano  use the bi-directional TTl to RS485 module.
The code uses address 3 in this sketch

In JMRI settings
Turnout 1 use address 3001

Led 1 use address 3002
------
Led 8 use address 3009

Turnout1 feed back use address 3001

Sensor1 use address 3002
------
Sensor5 use address 3007
