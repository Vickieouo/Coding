# Checkpoint 7

import sys

# read file
List = []; b = False
try:
    with open('record.txt', 'r') as fh:  #if file DNE, then OSError
        initial_money = fh.readline()
        if (initial_money == ''):  # if file exist but empty
            b = True
        initial_money = int(initial_money)
        L = fh.readlines()
        if len(L) != 0:  # if there's record(s) in the file
            for i in range(len(L)):
                s = L[i].split('\n')
                s = s[0].split()
                if (len(s) != 2):
                    raise ValueError
                List.append([s[0], int(s[1])])
        print('Welcome back!')  # if load the record sucessfully
except ValueError:  # if the format of the content is invalid
    sys.stderr.write('Invalid format in records.txt. Deleting the contents.\n')
    b = True
except OSError:
    b = True
    
if (b):  # if there's no file/record or ValueError occur
    initial_money = input('How much money do you have? ')
    try:
        initial_money = int(initial_money)
    except ValueError:
        sys.stderr.write('Invalid value for money. Set to 0 by default.\n')
        initial_money = 0
del(b) 

# begin the program
while(True):
    command = input('\nWhat do you want to do (add / view / delete / exit)? ')
    if not (command in ('add', 'view', 'delete', 'exit')):
        sys.stderr.write('Invalid command. Try again.\n')
        continue
    
    if command == 'add':
        print('Add some expense or income records with description and amount:')
        print('desc1 amt1, desc2 amt2, desc3 amt3, ...')
        try:
            record = input()
            r = record.split()
            assert (len(r) == 2)
            r[1] = int(r[1])
            List.append(r)
        except AssertionError:
            sys.stderr.write('The format of a record should be like this: breakfast -50.\nFail to add a record.\n')
        except ValueError:
            sys.stderr.write('Invalid value for money.\nFail to add a record.\n')

    elif command == 'view':
        cur = initial_money
        print("Here's your expense and income records: ")
        print('{:15s}{}'.format('Description','Amount'))
        print('=============================')
        for i in List:
            print(f' {i[0]:15s}{i[1]}')
            cur += int(i[1])
        print('=============================')
        print(f'Now you have {cur} dollars.')
        
    elif command == 'delete':
        if (len(List) == 0):
            sys.stderr.write('No record to be deleted.\n')
            continue
        print('Which record do you want to delete?')
        for i in range(len(List)):
            print(f' {i+1}. {List[i][0]} {List[i][1]}')
        num = input('Please select a numer: ')
        try:
            num = int(num)
            del(List[num-1])
        except ValueError:
            sys.stderr.write('Invalid format. Fail to delete a record.\n')
        except IndexError:
            sys.stderr.write('Index out of range. Fail to delete a record.\n')
    else:
        break

#renew the file
with open('record.txt', 'w') as fh:
    fh.write(str(initial_money) + '\n')
    for l in List:
        fh.write(l[0]+' '+str(l[1])+'\n')