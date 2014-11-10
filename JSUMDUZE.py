# JSUMDUZE
# 2014-11-10
tests = int(input())
 
while tests:
line = input()
num1, num2 = [int(x) for x in line.split()]
print(num1+num2)
 
tests -= 1
