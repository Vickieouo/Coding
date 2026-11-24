T = int(input())
for t in range(T):
    L = input().split(); n = len(L)
    L = set(L); type = len(L)
    print(f'Case #{t+1}: {int(min(n/2, type))}')