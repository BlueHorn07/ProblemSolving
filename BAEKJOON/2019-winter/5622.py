word = input()

sum = 0

for i in range(len(word)):
    value = ord(word[i])
    if 65 <= value and value <= 67:
        sum += 3
    elif 68 <= value and value <= 70:
        sum += 4
    elif 71 <= value and value <= 73:
        sum += 5
    elif 74 <= value and value <= 76:
        sum += 6
    elif 77 <= value and value <= 79:
        sum += 7
    elif 80 <= value and value <= 83:
        sum += 8
    elif 84 <= value and value <= 86:
        sum += 9
    elif 87 <= value and value <= 90:
        sum += 10
print(sum)