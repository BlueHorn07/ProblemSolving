#include<iostream>

using namespace std;

int main(){
    int T;
    cin >> T;

    long long memo[100] = {1, 1, 1, 2, 2, 3};

    for(int t = 0; t < T; t++){
        int N;
        cin >> N;
        for(int i=6; i<N; i++){
            memo[i] = memo[i-1] + memo[i-5];
        }
        cout << memo[N-1] << endl;
    }
}