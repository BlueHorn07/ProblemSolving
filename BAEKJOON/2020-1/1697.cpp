#include<cstdio>
#include<queue>
#include<iostream>

#define SIZE 100000

using namespace std;

queue<int> q;
int DP[SIZE + 1];
bool visit[SIZE + 1];

int main(){
    int N, K;
    scanf("%d %d", &N, &K);

    if (N==K){
        printf("0\n");
        return 0;
    }
    if (K < N){
        printf("%d\n", N-K);
        return 0;
    }

    visit[N] = true;
    q.push(N);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        if(!visit[front - 1] && front - 1 >= 0){

            q.push(front - 1);
            visit[front-1] = true;
            DP[front-1] = DP[front] + 1;
            if(front - 1 == K){
                break;
            }
        }
        if(!visit[front+1] && front + 1 <= SIZE){

            q.push(front+1);
            visit[front+1] = true;
            DP[front+1] = DP[front] + 1;
            if(front + 1 == K){
                break;
            }
        }
        if(!visit[front*2] && front * 2 <= SIZE){

            q.push(front*2);
            visit[front*2] = true;
            DP[front*2] = DP[front] + 1;
            if(front*2 == K){
                break;
            }
        }
    }
    printf("%d\n", DP[K]);

    return 0;
}