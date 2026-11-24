T = int(input())
for t in range(T):
    n = int(input())
    L = []
    while n > 0:
        n -= 1
        r = n % 26
        L.append(chr(ord('A') + r))
        n //= 26
    print(f'Case #{t+1}: {"".join(reversed(L))}')