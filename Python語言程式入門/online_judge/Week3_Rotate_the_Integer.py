T = int(input())
for t in range(T):
    b = int(input())
    print(f'Case #{t+1}: {((b << 1) | (b >> 7)) & 0b11111111}')