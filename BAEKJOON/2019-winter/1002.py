import math

def NumOfLocation(x1, y1, r1, x2, y2, r2):
    if(x1 == x2 and y1 == y2):
        if r1 == r2:
            print(-1, end='\n')
        else:
            print(0, end='\n')
    else:
        L2 = (x1-x2)**2 + (y1-y2)**2

        if L2 == (r1 + r2)**2 : # 외접
            print(1, end='\n')
        elif math.sqrt(L2) + r1 == r2 : # 내접
            print(1, end='\n')
        elif L2 > (r1 + r2)**2 or math.sqrt(L2) + r1 < r2:
            print(0, end='\n')
        else:
            print(2, end='\n')

if __name__ == "__main__":
    num = int(input())

    for i in range(num):
        x1, y1, r1, x2, y2, r2 = map(int, input().split())
        if r1 < r2:
            NumOfLocation(x1, y1, r1, x2, y2, r2)
        else:
            NumOfLocation(x2, y2, r2, x1, y1, r1)

