import math

s = input()
L = s.split(); L[0]=int(L[0]); L[1]=int(L[1])
Prime = []
if (L[0] == 1): L[0]+=1
for i in range(L[0],L[1]+1):
   for j in range(2,int(math.sqrt(i))+1):
      if(i%j == 0): break
   else: Prime.append(i)
Prime.reverse()
print(Prime)
