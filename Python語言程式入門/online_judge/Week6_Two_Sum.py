T = int(input())
for t in range(T):
    n = int(input())
    L = list(map(int, input().split()))
    for i, a in enumerate(L):
        for j, b in enumerate(L[i+1:]):
            if a+b == n:
                print(f'Case #{t+1}: [{i}, {j+i+1}]')