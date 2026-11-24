# Checkpoint 4

money = input('How much money do you have? ') #type(money) = str
str1 = input('Add an expense or income record with description and amount:\n')
str2 = str1.split()
money = int(money) + int(str2[1]) #type(money) = int
print('Now you have %d dollars.' %money)