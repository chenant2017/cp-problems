"""
ID: chenant1
LANG: PYTHON3
TASK: gift1
"""

def divQR(dividend, divisor):
        return dividend//divisor, dividend % divisor

        
with open("gift1.in.txt") as fileIn, open("gift1.out.txt", "w") as fileOut:
    np = int(fileIn.readline())
    accounts = {}
    for i in range(np):
        name = fileIn.readline()
        accounts[name] = 0

    for j in range(np):
        name = fileIn.readline()
        amount, people = [int(num) for num in fileIn.readline().split()]
        if people != 0:
            q,r = divQR(amount, people)
            for i in range(people):
                accounts[fileIn.readline()] +=  q
            accounts[name] += r
        else:
            accounts[name] += amount

    



