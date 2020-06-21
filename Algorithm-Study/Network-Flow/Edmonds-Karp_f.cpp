#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<queue>
#include <string.h>

#define MAX 100

using namespace std;

int Prev[MAX];
int capacity[MAX][MAX];
int flow[MAX][MAX];
vector<int> edges[MAX];

long long maxFlow(int start, int end){
    long long result = 0;
    while(1){
        fill(Prev, Prev+MAX, -1);
        queue<int> q;
        q.push(start);
        Prev[start] = start;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i=0; i<edges[curr].size(); i++){
                int adj = edges[curr][i];
                if(Prev[adj] == -1 && capacity[curr][adj] > flow[curr][adj]){
                    Prev[adj] = curr;
                    q.push(adj);
                    if(adj == end) break;
                }
            }
        }
        if(Prev[end] == -1) break;

        int curFlow = INT_MAX;
        for(int v = end; v != start; v = Prev[v]){
            curFlow = min(curFlow, capacity[Prev[v]][v] - flow[Prev[v]][v]);
        }

        for(int v = end; v != start; v = Prev[v]){
            flow[Prev[v]][v] += curFlow;
            flow[v][Prev[v]] -= curFlow;
        }
        result += curFlow;
    }
    return result;
}


int CtoI(char c){
    if(c >= 'A' && c <= 'Z')
        return c - 'A';
    else 
        return c - 'a' + 26;
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        char s, e;
        int c;
        cin >> s >> e >> c;
        int int_s = CtoI(s), int_e = CtoI(e);
        edges[int_s].push_back(int_e);
        edges[int_e].push_back(int_s);
        capacity[int_s][int_e] += c;
        capacity[int_e][int_s] += c;
    }
    printf("%lld", maxFlow(CtoI('A'), CtoI('Z')));
    return 0;
}