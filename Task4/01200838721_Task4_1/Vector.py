from Gadgets import Gadgets
from Villian import Villain

class Vector(Villain, Gadgets):

    gadgets = [Gadgets("weapon", "Laser Blasters", 40, float('inf'), 8, 0),
               Gadgets("weapon", "Plasma", 56, 8, 13, 0),
               Gadgets("weapon", "Sonic Resonance Connon", 100, 3, 22, 0),
               Gadgets("shield", "Energy Net Trap", 15, float('inf'), 0, 0.32),
               Gadgets("shield", "Quntum Deflector", 40, 3, 0, 0.8),
               Gadgets("Nothing", "Nothing", 0, 0, 0, 0)]
    
