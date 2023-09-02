from Gru import Gru
from Vector import Vector

# Method to display gadgets specified for each player
def displayGadgets(plNum):
    while 1:
        iter = 1

        #case player1
        if(plNum == 1):
            for i in player1.gadgets:
                if i.type == "weapon":
                    print(f"{iter} {i.type}: {i.name}, Energy: {i.energy}, Count: {i.resources}, Damage: {i.damage}")
                else:
                    print(f"{iter} {i.type}: {i.name}, Energy: {i.energy}, Count: {i.resources}, Save: {i.save}")

                iter += 1
            
            choice = int(input("your choice: ")) - 1
            # check for valid choice
            if choice < len(player1.gadgets):
                return choice
            else:
                print("Choice out of Boundries")

        #case player2
        elif(plNum == 2):
            for i in player2.gadgets:
                if i.type == "weapon":
                    print(f"{i.type} {iter}: {i.name}, Energy: {i.energy}, Count: {i.resources}, Damage: {i.damage}")
                else:
                    print(f"{i.type} {iter}: {i.name} ,Energy: {i.energy}, Count: {i.resources}, Save: {i.save}")

                iter += 1

            choice = int(input("your choice: ")) - 1
            #check for valid choice
            if choice < len(player2.gadgets):
                return choice
            else:
                print("Choice out of Boundries\n")


# Method to perform damage done after each round
def damage(g1, g2):

    #initialize needed variables
    energyLoss1 = 0
    energyLoss2 = 0

    # If player1 is using a freezing gun don't update his status
    if player1.gadgets[g1].name != "Freeze Gun":

        #Update health of player1
        player1.health -= (player2.gadgets[g2].damage - (player2.gadgets[g2].damage * player1.gadgets[g1].save))

        # Updata energy of player only if opponent is using a weapon
        if player2.gadgets[g2].type == "weapon":
            # Calculate loss in energy between both gadgets
            energyLoss1 = abs(player1.gadgets[g1].energy - player2.gadgets[g2].energy)

            player1.energy -= energyLoss1

    # If player2 is using a freezing gun don't update his status
    if player2.gadgets[g2].name != "Freeze Gun":

        #Update health of player2
        player2.health -= (player1.gadgets[g1].damage - (player1.gadgets[g1].damage * player2.gadgets[g2].save))

        # Updata energy of player only if opponent is using a weapon
        if player1.gadgets[g1].type == "weapon":
            # Calculate loss in energy between both gadgets
            energyLoss2 = abs(player2.gadgets[g2].energy - player1.gadgets[g1].energy)

            player2.energy -= energyLoss2

    
    #Decrease resources only when used gadget energy reaches 0 else update gadget's energy
    if player1.gadgets[g1].energy - energyLoss1 <= 0:
        player1.gadgets[g1].resources -= 1
    else:
        player1.gadgets[g1].energy -= energyLoss1

    if player2.gadgets[g2].energy - energyLoss2 <= 0:
        player2.gadgets[g2].resources -= 1
    else:
        player2.gadgets[g2].energy -= energyLoss2


    # If resources of this gadget are all used remove it from list
    if player1.gadgets[g1].resources == 0:
        del player1.gadgets[g1]

    if player2.gadgets[g2].resources == 0:
        del player2.gadgets[g2]



# Game starts
print("Welcom To The Battle!")

# Choosing playing character
choice1 = int(input("player1 you want to play as Gru(1) or Vector(2): "))
choice2 = int(input("player2 you want to play as Gru(1) or Vector(2): "))

# checking for valid characters choice and creating them
while 1:

    if choice1 == 1:
        player1 = Gru()
    elif choice1 == 2:
        player1 = Vector()
    else:
        print("Invalid Input please type 1 for Gru or 2 for Vector")
        choice1 = int(input("player1 you want to play as Gru(1) or Vector(2): "))
        continue

    if choice2 == 1:
        player2 = Gru()
    elif choice2 == 2:
        player2 = Vector()
    else:
        print("Invalid Input please type 1 for Gru or 2 for Vector")
        choice2 = int(input("player2 you want to play as Gru(1) or Vector(2): "))
        continue

    break

# Variable to trace round number
round = 1

# Keep playing unless health or energy of either players is 0
while(player1.health > 0 and player2.health > 0 and player1.energy > 0 and player2.energy > 0):
    print("\nround: ", round)
    print(f"player1  health: {player1.health} Energy: {player1.energy}")
    print(f"player2  health: {player2.health} Energy: {player2.energy}")

    if round == 1:
        print("\nplayer1 choose your gadget: ")
        gadget1 = displayGadgets(1)

        if player1.gadgets[gadget1].name != "Freeze Gun":
            print("\nplayer2 choose your gadget: ")
            gadget2 = displayGadgets(2)

        else:
            print("\nplayer2 your frozen you can't make a move")
            gadget2 = -1

    else: #check for freezing gun before asking any player

        if player2.gadgets[gadget2].name != "Freeze Gun":

            #If choosen gadget still has energy ask if player1 want to change it
            if player1.gadgets[gadget1].energy > 0:
                same = input("\nPlayer1 do you want to change your gadget(y/n)? ")
                if same == "y":
                    print("\nplayer1 choose your gadget: ")
                    gadget1 = displayGadgets(1)

                elif same != "n":
                    print("Invalid input")
                    continue

            #If choosen gadget has no energy remained display list of gadgets
            else:
                print("\nplayer1 choose your gadget: ")
                gadget1 = displayGadgets(1)

            print(f"player1 is using a {player1.gadgets[gadget1].name}")

        else :
            print("\nplayer1 you can't make a move your frozen")
            gadget1 = -1

        if player1.gadgets[gadget1].name != "Freeze Gun":

            #If choosen gadget still has energy ask if player2 want to change it
            if player2.gadgets[gadget2].energy > 0:
                same = input("\nPlayer2 do you want to change your gadget(y/n)? ")
                if same == "y":
                    print("\nplayer2 choose your gadget: ")
                    gadget2 = displayGadgets(2)
                
                elif same != "n":
                    print("Invalid input")
                    continue

            #If choosen gadget has no energy remained display list of gadgets
            else:
                print("\nplayer2 choose your gadget: ")
                gadget2 = displayGadgets(2)
            
            print(f"player2 is using a {player2.gadgets[gadget2].name}")

        else :
            print("\nplayer2 you can't make a move your frozen")
            gadget2 = -1

    #perform damage for this round
    damage(gadget1, gadget2)

    round += 1


#Display results of the Battle
if player2.health > 0 and player2.energy > 0:
    print("Well Done Player2 You Won the Battle")

elif player1.health > 0 and player1.energy > 0:
    print("Well Done Player1 You Won the Battle")

else:
    print("It's a Tie")


