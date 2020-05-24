#include<string>
#include<vector>
#include<stack>
#include<iostream>

using namespace std;

#define MAT vector<vector<int>>

vector<int> index;
int N;

void printMAT(MAT mat){
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat.size(); j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    N = board.size();
    index.assign(N, 0);
    vector<int> bucket;
    printMAT(board);
    for(int i=0; i<moves.size(); i++){
        int query = moves[i] - 1;
        // printMAT(board);
        if(index[query] != N){
            int col_idx = index[query];
            if(board[col_idx][query] == 0){
                while(index[query] != N && board[index[query]][query] == 0){
                    index[query] += 1;
                }
                // cout << "is zero!! " << query << " " << index[query] << " " << board[index[query]][query] << endl;
                if(index[query] != N){
                    bucket.push_back(board[index[query]][query]);
                    board[index[query]][query] = 0;
                    index[query] += 1;
                }
            }else{
                bucket.push_back(board[col_idx][query]);
                board[col_idx][query] = 0;
                index[query] += 1;
            }
        }

        // stack check
        int bucket_idx = bucket.size() - 1;
        bool isRemoved = false;
        while(bucket_idx != 0 && bucket[bucket_idx] == bucket[bucket_idx - 1]){
            answer += 1;
            bucket_idx -= 1;
            bucket.pop_back();
            isRemoved = true;
        }

        if(isRemoved){
            answer += 1;
            bucket.pop_back();
        }
    }


    return answer;
}
