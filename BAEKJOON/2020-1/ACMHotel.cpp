#include<cstdio>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        int H, W, N;
        scanf("%d %d %d", &H, &W, &N);
        if(N==1){
            printf("101\n");
            continue;
        }
        int result = (N%H == 0 ? H : N%H) * 100 + (N%H == 0 ? N/H - 1 : N/H) + 1;
        printf("%d\n", result);
    }
    return 0;
}