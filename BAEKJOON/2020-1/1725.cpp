#include<cstdio>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>

using namespace std;

int main(){
    while(1){
        vector<tuple<int, int, long long>> lines; // l, r, y

        int n;
        scanf("%d", &n);
        if(n==0){
            break;
        }
        for(int i=0; i<n; i++){
            long long y;
            scanf("%lld", &y);
            lines.push_back(make_tuple(i, i+1, y));
        }

        long long max_area = 0;
        for(int i=0; i<n; i++){
            int rightmost = n, leftmost = 0;
            long long y_value = get<2>(lines[i]);
            // go to right
            if(y_value != 0){
                if(y_value * n > max_area){
                    for(int j=i+1; j<n; j++){
                        if(get<2>(lines[j]) < y_value){
                            //printf("right: smaller than me! %d\n", j);
                            rightmost = get<0>(lines[j]);
                            break;
                        }
                    }
                    if(y_value * (rightmost - leftmost) > max_area){
                        for(int j=i-1; j>=0; j--){
                            if(get<2>(lines[j]) < y_value){
                                // printf("left: smaller than me! %d\n", j);
                                leftmost = get<1>(lines[j]);
                                break;
                            }
                        }
                    }else{
                        continue;
                    }
                }
                else {
                    continue;
                }
            }else{
                continue;
            }
            

            max_area = max(max_area, (long long)(y_value * (rightmost - leftmost)));
            // printf("%d area : %lld\n", i, area);

        }
        printf("%lld\n", max_area);
    }
    

    return 0;
}