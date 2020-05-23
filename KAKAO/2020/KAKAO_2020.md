1번, 2번 문제는 시간만 들이면 푸는 문제였음.

그래도 한번에 패스 못하는 건 조금 아쉬움...

3번 문제는 처음에는 N-queen 같이 푸는 걸로 가닥을 잡았었는데, 뭔가 visit 체크하기도 너무 힘들어서 테크 블로그의 풀이를 봤음.
``` cpp
#define MAT vector<vector<int>>
unordered_map<MAT, bool> visit;
```
으로 visit를 하려고 했으나 실패...

그래도 구현이 정말 어마어마 했음...

확실히 **행렬**처리하는 문제를 내는 느낌임!!

이번에 확실히 행렬 같은 거 처리할 때는 `MAT` 자료형을 정의해두는게 훨씬훨씬 편리한 듯 ㅎㅎ

```cpp
#define MAT vector<vector<int>>;
#define ROW vector<int>
```



