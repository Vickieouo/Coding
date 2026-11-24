s = input()
L = s.split(); L[0]=float(L[0]); L[1]=float(L[1]); L[2]=int(L[2])
product = round(L[0]*L[1], L[2])
print(f'{L[0]} * {L[1]} equals to {product}')
