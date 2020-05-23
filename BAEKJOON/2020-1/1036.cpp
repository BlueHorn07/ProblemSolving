#include<cstdio>
#include <cctype>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define MAX 50

using namespace std;

bool isGreater_36(string s1, string s2){ // true: s1 > s2
    if (s1.size() > s2.size())
        return true;
    else if (s1.size() < s2.size())
        return false;

    // both string has same size
    for(int i=0; i<s1.size(); i++){
        int c1 = toupper(s1[i]);
        int c2 = toupper(s2[i]);
        if( c1 > c2 )
            return true;
        else if( c1 < c2 )
            return false;
    }
    return false; // exactly same!
}

string add_36(string s1, string s2){
    // adjust to s1 >= s2
    if(s1.size() < s2.size())
        swap(s1, s2);
    if (s2.size() == 0)
        return s1;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string sum_36; // 0: LSB -> lenfth: MSB
    int carry = 0;
    for(int i=0; i<s2.size(); i++){
        int c1 = toupper(s1[i]);
        int c2 = toupper(s2[i]);
        c1 >= 'A' ? c1 -= 55 : c1 -= 48;
        c2 >= 'A' ? c2 -= 55 : c2 -= 48;
        int sum = c1 + c2 + carry;
        carry = 0;
        if(sum >= 36) {
            carry = 1;
            sum -= 36;
        }
        sum >= 10 ? sum += 55 : sum += 48;
        sum_36.push_back(char(sum));
    }

    for(int j=s2.size(); j<s1.size(); j++){
        int c1 = toupper(s1[j]);
        c1 >= 'A' ? c1 -= 55 : c1 -= 48;
        int sum = c1 + carry;
        carry = 0;
        if(sum >= 36){
            carry = 1;
            sum -= 36;
        }
        sum >= 10 ? sum += 55 : sum += 48;
        sum_36.push_back(char(sum));
    }
    if(carry == 1)
        sum_36.push_back('1');
    reverse(sum_36.begin(), sum_36.end());
    return sum_36;
}

string OneConverted(string s1, char c){
    for(int i=0; i<s1.length(); i++){
        if(s1[i] == c){
            s1[i] = 'Z';
        }
    }
    return s1;
}

vector<pair<string, int>> Merge(vector<pair<string, int>> left, vector<pair<string, int>> right){
    vector<pair<string, int>> merged;
    int i = 0;
    int j = 0;
    while(i < left.size() && j < right.size()){
        if(isGreater_36(left[i].first, right[j].first)){
            merged.push_back(left[i]);
            i++;
        }
        else{
            merged.push_back(right[j]);
            j++;
        }
    }
    for(;i<left.size(); i++){
        merged.push_back(left[i]);
    }
    for(;j<right.size(); j++){
        merged.push_back(right[j]);
    }

    return merged;
} 

vector<pair<string, int>> MergeSort(vector<pair<string, int>> v){
    if(v.size() <= 1)
        return v;
    int mid = v.size() / 2;

    vector<pair<string, int>> left = MergeSort(vector<pair<string, int>>(v.begin(), v.begin() + mid));
    vector<pair<string, int>> right = MergeSort(vector<pair<string, int>>(v.begin() + mid, v.end()));
    return Merge(left, right);
}


vector<string> nums;
vector<pair<string, int>> Converted;

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        char tmp[MAX+1];
        scanf("%s", tmp);
        nums.push_back(string(tmp));
    }
    int K;
    scanf("%d", &K);

    // convert test for all 36 numbers from 0 to Z
     for(int i=0; i<36; i++){
        string OneConvertedSum = "0";
        for(int j=0; j<N; j++){
            if(i < 10){
                OneConvertedSum = add_36(OneConvertedSum, OneConverted(nums[j], i+48));
            }else{
                OneConvertedSum = add_36(OneConvertedSum, OneConverted(nums[j], i+55));
            }
        }
        Converted.push_back(make_pair(OneConvertedSum, i));
    }

    vector<pair<string, int>> Sorted = MergeSort(Converted);

    for(int k=0; k < K; k++){
        for(int i=0; i<N; i++){
            if(Sorted[k].second < 10){
                nums[i] = OneConverted(nums[i], Sorted[k].second + 48);
            }else{
                nums[i] = OneConverted(nums[i], Sorted[k].second + 55);
            }
        }
    }

    string result;
    for(int i=0; i<N; i++){
        result = add_36(result, nums[i]);
    }
    cout << result << endl;

    return 0;
}
