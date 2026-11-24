T = int(input())
for t in range(T):
    L = list(map(complex, input().split()))
    a = L[0].real; b = L[0].imag
    c = L[1].real; d = L[1].imag
    if(a>c and b>d):
        op = '>'
    elif(a<c and b<d):
        op = '<'
    elif(a==c and b==d):
        op = '=='
    elif((a==c and b>d) or (a>c and b==d)):
        op = '>='
    elif((a==c and b<d) or (a<c and b==d)):
        op = '<='
    else:
        op = '!='
    print(f'Case #{t+1}: {L[0]} {op} {L[1]}')