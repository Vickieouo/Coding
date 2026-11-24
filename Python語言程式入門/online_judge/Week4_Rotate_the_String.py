T = int(input())
for t in range(T):
    s = input()
    r = int(input())
    if s == '':
        print(f'Case #{t+1}: ')
        continue
    r %= len(s)
    print(f'Case #{t+1}: {s[r:]+s[:r]}')