#include<stdio.h>

char board[51][51];

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    fflush(stdin);
    char temp;
    for(int i=0; i<N; i++){
        for(int j=0; j<M+1; j++){
            temp = getchar();
            if(temp!='\n'){
                board[i][j] = temp;
            }
        }
    }

    int result = 9999;
    for(int i=0; i<N-7; i++){
        for(int j=0; j<M-7; j++){
            int cnt1 = 0;
            int cnt2 = 0;
            for(int a=i; a<i+8; a++){
                for(int b=j; b<j+8; b++){
                    if(a%2==0){
                        if(b%2==0){
                            if(board[a][b]=='W')
                                cnt1++;
                            else
                                cnt2++;
                        }else{
                            if(board[a][b]=='B')
                                cnt1++;
                            else
                                cnt2++;
                        }
                    }else{
                        if(b%2==0){
                            if(board[a][b]=='W')
                                cnt2++;
                            else
                                cnt1++;
                        }else{
                            if(board[a][b]=='B')
                                cnt2++;
                            else
                                cnt1++;
                        }
                    }
                }
            }
            cnt1 = (cnt1 < cnt2 ? cnt1 : cnt2);
            if(cnt1 < result){
                result = cnt1;
            }
        }
    }
    printf("%d\n", result);

    return 0;
}