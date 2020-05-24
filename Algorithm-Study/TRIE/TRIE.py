import sys

class TRIE:
    # 배열이 아니라 dict으로 각 알파벳을 관리!
    head = {}
    def __init__(self):
        self.head = {}

    def add(self, word):
        cur = self.head

        for ch in word:
            if ch not in cur:
                cur[ch] = {}
            cur = cur[ch]
        cur['*'] = True

    def search(self, word):
        cur = self.head
        for ch in word:
            if ch not in cur:
                if '*' in cur:
                    return True
                return False
            else:
                cur = cur[ch]
        if '*' in cur:
            return True
        else:
            if len(cur) != 0:
                return True
            else:
                return False
    def size_print(self):
        print("+++++++ size is ", len(self.head))

if __name__ == "__main__":
    T = int(sys.stdin.readline().rstrip())

    for t in range(T):
        Trie = TRIE()
        N = int(sys.stdin.readline().rstrip())
        isConsistent = True
        for i in range(N):
            word = list(sys.stdin.readline().rstrip())
            if(isConsistent):
                if(Trie.search(word)):
                    isConsistent = False
                else:
                    Trie.add(word)

        if(isConsistent):
            print("YES")
        else:
            print("NO")
