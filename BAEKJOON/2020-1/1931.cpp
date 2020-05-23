#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    pair<int, int>* end_start = (pair<int, int>*)malloc((N+1)*sizeof(pair<int, int>));
    for(int i=0; i<N;i ++){
        scanf("%d %d", &end_start[i].second, &end_start[i].first);
    }
    sort(end_start, end_start+N);
    int cnt = 1;
    int latest = end_start[0].first;
    for(int i=1; i<N; i++){
        if(latest <= end_start[i].first){
            if(latest <= end_start[i].second){
                latest = end_start[i].first;
                cnt += 1;
            }
        }
    }

    printf("%d\n", cnt);
    
    return 0;
}