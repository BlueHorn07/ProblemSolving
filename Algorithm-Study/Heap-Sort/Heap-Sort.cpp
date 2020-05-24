// 참고자료: https://gmlwjd9405.github.io/2018/05/10/algorithm-heap-sort.html

#include<cstdio>

#define NMAX 10

struct Elt {
    int key;
};

struct HeapType{
    Elt heap[NMAX];
    int heap_size;
};

void insert_max_heap()