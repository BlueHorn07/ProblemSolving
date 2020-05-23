#include<cstdio>
#include<cstdlib>

#define VMAX 501

using namespace std;

long long DP[VMAX][VMAX];
int M, N;
int** Map;
bool visit[VMAX][VMAX];

long long fun(int y, int x){
    if(visit[y][x] == false){
        if(x+1 <= N-1 && Map[y][x] < Map[y][x+1]){
            DP[y][x] += fun(y, x+1);
            //if(y==0 && x==1) printf("x+1 %lld\n", fun(y, x+1));
        }
        if(x-1 >= 0 && Map[y][x] < Map[y][x-1]){
            DP[y][x] += fun(y, x-1);
            //if(y==0 && x==1) printf("x-1 %lld\n", fun(y, x-1));
        }
        if(y+1 <= M-1 && Map[y][x] < Map[y+1][x]){
            DP[y][x] += fun(y+1, x);
           // if(y==0 && x==1) printf("y+1 %lld\n", fun(y+1, x));
        }
        if(y-1 >= 0 && Map[y][x] < Map[y-1][x]){
            DP[y][x] += fun(y-1, x);
            //if(y==0 && x==1) printf("y-1 %lld\n", fun(y-1, x));
        }
        visit[y][x] = true;
    }
    return DP[y][x];
}


int main(){
    scanf("%d %d", &M, &N);
    Map = (int**)malloc((M+1) * sizeof(int*));
    for(int i=0; i<M; i++){
        Map[i] = (int*)malloc((N+1) * sizeof(int));
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &Map[i][j]);
        }
    }
    DP[0][0] = 1;


    printf("%lld\n", fun(M-1, N-1));

   /*  for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            printf("%lld ", DP[i][j]);
        }
        printf("\n");
    } */
    for(int i=0; i<=M; i++){
        free(Map[i]);
    }
    free(Map);

    return 0;    
}