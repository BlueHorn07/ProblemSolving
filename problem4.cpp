#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'scatterPalindrome' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY strToEvaluate as parameter.
 */

// fact1 = scatter + scatter = scatter
// Construct Segment tree

#define ALPHABETS 26

bool isScatter(string word, int s, int e){
    int cnt[ALPHABETS] = {0, };
    for(int i=s; i<=e; i++){
        cnt[word[i] - 'a'] += 1;
    }
    bool isOdd = false;
    for(int i=0; i<ALPHABETS; i++){
        if(cnt[i]%2 == 0)
            continue;
        else{
            if(isOdd)
                return false;
            else
                isOdd = true;
        }
    }
    return true;
}

bool Construct(vector<bool> &tree, string word, int node, int s, int e){
    if(s == e)
        return tree[node] = true;
    else if(s + 1 == e){
        cout << "near two" << s << " " << e << " " << (word[s] == word[e]) << endl;
        Construct(tree, word, node*2, s, s);
        Construct(tree, word, node*2+1, e, e);
        if(word[s] == word[e])
            return tree[node] = true;
        else
            return tree[node] = false;
    }
    else{
        cout << "general" << s << " " << e << endl;
        int mid = (s+e)/2;
        bool left_child = Construct(tree, word, node*2, s, mid);
        bool right_child = Construct(tree, word, node*2+1, mid+1, e);
        if(left_child && right_child){
            return tree[node] = true;
        }else{
            // 직접 scatter 여부 체크
            return tree[node] = isScatter(word, s, e);
        }
    }
}

bool Query(vector<bool> &tree, int node, int s, int e, int l, int r){
    if (l > e || r < s)
        return true;
    if (l <= s && e <= r)
        return tree[node];
    int mid = (s+e)/2;
    bool left_child = Query(tree, node*2, s, mid, l, r);
    bool right_child = Query(tree, node*2+1, mid+1, e, l, r);

    return (left_child && right_child);
}

vector<int> scatterPalindrome(vector<string> strToEvaluate) {
    vector<int> result;


    for(int i=0; i < (int)strToEvaluate.size(); i++){
        cout << strToEvaluate[i] << endl;

        string word = strToEvaluate[i];
        int word_size = (int)word.size();
        
        int h = (int)ceil(log2(word_size));
        int tree_size = (1 << (h+1));
        vector<bool> tree;
        tree.assign(tree_size, false);

        Construct(tree, word, 1, 0, word_size-1);
        for(int t = 0; t < tree_size; t++){
            printf("%d\n", (int)tree[t]);
        }
        int cnt = 0;
        for(int j=0; j < word_size; j++){
            for(int k=j; k < word_size; k++){
                if(j + 1 == k){
                    if(isScatter(word, j, k)){
                        cnt += 1;
                    }
                }
                else if(Query(tree, 1, 0, word_size - 1, j, k)){
                    // cout << "query test" << j << " " << k << endl;
                    cnt += 1;
                }else{
                    isScatter(word, j, k);
                }
            }
        }
        result.push_back(cnt);
    }


    return result;
}

int main()