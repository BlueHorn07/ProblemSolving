#include<iostream>
#define SIZE 1000002
#define MOD 1000000007

using namespace std;

long long memo[1000002][2];


int main(){
    int n;
    cin >> n;

    memo[0][0] = 0;
    memo[1][0] = 2;
    memo[2][0] = 7;
    memo[2][1] = 1;

    for(int i=3; i <=n; i++){
        memo[i][1] = (memo[i-1][1] + memo[i-3][0])%MOD;
        memo[i][0] = (memo[i-1][0] * 2 + memo[i-2][0] * 3 + 2 * memo[i][1])%MOD;
    }
    
    cout << memo[n][0] << endl;
    
    return 0;
}
