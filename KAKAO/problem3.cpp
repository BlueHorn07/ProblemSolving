#include <bits/stdc++.h>
#include <ext/aligned_buffer.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'scatterPalindrome' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY strToEvaluate as parameter.
 */

// scatter + scatter = scatter
// 오직 substring 문자의 even or odd만 중요하다.
// DP?
// substring을 어떻게 나누지?
// O(n^3)은 절대 아님.


#define ALPHABETS 26

void printArr(vector<bool> arr){
    for(int i=0; i<(int)arr.size(); i++){
        printf("%d ", (int)arr[i]);
    }
    printf("\n");
}

bool isScatter(vector<bool> isOdd){
    bool isOddExist = false;
    for(int i=0; i<ALPHABETS; i++){
        if(isOdd[i]){
            if(isOddExist)
                return false;
            isOddExist = true;
        }
    }
    return true; 
}

// input: isOdd bool arrary
vector<bool> getSubStrIsOdd(vector<bool> isOddArr1, vector<bool> isOddArr2){
    vector<bool> SubStrIsOdd(ALPHABETS, false);
    for(int i=0; i<ALPHABETS; i++){
        // (1, 1), (0, 0) -> continue
        if(isOddArr1[i]!=isOddArr2[i])
            SubStrIsOdd[i] = true;
    }
    // printArr(SubStrIsOdd);
    return SubStrIsOdd;
}

vector<bool> makeIsOddArr(string s){
    vector<bool> IsOddArr(ALPHABETS, false);
    for(int i=0; i<(int)s.size(); i++){
        if(IsOddArr[s[i] - 'a'])
            IsOddArr[s[i] - 'a'] = false;
        else
            IsOddArr[s[i] - 'a'] = true;
    }
    return IsOddArr;
}

vector<int> scatterPalindrome(vector<string> strToEvaluate) {
    vector<int> result;

    for(int t=0; t<(int)strToEvaluate.size(); t++){

        string word = strToEvaluate[t];
        int word_length = (int)word.size();

        vector<vector<bool>> IsOddArrForSubstr;
        IsOddArrForSubstr.push_back(vector<bool>(ALPHABETS, false));
        // growing prefix
        for(int i=1; i<=word_length; i++){
            // printArr(makeIsOddArr(word.substr(0, i)));
            IsOddArrForSubstr.push_back(makeIsOddArr(word.substr(0, i)));
        }
        vector<bool> SubStrIsScatter(word_length, false);
        for(int i=0; i<=word_length; i++){
            if(isScatter(IsOddArrForSubstr[i]))
                SubStrIsScatter[i] = true;
            printf("i %d: %d ", i, int(SubStrIsScatter[i]));
        }

        int cnt = 0;
        for(int i=1; i<=word_length; i++){
            for(int j=i; j<=word_length; j++){
                if(i==j)
                    cnt += 1;
                else if(SubStrIsScatter[i-1] && SubStrIsScatter[j])
                    cnt += 1;
                else if(isScatter(getSubStrIsOdd(IsOddArrForSubstr[i-1], IsOddArrForSubstr[j])))
                    cnt += 1;
                // printf("i %d, j %d cnt %d\n", i, j, cnt);
            }
        }
        result.push_back(cnt);
    }
    return result;
}

int main()