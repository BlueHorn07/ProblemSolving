#include<iostream>
#define MOD 15746

using namespace std;

int main(){
    long N;
    cin >> N ;

    long memo[2] = {1, 1};

    for(int i=2; i <= N; i++){
        int temp = memo[1];
        memo[1] = (memo[0] + memo[1])%MOD;
        memo[0] = temp;
    }

    cout << memo[1] << endl;

    return 0;
}