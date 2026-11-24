# Checkpoint 8

import sys

# 5 functions
def initialize():
    records = []; b = False
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
                    records.append([s[0], int(s[1])])
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
    
    return initial_money, records

def add(records):
    print('Add some expense or income records with description and amount:')
    print('desc1 amt1, desc2 amt2, desc3 amt3, ...')
    try:
        r = input()
        record = r.split()
        assert (len(record) == 2)
        record[1] = int(record[1])
        records.append(record)
    except AssertionError:
        sys.stderr.write('The format of a record should be like this: breakfast -50.\nFail to add a record.\n')
    except ValueError:
        sys.stderr.write('Invalid value for money.\nFail to add a record.\n')
    return records

def view(records):
    cur = initial_money
    print("Here's your expense and income records: ")
    print('{:15s}{}'.format('Description','Amount'))
    print('=============================')
    for i in records:
        print(f' {i[0]:15s}{i[1]}')
        cur += int(i[1])
    print('=============================')
    print(f'Now you have {cur} dollars.')
    return records

def delete(records):
    if (len(records) == 0):
        sys.stderr.write('No record to be deleted.\n')
        return records
    print('Which record do you want to delete?')
    for i in range(len(records)):
        print(f' {i+1}. {records[i][0]} {records[i][1]}')
    num = input('Please select a numer: ')
    try:
        num = int(num)
        if num <= 0:
            raise IndexError
        del(records[num-1])
    except ValueError:
        sys.stderr.write('Invalid format. Fail to delete a record.\n')
    except IndexError:
        sys.stderr.write('Index out of range. Fail to delete a record.\n')
    return records

def save(initial_money, records):
    with open('record.txt', 'w') as fh:
        fh.write(str(initial_money) + '\n')
        for l in records:
            fh.write(l[0]+' '+str(l[1])+'\n')

# main program
initial_money, records = initialize()
while(True):
    command = input('\nWhat do you want to do (add / view / delete / exit)? ')
    if command == 'add':
        records = add(records)

    elif command == 'view':
        records = view(records)
        
    elif command == 'delete':
        records = delete(records)
    elif command == 'exit':
        save(initial_money, records)
        break
    else:
        sys.stderr.write('Invalid command. Try again.\n')