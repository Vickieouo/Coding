T = int(input())
for t in range(T):
    L = list(map(int, input().split())); n = len(L)
    L.reverse(); L[0] += 1
    for i, v in enumerate(L):
        if v >= 10:
            L[i] = 0
            if i+1 >= n:
                L.append(1)
            else:
                L[i+1] += 1
    print(f'Case #{t+1}: {list(reversed(L))}')