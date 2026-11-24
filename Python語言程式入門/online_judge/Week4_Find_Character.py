T = int(input())
for t in range(T):
    s = input().split()
    print(f'Case #{t+1}: {s[0].find(s[1])}')