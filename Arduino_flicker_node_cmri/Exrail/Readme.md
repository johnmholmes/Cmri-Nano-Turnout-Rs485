Steps to making the led flicker on pin 17 on a arduino mega with the latest version of DCC++Ex

1. You need to add a file called myAutomation.h

2. add the following lines of code.

EXRAIL
START(917)
DONE

SEQUENCE(917)
DELAYRANDOM(10,400) SET(17)
DELAYRANDOM(10,400) RESET(17)
FOLLOW(917)


ENDEXRAIL

3. once the file has been created up load the dcc++ex new version of DCC++Ex to your base station and the flickering led will start on start up of the base station

4. this runs in the back ground so will not affect the dcc signals going to your track.

5. more information on exrail is on the dcc++ex website


6. check out the automation of the train which can easly be programmed for exrail.

7. this was shown to meby one of the developers so i can not explain all the details of how its being done, but i am sure the team will help you as they did me on the Dcc++ex discord.

Have fun with it.


