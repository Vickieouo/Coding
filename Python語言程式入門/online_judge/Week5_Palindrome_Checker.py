T = int(input())
for t in range(T):
    L = input().split()
    if (L == list(reversed(L))):
        print(f'Case #{t+1}: Yes')
    else:
        print(f'Case #{t+1}: No')