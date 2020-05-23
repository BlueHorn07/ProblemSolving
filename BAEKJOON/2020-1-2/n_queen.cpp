#include<cstdio>
#include<stack>
#include<vector>

#define MAX 16

using namespace std;

bool visit[16][16];

long cnt = 0;

bool isPromising(vector<int> node, int r, int c){
    if(c == 0){
        return true;
    }
    int idx = 0;
    for(int i=0; i<c; i++){
        if(node[i] == r)
            return false;
    
        if(i + r == node[i] + c)
            return false;

        if(i + node[i] == c + r)
            return false;
    }
    return true;
}


void dfs(vector<int> node, int c, int N){
    if(c == N){
        //printf("REACH the end!\n");
        cnt += 1;
        return;
    }
    if(c == -1){
        for(int i=0; i<=(N-1)/2; i++){
            if(isPromising(node, i, c+1)){
                //printf("it is promising! %d %d\n", i, c+1);
                vector<int> next_node = node;
                next_node[0] = i;
                dfs(next_node, 0, N);
            }
        }
    }
    else{
        for(int i=0; i<=N; i++){
            if(isPromising(node, i, c+1)){
                //printf("it is promising! %d %d\n", i, c+1);
                vector<int> next_node = node;
                next_node[c+1] = i;
                dfs(next_node, c+1, N);
            }
        }
    }
}

void N_queen(int num){
    // initial vector
    vector<int> start_node;
    start_node.assign(num+1, -1);
    if(num==1){
        printf("1\n");
        return;
    }
    dfs(start_node, -1, num-1);
    if(num % 2 == 0){
        cnt *= 2;
    }else{
        cnt *= 2;
        start_node[0] = num/2;
        dfs(start_node, 0, num-1);
        
    }
    printf("%ld\n", cnt);
}


int main(){
    int N;
    scanf("%d", &N);
    N_queen(N);
    return 0;
}