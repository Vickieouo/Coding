class Rectangle:
    def __init__(self, w, h):
        self.w = w
        self.h = h

    @property
    def area(self):
        return self.w * self.h

    def __gt__(self, other):
        return (self.area > other.area and ((other.w<=self.w and other.h<=self.h)or(other.h<=self.w and other.w<=self.h)))

    def __lt__(self, other):
        return (self.area < other.area and ((self.w<=other.w and self.h<=other.h)or(self.h<=other.w and self.w<=other.h)))

    def __eq__(self, other):
        return (self.area == other.area and ((other.w==self.w and other.h==self.h)or(other.h==self.w and other.w==self.h)))

T = int(input())
for t in range(T):
    s = input()
    print(eval(s))