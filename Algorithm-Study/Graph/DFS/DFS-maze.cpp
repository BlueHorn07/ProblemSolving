// https://www.acmicpc.net/problem/2667

#include<cstdio>
#include<vector>
#include<string>

using namespace std;

#define MAT vector<vector<int>>
#define ROW vector<int>

void DFS(MAT field, MAT &visit, int N){

}

int main(){
    int N;
    scanf("%d", &N);
    MAT field;
    for(int i=0; i<N; i++){
        string line;
        scanf("%s", &line);

        for(int j=0; j<N; j++){
            field[i].push_back(line[j] - '0');
        }
    }
    MAT visit(N, ROW(N, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(field[i][j] == '1' && visit[i][j] == 0]){
                DFS(field, visit, N);
                
            }
        }
    }

    return 0;
}