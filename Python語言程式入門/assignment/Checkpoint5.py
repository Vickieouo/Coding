# Checkpoint 5

total = int(input('How much money do you have? '))
s = input('Add some expense or income records with description and amount:\n')
L = s.split(', ')
for i in L:
    item = i.split()
    total += int(item[1])
print("Here's your expense and income records:")
print('\n'.join(L))
print(f'Now you have {total} dollars.')