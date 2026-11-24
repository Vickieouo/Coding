class csstr(str):
    def __lshift__(self, n):
        n %= len(self)
        return csstr(self[n:] + self[:n])

    def __rshift__(self, n):
        n %= len(self)
        return csstr(self[-n:] + self[:-n])


T = int(input())
for i in range(T):
    result = eval(input())  # eval() = evaluate
    print(result)