#include<stdio.h>
#define MAX 101

int gcd(int x, int y){
    if(x < y){
        int temp = x;
        x = y;
        y = temp;
    }
    if(y==0)
        return x;
    else
        return gcd(x%y, y);
}

int main(){
    int t;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
        int n;
        scanf("%d", &n);
        int nums[MAX];
        for(int j=0; j<n; j++){
            scanf("%d", &nums[j]);
        }
        //printf("%d %d %d", n, nums[0], nums[1]);

        long long sum = 0;

        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                sum += gcd(nums[j], nums[k]);
            }
        }

        printf("%lld\n", sum);
    }
    return 0;
}