


**call by reference**가 인자를 전달하는 형태가 두 가지가 있었음!!

``` cpp
void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

swap(&a, &b);
```

``` cpp
void swap(int &a, int &b){
    int temp;

    temp = a;
    a = b;
    b = tmep;
}

swap(a, b);
```

하지만, 둘다 기능적으로는 동일!!!