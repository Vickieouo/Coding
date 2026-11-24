class Player:
    def __init__(self):
        self.total = 0
        self.poly = 0

    def add(self, val):
        self.total += pow(val, self.poly)

    def getval(self):
        return self.total

    def getpoly(self):
        return self.poly


n = int(input())
p1 = Player()
p2 = Player()

for i in range(n):
    player, value = input().split()
    if int(player) == 1:
        p1.add(int(value))
        p1.poly += 1
    else:
        p2.add(int(value))
        p2.poly += 1

# choose the winner
if p1.getval() > p2.getval():
    winner = "1"
elif p2.getval() > p1.getval():
    winner = "2"
else:
    if p1.getpoly() > p2.getpoly():
        winner = "1"
    elif p2.getpoly() > p1.getpoly():
        winner = "2"
    else:
        winner = "DRAW"

print(winner)