import sys
import collections

matricies = collections.defaultdict(list)

if __name__ == "__main__":
    N = int(sys.stdin.readline().rstrip())

    for i in range(N):
        matrix, row, col = sys.stdin.readline().rstrip().split()
        row = int(row)
        col = int(col)
        matricies[matrix] = (row, col)

    while True:
        line = sys.stdin.readline().rstrip()
        if line == '':
            break
        result = 0
        s = []
        isValid = True
        for c in line:
            if c != '(' and c != ')':
                if matricies[c]:
                    s.append(matricies[c])
            elif c == ')':
                m2 = s.pop()
                while m2 == '(' and s:
                    m2 = s.pop()
                m1 = s.pop()
                while m1 == '(' and s:
                    m1 = s.pop()
                
                if m1[1] != m2[0]:
                    print("error")
                    isValid = False
                    break
                result += m1[0]*m1[1]*m2[1]
                s.append((m1[0], m2[1]))
        if isValid:
            print(result)

