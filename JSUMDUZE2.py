# Wojciech Geisler
# 2014-11-14

tests = int(input())

while tests:
    num1, num2 = [x for x in input().split()]
    result = ""
    overflow = 0
    i = len(num1) - 1 # iterator
    j = len(num2) - 1 # iterator

    while overflow or i >= 0 or j >= 0:
        if(i>=0):
            digit1 = int(num1[i])
            i -= 1
        else:
            digit1 = 0

        if(j>=0):
            digit2 = int(num2[j])
            j -= 1
        else:
            digit2 = 0

        resultDigit = (digit1 + digit2 + overflow) % 10
        overflow = (digit1 + digit2 + overflow) // 10
        result = str(resultDigit) + result
    print(result)

    tests -= 1
