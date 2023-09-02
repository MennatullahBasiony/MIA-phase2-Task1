from Villian import Villain
from Gadgets import Gadgets

class Gru(Villain, Gadgets):

    gadgets = [Gadgets("weapon", "Freeze Gun", 50, float('inf'), 11, 0),
               Gadgets("weapon", "Electric Prod", 88, 5, 18, 0),
               Gadgets("weapon", "Mega Magnet", 92, 3, 10, 0),
               Gadgets("weapon", "Kalman Missile", 120, 1, 20, 0), 
               Gadgets("shield", "Energy Projected BarrierGun", 20, float('inf'), 0, 0.4),
               Gadgets("shield", "Selective Permeability", 50, 2, 0, 0.9),
               Gadgets("Nothing", "Nothing", 0, 0, 0, 0)]
  