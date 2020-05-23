#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool complete_test(string s){
    int cnt = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(')
            cnt += 1;
        else
            cnt -= 1;
        if(cnt < 0)
            return false;
    }
    return true;
}

string reverted_string(string s){
    string n = "";
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(')
            n += ")";
        else
            n += "(";
    }
    return n;
}

string solution(string p) {
    if(p.length() == 0 || complete_test(p))
        return p;
    string u, v;
    int cnt = 0;
    for(int i=0; i<p.length(); i++){
        if(p[i] == '(')
            cnt += 1;
        else 
            cnt -= 1;
        if(cnt == 0){
            u = p.substr(0, i+1);
            v = p.substr(i, p.length());
            break;
        }
    }
    string u = p.substr(0, 2);
    string v = p.substr(2, p.length());
    
    if(complete_test(u)){
        return u + solution(v);
    }else{
        cout << "here" << endl;
        string n = "(";
        n += solution(v);
        cout << n << endl;
        n += ")";
        n += reverted_string(u.substr(1, u.length() - 2));
        return n;
    }    
}