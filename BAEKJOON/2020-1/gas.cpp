#include<cstdio>
#include<cstdlib>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    long long* weight = (long long*)malloc(N * sizeof(long long));
    for(int i=0; i<N-1; i++){
        scanf("%lld", &weight[i]);
    }
    long long* cost = (long long*)malloc((N+1) * sizeof(long long));
    for(int i=0; i<N; i++){
        scanf("%lld", &cost[i]);
    }
    
    long long total_cost = 0;
    long long last_cost = cost[0];
    long long last_visit = 0;
    for(int i=1; i<N; i++){
        if(last_cost >= cost[i] && i != N-1){
            total_cost += (last_cost * weight[i-1]);
            last_cost = cost[i];
            last_visit = i;
        }else{
            total_cost += last_cost * weight[i-1];
        }
    }

    printf("%lld\n", total_cost);
    free(weight);
    free(cost);
    return 0;
}