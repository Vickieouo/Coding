import re

def is_strong(passwd):
    b = True
    if len(passwd) < 8:
        b = False
    elif re.search('[a-z]', passwd) == None:
        b = False
    elif re.search('[A-Z]', passwd) == None:
        b = False
    elif re.search(r'\d', passwd) == None:
        b = False
    elif re.search(r'[-!@#$%^&*()+]', passwd) == None:
        b = False
    elif re.search(r'(.)\1', passwd):
        b = False
    return b

# Note that the following code is for local testing purposes only. You should leave this part of code unchanged and not submit it to the OJ system.
T = int(input())
for t in range(T):
    passwd = input()
    if is_strong(passwd):
        print('Strong')
    else:
        print('Weak')