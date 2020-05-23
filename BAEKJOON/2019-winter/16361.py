word = input()

for i in range(97, 123):
    try :
        print(word.index(chr(i)), end=' ')
    except ValueError:
        print(-1, end=' ')