#include<cstdio>
#include<algorithm>
#include<list>
#include<vector>

using namespace std;

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    list<int> lst;
    for(int i=0; i<N; i++){
        lst.push_back(i);
    }
    vector<int> result;

    printf("<");
    list<int>::iterator curr = lst.begin();
    while(!lst.empty()){
        int step = (K % lst.size()) - 1;
        if(step == -1){
            step = K - 1;
            if(lst.size() != 1)
                printf("%d, ", *curr + 1);
            else
                printf("%d", *curr + 1);
            curr = lst.end();
            curr--;
            curr = lst.erase(curr);
            continue;

        }
        for(int i=0; i<step; i++){
            if(next(curr) != lst.end()){
                curr++;
            }else{
                curr = lst.begin();
            }
        }
        if(lst.size() != 1)
            printf("%d, ", *curr + 1);
        else
            printf("%d", *curr + 1);
            
        
        if(next(curr) != lst.end())
            curr = lst.erase(curr);
        else{
            lst.erase(curr);
            curr = lst.begin();
        }
    }
    printf(">\n");

    return 0;
}