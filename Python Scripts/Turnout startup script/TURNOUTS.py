import jmri
class setStartup(jmri.jmrit.automat.AbstractAutomaton) :
   def init(self):
     return
   def handle(self):
     self.waitMsec(500)         # time is in milliseconds
     turnouts.provideTurnout("CT1001").setState(CLOSED)
     self.waitMsec(500)
     turnouts.provideTurnout("CT1002").setState(CLOSED)
     self.waitMsec(500)
     turnouts.provideTurnout("CT1003").setState(CLOSED)
     self.waitMsec(500)
     turnouts.provideTurnout("CT1004").setState(CLOSED)
     self.waitMsec(500)
     turnouts.provideTurnout("CT1005").setState(CLOSED)
     self.waitMsec(500)
     turnouts.provideTurnout("CT1006").setState(CLOSED)
     self.waitMsec(500)
     turnouts.provideTurnout("CT1007").setState(CLOSED)
     self.waitMsec(500)
     turnouts.provideTurnout("CT1008").setState(CLOSED)
     self.waitMsec(500)
     turnouts.provideTurnout("CT1009").setState(CLOSED)
     self.waitMsec(500)
     turnouts.provideTurnout("CT1010").setState(CLOSED)
     self.waitMsec(500)
     turnouts.provideTurnout("CT1011").setState(CLOSED)
     self.waitMsec(500)
     turnouts.provideTurnout("CT1012").setState(CLOSED)
     self.waitMsec(500)
     turnouts.provideTurnout("CT1013").setState(CLOSED)
     self.waitMsec(500)


     return False              # all done, don't repeat again
setStartup().start()          # create one of these, and start it running 
