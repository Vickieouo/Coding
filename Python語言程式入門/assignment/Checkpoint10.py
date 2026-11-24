#Checkpoint 10

import sys

# class definitions
class Record:
    """Represent a record."""
    def __init__(self, category, description, amount):
        # 1. Define the formal parameters so that a Record can be instantiated
        #    by calling Record('meal', 'breakfast', -50).
        # 2. Initialize the attributes from the parameters. The attribute
        #    names should start with an underscore (e.g. self._amount)
        self._category = category
        self._description = description
        self._amount = amount
    
    # Define getter methods for each attribute with @property decorator.
    # Example usage:
    # >>> record = Record('meal', 'breakfast', -50)
    # >>> record.amount
    # -50
    @property
    def category(self):
        return self._category
    @property
    def description(self):
        return self._description
    @property
    def amount(self):
        try:
            return int(self._amount)
        except ValueError:
            sys.stderr.write('Invalid value for money.\nFail to add a record.\n')

class Records:
    """Maintain a list of all the 'Record's and the initial amount of money."""
    def __init__(self):
        # 1. Read from 'records.txt' or prompt for initial amount of money.
        # 2. Initialize the attributes (self._records and self._initial_money)
        #    from the file or user input.
        
        records = []; b = False
        try:
            with open('records.txt', 'r') as fh:  #if file DNE, then OSError
                initial_money = fh.readline()
                if (initial_money == ''):  # if file exist but empty
                    b = True
                initial_money = int(initial_money)
                L = fh.readlines()
                if len(L) != 0:  # if there's record(s) in the file
                    for i in range(len(L)):
                        s = L[i].split('\n')
                        s = s[0].split()
                        if (len(s) != 3):
                            raise ValueError
                        record = Record(s[0], s[1], int(s[2]))
                        records.append(record)
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
                
        self._initial_money = initial_money
        self._records = records
        
    def add(self, record, categories):
        """Add the record into records' list."""
        # 1. Define the formal parameter so that a string input by the user
        #    representing a record can be passed in.
        # 2. Convert the string into a Record instance.
        # 3. Check if the category is valid. For this step, the predefined
        #    categories have to be passed in through the parameter.
        # 4. Add the Record into self._records if the category is valid.
        
        try:
            r1 = record.split()
            assert (len(r1) == 3)
            r2 = Record(r1[0], r1[1], int(r1[2]))
            if (categories.is_category_valid(r2.category)):
                self._records.append(r2)
            else:
                sys.stderr.write('The specified category is not in the category list.\n\
You can check the category list by command "view categories".\n\
Fail to add a record.\n')
        except AssertionError:
            sys.stderr.write('The format of a record should be like this: meal breakfast -50.\nFail to add a record.\n')
        except ValueError:
            sys.stderr.write('Invalid value for money.\nFail to add a record.\n')
    def view(self):
        """To print the record list and total money in format."""
        # 1. Print all the records and report the balance.
        
        print("Here's your expense and income records:")
        cur = 0
        print('{:17s}{:15s}{}'.format('Category','Description','Amount'))
        print('=======================================')
        for record in self._records:
            print(f' {record.category:17s}{record.description:15s}{record.amount}')
            cur += int(record.amount)
        print('=======================================')
        print(f'Now you have {self._initial_money + cur} dollars.')
    def delete(self):
        """To delete specified record."""
        # 1. Define the formal parameter.
        # 2. Delete the specified record from self._records.
        
        if (len(self._records) == 0):
            sys.stderr.write('No record to be deleted.\n')
        print('Which record do you want to delete?')
        for index,record in enumerate(self._records):
            print(f' {index+1}. {record.category} {record.description} {record.amount}')
        num = input('Please select a numer: ')
        try:
            num = int(num)
            if num <= 0:
                raise IndexError
            del(self._records[num-1])
        except ValueError:
            sys.stderr.write('Invalid format. Fail to delete a record.\n')
        except IndexError:
            sys.stderr.write('Index out of range. Fail to delete a record.\n')
    def find(self, target_categories):
        """Find expense and income records under category."""
        # 1. Define the formal parameter to accept a non-nested list
        #    (returned from find_subcategories)
        # 2. Print the records whose category is in the list passed in
        #    and report the total amount of money of the listed records.
        
        if not (target_categories):
            sys.stderr.write("Category doesn't exist.\n")
            return
        record = list(filter(lambda r: r.category in target_categories, self._records))
        print(f"Here's your expense and income records: under category "+f'"{category}"')
        cur = 0
        print('{:17s}{:15s}{}'.format('Category','Description','Amount'))
        print('=======================================')
        for r in record:
            print(f' {r.category:17s}{r.description:15s}{r.amount}')
            cur += int(r.amount)
        print('=======================================')
        print(f'The total amount above is {cur}.')
    def save(self):
        """Write the initial money and all the records to 'records.txt'."""

        with open('records.txt', 'w') as fh:
            fh.write(str(self._initial_money) + '\n')
            for record in self._records:
                fh.write(f'{record.category} {record.description} {record.amount}\n')

