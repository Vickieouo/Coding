def MakeSnakeCase(s):
    return '_'.join(s.split())

str = input()
print(MakeSnakeCase(str))
