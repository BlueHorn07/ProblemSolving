# CPP

Extension 설치를 포함한 초기 세팅은 이 포스트 참조: "[[MacOS] Visual Studio Code로 C/C++ 코딩하기](https://wooono.tistory.com/299)"

`Makefile`을 직접 세팅하려고도 생각해봤는데, 가볍게 하려면 Extension 설치하는게 빠름.

`gcc`, `g++` 설치 확인

```sh
gcc --version
g++ --version
```

## 빌드 단축키

`Command` + `Shift` + `B`

g++ 컴파일 사용할 것

## bits/stdc++.h

Window/Mac 둘다 따로 설정 해둔게 아니면 로컬에서 못 씀...;;

https://1sangcoder.tistory.com/242

나중에 요거 보고 세팅할 것

## 주요 라이브러리

`main.cpp` 현재에는 아래와 같이 `#include` 해둠.

```cpp
#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
```

### cstdio

```cpp
#include <cstdio>
```

`cin >> something`, `cout << something`

### climits

```cpp
#include <climits>
```

`INT_MAX`, `INT_MIN` 같은 것들 쓰기 위해

### vector

```cpp
#include <vector>
```

`vector<T> vec` 자료형 쓰려고

### algorithm

```cpp
#include <algorithm>
```

`find`, `count`, `search`, `swap`, `min`, `max` 등등 많은 것들이 가능


## 종종 쓰는 함수

- `fill_n(arr, N, -1)`
  - `memset()`보다 `fill_n()`을 더 선호

## Online Compiler

- [LeetCode Playground](https://leetcode.com/playground/)

