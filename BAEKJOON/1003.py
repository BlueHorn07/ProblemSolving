cnt0 = [1, 0]
cnt1 = [0, 1]

def fibo(n):
    if n==0 or n==1:
        return
    else :
        if(len(cnt0)-1 >= n):
            return
        else:
            fibo(n-1)
            fibo(n-2)
            cnt0.append(cnt0[n-1] + cnt0[n-2])
            cnt1.append(cnt1[n-1] + cnt1[n-2])
            return

if __name__ == "__main__":
    num = int(input())

    for i in range(num):
        a = int(input())
        fibo(a)
        print(str(cnt0[a]) + " " + str(cnt1[a]))

# DP로 다시 짜!!
