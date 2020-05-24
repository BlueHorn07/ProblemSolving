#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

#define TrieNode 10

struct Trie{
    Trie* next[TrieNode]; // 다음 노드를 가리키는 포인터 '배열'
    bool finish; // 이 노드에서 끝나게 되는 전화번호가 있는가!! (오!)
    bool nextChild; // 이 노드에게 자식이 있는가? <- 일관성 테스트를 위해 필요

    Trie(){
        fill(next, next + TrieNode, nullptr);
        finish = nextChild = false;
    }

    // 포인터 배열을 쓰기 때문에 꼭 할당해제 작업이 필요함!!!
    ~Trie(){
        for(int i=0; i<TrieNode; i++){
            if(next[i])
                delete next[i];
        }
    }

    // 문자열 key를 삽입
    bool insert(const char* key){
        if(*key == '\0'){
            finish = true;

            // 만약 문자열이 \0로 끝났는데도 
            // 자식이 있다면, 일관성 없는 것!!
            if(nextChild)
                return false;
            else
                return true;
        }

        // 인덱스 범위로 변환
        int nextKey = *key - '0';
        
        // 만약 해당 인덱스에 처음 접근하는 거라면?
        // = 해당 인덱스에 sub-trie가 없다면?
        if(!next[nextKey]){
            next[nextKey] = new Trie;
        }
        // new로 자식 trie를 하나 할당했으니까!
        nextChild = true;

        // 여기까지 왔다는 것은 트라이의 자식이 있다는 말!!
        // 이때 자식에서 일관성이 없는 것이 밝힌다면?
        // 'key+1'의 의미는 char 배열에서 한칸 앞으로 간다는 말!!
        bool get = next[nextKey]->insert(key+1);

        // 자식 trie가 존재하는데, finish가 참 -> 일관성 X
        return !finish && get;
    }

};


int main(){

    Trie* root = new Trie;

    bool chk = true;

    

    return 0;
}