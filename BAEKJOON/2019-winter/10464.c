#include<stdio.h>

int XOR(int n){
    int result = 0;
    result += ((n+1)/2)%2;
    for(int i=2; i <= n; i*=2){
        //printf("%d- %d\n", i, result);

        if(((n+1)/i)%2 != 0){
            //printf("aaaaa %d\n", result + (((n+1)%i)%2)*i);
            result = result + ((((n+1)%i)%2)*i);
        }
    }

    return result;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        int S, F;
        scanf("%d %d", &S, &F);
        //printf("%d: %d %d\n", t, XOR(F), XOR(S-1));
        int result = XOR(F)^XOR(S-1);

        printf("%d\n", result);
    }
    return 0;
}