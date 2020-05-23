#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string n1, n2;
    cin >> n1 >> n2;

    string result;
    if(n1.length() < n2.length())
        swap(n1, n2);
    
    int carry = 0;
    
    int n1_len = n1.length();
    int n2_len = n2.length();

    for(int i = 0; i < n1_len; i++){
        int N1 = n1.back() - 48;

        if(i < n2_len){
            int N2 = n2.back() - 48;
            int one_result = N1 + N2 + carry;
            if(one_result >= 10)
                carry = 1;
            else
                carry = 0;

            result.push_back(char((one_result)%10 + 48));
            n1.pop_back();
            n2.pop_back();
        }else{
            int one_result = N1 + carry;
            if( one_result >= 10)
                carry = 1;
            else
                carry = 0;
            result.push_back(char(( one_result)%10 + 48));
            n1.pop_back();
        }
    }

    if(carry == 1){
        result.push_back('1');
    }

    reverse(result.begin(), result.end());


    cout << result;
}