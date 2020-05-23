#include<cstdio>
#include<cmath>
#include<cfloat>
#include<vector>
#include<algorithm>

#define NMAX 501

using namespace std;

vector<int> mins;

long long favors[NMAX];

long double K_avg(long long nums[], int s, int k){
    long double k_avg = 0;
    for (int i=s; i<s+k; i++){
        k_avg += (long double) nums[i];
    }
    // printf("in average %Lf\n", k_avg);
    return k_avg / (long double) k;
}

long double K_dev(long long nums[], int s, int k, long double k_avg){
    long double k_dev = 0;
    for (int i=s; i<s+k; i++){
        k_dev += pow(nums[i] - k_avg, 2);
    }
    return sqrt(k_dev / (long double) k);
}


int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        scanf("%lld", &favors[i]);
    }
    long double minDev;
    for(int k=K; k<=N; k++){
        vector<long double> devs;
        for(int i=0; i<=N-k; i++){
            devs.push_back(K_dev(favors, i, k, K_avg(favors, i, k)));
            // printf("dev %Lf\n", devs[i]);
        }
        if(k==K){
            minDev = *min_element(devs.begin(), devs.end());
        }else
            minDev = min(minDev, *min_element(devs.begin(), devs.end()));
        // printf("min devs %Lf\n", *min_element(devs.begin(), devs.end()));
    }
    printf("%.10Lf\n", minDev);

    return 0;
}