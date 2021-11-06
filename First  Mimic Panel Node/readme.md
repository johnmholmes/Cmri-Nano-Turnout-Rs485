This Node is my first attempt at a mimic panel using JMRI and CMRI with an Arduino Nano

It is used for a dock zone on the layout which has 2 platforms and a dock siding it uses a crossover 
and the route into the zone comes from the main part of the layout via a 3rd turnout which is turnout 2 in JMRI.

The mimic panel has 5 push buttons which are used by Jmri to set roots that have been setup within the jmri root table.

the 2 platform lines have been coloured red and blue and they have a few optional roots to solect.

Platform 1 has 3 possible roots in this case (Peel platform 1, Peel platform 2, and dock siding).

Platform 2 only has 2 roots options (Peel platform 1, and Peel platform 2),

The root tables in Jmri controls turnouts 1, which is the root into peel platforms and turnout 2 which in this turnout 2 needs to be thrown, turnouts 3 & 4
depends which platform you are coming from.

The mimic panel has leds to show the state of the turnouts, turnout 2 only shows 1 led which lights when turnout to is thrown.

The mimic panel also has 3 red leds which are used to show if Peel platform 1 and 2 are occupied and 1 red led show if the dock siding is occupied.
The dock siding led is a bit pointless really as the mimic panel is set in front of the dock Zone.
