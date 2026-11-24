#Checkpoint 9

def initialize_categories():
    """define a multi-level list
    ['expense', ['food', ['meal', 'snack', 'drink'], 'transportation', ['bus', 'railway']], 'income', ['salary', 'bonus']]and simply return it."""
    
    categories = ['expense', ['food', ['meal', 'snack', 'drink'],\
                'transportation', ['bus', 'railway']],\
                'income', ['salary', 'bonus']]
    return categories

def view_categorizes(categories, level = 0):
    """Print a category with proper indentation in the base case."""
    
    if(type(categories) == list):
        for	i in categories:
            view_categorizes(i, level+1)
    else:
        print(f'{" "*2*(level-1)}- {categories}')
    
def is_category_valid(category, categories):
    """Check if the specified category is in the predefined list categories.
    Returns True if category is in categories and False otherwise."""
    
    for i in categories:
        if(i == category):
            return True
        elif(type(i) == list):
            if(is_category_valid(category, i)):
                return True
    return False

def find(category, records, categories):
    """Find expense and income records under category."""
    
    L = find_subcategories(category, categories)
    record = list(filter(lambda r: r[0] in L, records))
    print(f"Here's your expense and income records: under category "+f'"{category}"')
    cur = print_records(record)
    print(f'The total amount above is {cur}.')

def print_records(records):
    """To print the record list in format."""
    
    cur = 0
    print('{:17s}{:15s}{}'.format('Category','Description','Amount'))
    print('=======================================')
    for i in records:
        print(f' {i[0]:17s}{i[1]:15s}{i[2]}')
        cur += int(i[2])
    print('=======================================')
    return cur

    
def find_subcategories(category, categories):
    """Returns a non-nested list containing the specified category and all the subcategories under it (if any)."""
    
    if(type(categories) == list):
        for v in categories:
            p = find_subcategories(category, v)
            if(p == True):
                index = categories.index(v)
                if(index + 1 < len(categories) and type(categories[index + 1]) == list):
                    return flatten(categories[index:index + 2])
                else:
                    return [v]
            if(p != []):
                return p
    return True if categories == category else []

def flatten(L):
    """Return a flat list that contains all element in the nested list L.
    For example, flatten([1, 2, [3, [4], 5]]) returns [1, 2, 3, 4, 5]"""
    
    if type(L) == list:
        result = []
        for i in L:
            result.extend(flatten(i))
        return result
    else:
        return [L]
    
def delete(records):
    """To delete specified record."""
    
    print('Which record do you want to delete?')
    for i,v in enumerate(records):
        print(f' {i+1}. {v[0]} {v[1]} {v[2]}')
    num = int(input('Please select a numer: '))
    if num <= 0:
        raise IndexError
    del(records[num-1])
    return records

    
total = int(input('How much money do you have? '))
categories = initialize_categories()
records = []

while(True):
    command = input('\nWhat do you want to do\
(add / view / delete / view categories /find / exit)? ')
    if(command == 'add'):
        L = input('Add some expense or income records with category, description, and amount (separate by spaces):\n\
cat1 desc1 amt1, cat2 desc2 amt2, cat3 desc3 amt3, ...\n').split()
        if (is_category_valid(L[0], categories)):
            records.append(L)
        else:
            print('The specified category is not in the category list.\n\
You can check the category list by command "view categories".\n\
Fail to add a record.')
    elif(command == 'view'):
        print("Here's your expense and income records:")
        cur = print_records(records)
        print(f'Now you have {total+cur} dollars.')
    elif(command == 'delete'):
        records = delete(records)
    elif(command == 'view categories'):
        view_categorizes(categories)
    elif(command == 'find'):
        category = input('Which category do you want to find? ')
        find(category, records, categories)
    elif(command == 'exit'):
        break