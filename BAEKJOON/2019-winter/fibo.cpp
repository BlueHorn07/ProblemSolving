#include<iostream>
using namespace std;

#define N 1000000
#define P (N/10*15)

int memo[P] = {0, 1};

int main(){
    long long n;
    cin >> n;

    n = n % P;

    for(int i=2; i<=n; i++){
        memo[i] = (memo[i-1] + memo[i-2])% N;
    }

    cout << memo[n] << endl;
    return 0;
}