class Categories:
    """Maintain the category list and provide some methods."""
    def __init__(self):
        # 1. Initialize self._categories as a nested list.
        self._categories = ['expense', ['food', ['meal', 'snack', 'drink'],\
                'transportation', ['bus', 'railway']],\
                'income', ['salary', 'bonus']]
        
    def view(self, categories = None, level = 0):
        """Print a category with proper indentation in the base case."""
        # 1. Define the formal parameters so that this method
        #    can be called recursively.
        # 2. Recursively print the categories with indentation.
        # 3. Alternatively, define an inner function to do the recursion.
        
        if(categories == None):
            categories = self._categories
        if(type(categories) == list):
            for	i in categories:
                self.view(i, level+1)
        else:
            print(f'{" "*2*(level-1)}- {categories}')
    def is_category_valid(self, category, categories = None):
        """Check if the specified category is in the predefined list categories.
        Returns True if category is in categories and False otherwise."""
        # 1. Define the formal parameters so that a category name can be
        #    passed in and the method can be called recursively.
        # 2. Recursively check if the category name is in self._categories.
        # 3. Alternatively, define an inner function to do the recursion.
        
        if(categories == None):
            categories = self._categories
        for i in categories:
            if(i == category):
                return True
            elif(type(i) == list):
                if(self.is_category_valid(category, i)):
                    return True
        return False
    def find_subcategories(self, category, categories = None):
        """Returns a non-nested list containing the specified category and all the subcategories under it (if any)."""
        # 1. Define the formal parameters so that a category name can be
        #    passed in and the method can be called recursively.
        # 2. Recursively find the target category and call the
        #    self._flatten method to get the subcategories into a flat list.
        # 3. Alternatively, define an inner function to do the recursion.
        
        if(categories == None):
            categories = self._categories
        if(type(categories) == list):
            for v in categories:
                p = self.find_subcategories(category, v)
                if(p == True):
                    index = categories.index(v)
                    if(index + 1 < len(categories) and type(categories[index + 1]) == list):
                        return self._flatten(categories[index:index + 2])
                    else:
                        return [v]
                if(p != []):
                    return p
        return True if categories == category else []
    def _flatten(self, L):
        """Return a flat list that contains all element in the nested list L.
        For example, flatten([1, 2, [3, [4], 5]]) returns [1, 2, 3, 4, 5]"""
        # 1. Define the formal parameters so that this method
        #    can be called recursively.
        # 2. Recursively call self._flatten and return the flat list.
        # 3. (FYI) The method name starts with an underscore to indicate that
        #    it is not intended to be called outside the class.
        # 4. Alternatively, put flatten as an inner function of
        #    find_subcategories.

        if(type(L) == list):
            result = []
            for i in L:
                result.extend(self._flatten(i))
            return result
        else:
            return [L]

categories = Categories()
records = Records()

while True:
    command = input('\nWhat do you want to do (add / view / delete / view categories /find / exit)? ')
    if command == 'add':
        record = input('Add some expense or income records with category, description, and amount (separate by spaces):\ncat1 desc1 amt1, cat2 desc2 amt2, cat3 desc3 amt3, ...\n')
        records.add(record, categories)
    elif command == 'view':
        records.view()
    elif command == 'delete':
        records.delete()
    elif command == 'view categories':
        categories.view()
    elif command == 'find':
        category = input('Which category do you want to find? ')
        target_categories = categories.find_subcategories(category)
        records.find(target_categories)
    elif command == 'exit':
        records.save()
        break
    else:
        sys.stderr.write('Invalid command. Try again.\n')