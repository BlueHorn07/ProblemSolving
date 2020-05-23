#include<stdio.h>
#define SIZE 500000

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    int nums[SIZE] = {};
    char a;
    for(int i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }
    
    int product = 1;
    int value = 0;
    int result = 0;
    int i, j;

    for(i=0; i < N; i++){
        if(product == 0){
            break;
        }
        value = nums[i];
        for(j=i+1; j < N; j+=8){
            for(int k=0; k<8 && j+k < N; k++){
                result = value - nums[j+k];

                result = result < 0 ? (-result)%M : result%M;

                if(result == 0){
                    product = 0;
                    break;
                }
                else{
                    product = (product * result)%M;
                }
            }
            
        }
    }

    printf("%d", product);

    return 0;
}