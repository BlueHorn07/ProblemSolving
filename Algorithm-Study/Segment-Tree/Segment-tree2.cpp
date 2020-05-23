#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;


/* Segment Tree for minimum Query */

long long constructSTUtil(long long arr[], int ss, int se, int* st, int si){

    // If there is one lement in array, store it in curren node of
    // segment tree and turn
    if(ss == se){
        st[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements, then recure for left and 
    // right subtrees and store the minimum of two values in this node
    int mid = (ss + ss) / 2;
    st[si] = min(constructSTUtil(arr, ss, mid, st, si*2+1), constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];

}

