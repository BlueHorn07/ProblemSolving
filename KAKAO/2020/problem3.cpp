#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define MAT vector<vector<int>>
#define ROW vector<int>

bool total_number_test(MAT key, MAT lock){
    int cnt_key = 0;
    for(int i=0; i<key.size(); i++){
        for(int j=0; j<key.size(); j++){
            if(key[i][j] == 1)
                cnt_key += 1;
        }
    }
    int cnt_lock = 0;
    for(int i=0; i<lock.size(); i++){
        for(int j=0; j<lock.size(); j++){
            if(lock[i][j] == 0)
                cnt_lock += 1;
        }
    }
    if(cnt_key < cnt_lock)
        return false;
    else
        return true;
}


MAT rotate_MAT(MAT mat){
    // CCW rotataion
    MAT rotated_MAT;
    for(int c=0; c<mat.size(); c++){
        ROW col;
        for(int r=0; r<mat.size(); r++){
            col.push_back(mat[r][c]);
        }
        reverse(col.begin(), col.end());
        rotated_MAT.push_back(col);
    }

    return rotated_MAT;
}

MAT extend_MAT(MAT mat){
    MAT extended;
    for(int i=0; i < mat.size()*3; i++){
        ROW row;
        for(int j=0; j < mat.size()*3; j++){
            if(mat.size() <= i && i < mat.size()*2){
                if(mat.size() <= j && j < mat.size()*2)
                    row.push_back(mat[i - mat.size()][j - mat.size()]);
                else
                    row.push_back(0);
            } else
                row.push_back(0);
        }
        extended.push_back(row);
    }
    return extended;
}

MAT subMAT(MAT original, int x, int y, int n){
    MAT sub_matrix;

    for(int i=y; i<y+n; i++){
        ROW sub_row;
        for(int j=x; j<x+n; j++){
            // cout << i << " " << j << " " << endl;
            sub_row.push_back(original[i][j]);
        }
        sub_matrix.push_back(sub_row);
    }

    return sub_matrix;
}

int N, M;

void printMAT(MAT mat){
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat.size(); j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int countZeros(MAT mat){
    int cnt = 0;
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat.size(); j++){
            if(mat[i][j]==0)
                cnt += 1;
        }
    }
    return cnt;
}

int countOnes(MAT mat){
    int cnt = 0;
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat.size(); j++){
            if(mat[i][j]==1)
                cnt += 1;
        }
    }
    return cnt;
}

bool solution(MAT key, MAT lock) {
    // IF has less than number of lock's -> false!
    N = lock.size();
    M = key.size();
    if(!total_number_test(key, lock))
        return false;
    

    MAT extended_lock = extend_MAT(lock);
    int cntZeros = countZeros(lock);
    int cntOnes = countOnes(key);


    if(cntZeros == 0){
        return true;
    }
    if(cntZeros == N && cntOnes == N){
        return true;
    }

    // test for rotated one
    MAT rotated = key;
    for(int t=0; t<4; t++){
        rotated = rotate_MAT(rotated);
        for(int i =0; i < 2*N; i++){
            for(int j = 0; j < 2*N; j++){
                int cnt = cntZeros;
                for(int key_i = 0; key_i < M; key_i++){
                    for(int key_j = 0; key_j < M; key_j++){
                        int iter_i = key_i + i;
                        int iter_j = key_j + j;
                        if(N <= iter_i && iter_i < N*2){
                            if(N <= iter_j && iter_j < N*2){
                                if(extended_lock[iter_i][iter_j] == 0 && rotated[key_i][key_j] == 1){
                                    cnt -= 1;
                                }else if(extended_lock[iter_i][iter_j] == 1 && rotated[key_i][key_j] == 1){
                                    break;
                                }else if(extended_lock[iter_i][iter_j] == 0 && rotated[key_i][key_j] == 0){
                                    break;
                                }
                            }
                        }
                    }
                }
                if(cnt == 0){
                    return true;
                }
            }
        }
    }
    return false;
}