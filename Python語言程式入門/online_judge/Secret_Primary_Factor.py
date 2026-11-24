N = input()
n_odd = n_even = 0; Odd = Even = ''

#Step1
n = len(N)
for i in range(n):
    if i % 2 == 0:
        Even += N[i]
    elif i % 2 == 1:
        Odd += N[i]

#Step2
Even = int(Even); Odd = int(Odd)
num = abs(Even-Odd)

#Step3
i = 2
while(i*i <= num):
    while(num % i == 0):
        num = num / i
    i+=1

print(int(num))
