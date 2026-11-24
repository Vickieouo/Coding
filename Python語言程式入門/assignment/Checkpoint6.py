# Checkpoint 6

total = int(input('How much money do you have? '))
List = []
while(True):
    k = input('\nWhat do you want to do (add / view / delete / exit)? ')
    if k == 'add':
        s = input('Add some expense or income records with description and amount:\n')
        List.append(s.split())
    elif k == 'view':
        cur = total
        print("Here's your expense and income records: ")
        print('{:15s}{}'.format('Description','Amount'))
        print('=============================')
        for i in List:
            print(f' {i[0]:15s}{i[1]}')
            cur += int(i[1])
        print('=============================')
        print(f'Now you have {cur} dollars.')
    elif k == 'delete':
        print('Which record do you want to delete?')
        for i in range(len(List)):
            print(f' {i+1}. {List[i][0]} {List[i][1]}')
        num = int(input('Please select a numer: '))
        del(List[num-1])
    else:
        break