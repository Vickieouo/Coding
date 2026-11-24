T = int(input())
for t in range(T):
    s = input()
    ans = ''
    for i in s:
        if ((ord(i)>=ord('A') and ord(i)<=ord('Z')) or
            (ord(i)>=ord('a') and ord(i)<=ord('z'))):
            if i == 'Z':
                ans += 'A'
            elif i == 'z':
                ans += 'a'
            else:
                ans += chr(ord(i)+1)
        else:
            ans += i
    print(f'Case #{t+1}: {ans}')