#include<cstdio>
#include<vector>
#include<algorithm>

#define NMAX 1001
#define kMAX 51
#define STDMAX 10001

using namespace std;

vector<int> classes[NMAX];

vector<int> STD[STDMAX];

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int k;
        scanf("%d", &k);
        for(int j=0; j<k; j++){
            int tmp;
            scanf("%d", &tmp);
            classes[i].push_back(tmp);
        }
        sort(classes[i].begin(), classes[i].end());

    }

    int M;
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int p;
        scanf("%d", &p);
        for(int j=0; j<p; j++){
            int tmp;
            scanf("%d", &tmp);
            STD[i].push_back(tmp);
        }

        sort(STD[i].begin(), STD[i].end());

    }

    for(int i=0; i<M; i++){
        int cnt = 0;
        for(int j=0; j<N; j++){
            int s_idx = 0, c_idx = 0;
            bool check;
            while(1){
                if(c_idx == classes[j].size()){
                    if(s_idx <= STD[i].size()){
                        check = true;
                    }
                    else{
                        check = false;
                    }
                    break;
                }
                if(s_idx == STD[i].size()){
                    if(c_idx < classes[j].size()){
                        check = false;
                    }
                    else{
                        check = true;
                    }
                    break;
                }
                if(STD[i][s_idx] < classes[j][c_idx]){
                    s_idx += 1;
                }
                else if(STD[i][s_idx] == classes[j][c_idx]){
                    c_idx += 1;
                }else{
                    check = false;
                    break;
                }

            }
            if(check == true){
                cnt += 1;
            }
        }
        printf("%d\n", cnt);

    }
    

    return 0;
}

/*             
int time = STD[i][j];
            if(pair_STD[i].size() == 0){
                pair_STD[i].push_back(make_pair(time, time));
            }
            else if(pair_STD[i][pair_STD[i].size()-1].second + 1 == time){
                pair_STD[i][pair_STD[i].size()-1].second = time;
            }
            else{
                pair_STD[i].push_back(make_pair(time, time));
            }

    pair<int, int> s_pair = pair_STD[i][s_idx];
                pair<int, int> c_pair = pair_classess[j][c_idx];
                if(i==2){
                    printf("idx %d %d %d\n", i, j, cnt);
                    printf("s_pair %d %d\n", s_pair.first, s_pair.second);
                    printf("c_pair %d %d\n", c_pair.first, c_pair.second);
                }
                if(c_idx >= pair_classess[j].size()){
                    if(s_idx < pair_STD[i].size()){
                        check = true;
                    }else{
                        check = false;
                    }
                    break;
                }
                if(s_idx >= pair_STD[i].size()){
                    if(c_idx < pair_classess[j].size()){
                        // still left...
                        check = false;
                    }else{
                        check = true;
                    }
                    break;
                }
                if(s_pair.first <= c_pair.first && c_pair.second <= s_pair.second){
                    c_idx += 1;
                    continue;
                }
                else if(c_pair.first < s_pair.first && s_pair.second < c_pair.second){
                    check = false;
                    break;
                }
                else if(s_pair.first <= c_pair.first && s_pair.second < c_pair.second && c_pair.second < s_pair.second){
                    check = false;
                    break;
                }
                else if(s_pair.second < c_pair.first){
                    s_idx += 1;
                }
                else if(c_pair.second < s_pair.first){
                    check = false;
                    break;
                }
            }
            if(check == false){
                continue;
            }
            else{
                cnt += 1;
            }

        } */