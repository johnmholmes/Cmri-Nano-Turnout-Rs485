This scritp i use to run 3 trains in a sequence of automation, it is inportant to ensure that the trains are in there correct starting location.

as you will see it use the sensors to detect where each train has reached. before the train starts off it sets the route it needs.

The next train can not move until the first train has reached a certain point and the 3rd train waits until another train reaches a certain point.

This works on my layout and is only a guild to show you how it can be done.

The routes table in the folder shows all the route i have setup in jmri.

The routes are trigger using nternal sensors within jmri and script sets them to active when the train is being setup ready to move. at certain 
points within the code the sensors get set to inactive.
