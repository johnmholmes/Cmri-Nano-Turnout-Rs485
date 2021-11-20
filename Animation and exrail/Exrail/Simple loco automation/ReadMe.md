Steps to run a locomotive address 4 between 2 sensors on the track forward sensor at pin 42 and reverse sensor at pi 41
We also have a switch on pin 22 to start this to only run 1 time

1. upload the newversion of CommandStation_ex to your arduino and restart it

2. Check out the myAutomation.h file you will also see the flicker led included the code below just controls the loco

EXRAIL

START(20)

SENDLOCO(4,20)

DONE

SEQUENCE(20)

AT(22)  // if you remove this line the code will loop from startup until arduino is switched off

DELAYRANDOM(1000,20000)

FWD(60)

AT(42)

STOP

DELAY(15000)

REV(50)

AT(41)

STOP

FOLLOW(20)


ENDEXRAIL

3. once the file has been created up load the dcc++ex new version of DCC++Ex to your base station and the flickering led will start on start up of the base station

4. this runs in the back ground so will not affect the dcc signals going to your track.

5. more information on exrail is on the dcc++ex website


6. check out the automation of the train which can easly be programmed for exrail.

7. this was shown to meby one of the developers so i can not explain all the details of how its being done, but i am sure the team will help you as they did me on the Dcc++ex discord.

Have fun with it.


