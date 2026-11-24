T = int(input())
for t in range(T):
    L = input()[::-1]; num = 0
    for i, v in enumerate(L):
        num += pow(26, i)*(ord(v)-ord('A')+1)
    print(f'Case #{t+1}: {num}')