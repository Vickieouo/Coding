class Student:  #class declaration
    def __init__(self,name,ID):  #constructor
        self.name=name
        self.ID=ID
    def showMe(self):
        print('Name:',self.name,',ID:',self.ID)
    def changeName(self, newName):
        self.name=newName
