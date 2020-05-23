#include<stdio.h>

int *dp;

int fun(int curr, int hop){
    if(curr == 0){
        return 0;
    }else if(curr == 1){
        return 1;
    }
    else if(dp[curr] != 0){
        return dp[curr];
    }else{
        min
    }
}

int main(){
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        int S, E;
        scanf("%d %d", &S, &E);
        E = E-S;
        S = 0;

        dp = (int*)malloc(sizeof(int)*E);


        free(dp);
    }


    return 0;
}