## TRIE

[여기](https://twpower.github.io/187-trie-concept-and-basic-problem)의 자료를 참고하였다.

처음에는 `python`으로 TRIE를 짰는데, 뭔가 python이라 그런지 런타임에서 손해를 많이 보는 것 같다.

그래서 C++로 다시 TRIE를 공부했다.

역시 명작은 여러번!!

[링크](https://www.crocus.co.kr/1053)



C++에서
`const char* word`랑 `string word`랑 뭔가 쓰는 테크닉이 좀 다른 것 같음!

C++에서의 TRIE는 확실히 구조체 만들어서 하는게 제일 좋을 듯!!
단,
- 자식 Trie 포인터 배열
- 소멸자에서 할당 해제 `delete`

이 두 가지는 정말 TRIE를 쓸 때, 기본이 되는 아이디어인 것 같다!!