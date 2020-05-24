// 참고자료: https://twpower.github.io/187-trie-concept-and-basic-problem

#include<cstdio>
#include<cstring>

#define ALPHABETS 26

using namespace std;

// Convert char to array index
// All are base on capital

int char_to_index(char c){

}

struct Trie {
    bool is_terminal;
    Trie* childern[ALPHABETS];

    // Constructor
    Trie(): is_terminal(false){
        memset(childern, 0, sizeof(childern));
    }

    ~Trie(){
        for(int i=0; i<ALPHABETS; i++){
            if(childern[i])
                delete childern[i];
        }
    }

    void insert(const char* key){
        if(*key == '\0')
            is_terminal = true;
        else{

        }
    }
};
