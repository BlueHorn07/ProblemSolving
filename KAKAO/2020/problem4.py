class TRIE:
    head = {}

    def __init__(self):
        self.head = {}
    
    def add(self, word):
        curr = self.head
        for ch in word:
            if ch not in curr:
                curr[ch] = {}
            curr = curr[ch]
        curr['*'] = {}

    def search(self, word, head = None):
        curr = head
        if(head == None):
            curr = self.head
        
        if(not word):
            return list(curr.keys()).count('*')
        
        cnt = 0
        for idx in range(len(word)):
            ch = word[idx]
            if ch == '?':
                for key in list(curr.keys()):
                    cnt += self.search(word[idx+1:], curr[key])
                return cnt
            if ch not in curr:
                return 0
            curr = curr[ch]

        return 1

    def printSize(self):
        print(len(self.head))

def solution(words, queries):
    answer = []

    Trie = TRIE()

    for word in words:
        word = list(word)

        Trie.add(word)
    
    for query in queries:
        query = list(query)
        answer.append(Trie.search(query))
    return answer