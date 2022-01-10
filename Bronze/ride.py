"""
ID: chenant1
LANG: PYTHON3
TASK: ride
"""

with open("ride.in.txt") as fileIn, open("ride.out.txt", "w") as fileOut:
    
        myList = []

        for a in range(2):
            
            product = 1
            
            for x in fileIn.readline().strip():
                y = ord(x) - ord("A") + 1
                product *= y
         
            myList.append(product)
            
        message = "GO" if myList[0] % 47 == myList[1] % 47 else "STAY"

        fileOut.write(message + "\n")
