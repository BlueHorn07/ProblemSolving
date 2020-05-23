#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = INT_MAX;
    for(int k=1; k<=s.length()/2; k++){
        vector<string> chunks;
        for(int i=0; i<s.length(); i+=k){
            chunks.push_back(s.substr(i, k));
        }
        int cnt = 1;
        string result;
        for(int i=0; i < chunks.size() - 1; i++){
            if(chunks[i].compare(chunks[i+1]) == 0){
                cnt += 1;
            }else{ // IF different
                if(cnt!=1)
                    result.append(to_string(cnt));
                result.append(chunks[i]);
                cnt = 1;
            }
        }
        if(cnt!=1)
            result.append(to_string(cnt));
        result.append(chunks[chunks.size() - 1]);
        if (answer)
        answer = min(answer, (int) result.size());
    }
    return answer;
}