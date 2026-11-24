import string
def MakeCamelCase(s):
    return ''.join(string.capwords(s).split())

str = input()
print(MakeCamelCase(str))
