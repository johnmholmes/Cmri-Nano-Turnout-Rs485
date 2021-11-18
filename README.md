# A group of various codes for use with a  model layout that uses Jmri and Cmri and Dcc++Ex
When i first created this repository it was going to be for 1 peice of code for use on my layout 
and for me to learn how to use github.

But i have decided that is a good place to keep all the codes i use on the layout which is still
under construction, its about 3/4 complete and my ideas have changed quite a bit since i started it.

Atfer watching Rob's Youtube channel "little wicket" it got me started into a hobby i had not 
done for about 27 years.

I had been learning Python for another hobby project which was a Marine aquarium controller, which once
was completed i had a few spare arduino's laying around the house which i had been messing about with as well.

After building the original version of Dcc++ i soon got hooked on expanding the size of the layout. As i had found
adapting the many variations of code around the internet.

After moving away from my original plan of keeping the electronics all in one place, which i wish i had not already built 
a large section of it. The 24 foot by 20 foot layout in the loft of the house. I decided to start building smaller stand 
alone nodes and putting them closer to the turnouts and signals, This through up a issue after following the Rs485 video 
that Rob had done quite a few of the cheap ebay units start to be unreliable. This set me down the road of looking for a 
different Rs485 module which i did find on the internet but it came with very little information how to use it. 
After some experementing i found that i did not need to use the Auto485 Library as per Robs video and also i only
needed 2 pins on the arduino instead of 3

So far i have now added 2 versions of turnout and signal and infrared sensors code both based on Nano's

Also i have added 2 versions of mimic panels 1 nano and 1 mega based

Also i have added some python scripts for use in jmri as shown by Rob but this code will run more locomotives
this shows how to set turnouts via routes and waits for the other trains to get to a certain point on the layou before
others can proceed.

Hopefully you can adapt the codes for use on your own layouts


