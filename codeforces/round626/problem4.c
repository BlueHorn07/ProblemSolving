#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    scanf("%d", &N);

    int* nums = (int*)malloc(sizeof(int)*N);

    for(int i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }

    int result = 0;
    int target = 0;
    int temp = 0;
    for(int i=0; i<N; i++){
        target = nums[i];
        temp = 0;
        for(int j=i+1; j<N;){
            if(((N-j)%4 == 0)){
                temp = temp ^ (target + nums[j]) ^ (target + nums[j+1]) ^ (target + nums[j+2]) ^ (target + nums[j+3]);
                j += 4;
            }
            else if((N-j)%2 == 0){
                temp = temp ^ (target + nums[j]) ^ (target + nums[j+1]);
                j += 2;
            }
            else if((N-j)%3 == 0){
                temp = temp ^ (target + nums[j]) ^ (target + nums[j+1]) ^ (target + nums[j+2]);
                j += 3;
            }
            else {
                temp = temp ^ (target+nums[j]);
                j++;
            }        
        }
        result = result ^ temp;
    }

    printf("%d\n", result);

    free(nums);
    return 0;
}