/*
1) insert(“WORD”): Insert the string “WORD”  into this “TRIE” data structure.
2) countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this “TRIE”.
3) countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.
4) erase(“WORD”): Delete one occurrence of the string “WORD” from the “TRIE”.
Note: If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.
*/
class TrieNode{
    public:
    TrieNode* links[26];
    int prefix = 0;
    int isEnd = 0;
};
class Trie{
    TrieNode* root;
    public:

    Trie(){
        root = new TrieNode();
    }

    void insert(string &word){
        TrieNode* node = root;
        for(char& c: word){
            if(!node->links[c - 'a']){
                node->links[c - 'a'] = new TrieNode();
            }
            node = node->links[c - 'a'];
            node->prefix++;
        }
        node->isEnd++;
    }

    int countWordsEqualTo(string &word){
        TrieNode* node = root;
        for(char& c: word){
            if(!node->links[c - 'a']) return 0;
            node = node->links[c -  'a'];
        }
        return node->isEnd;
    }

    int countWordsStartingWith(string &word){
        TrieNode* node = root;
        for(char& c: word){
            if(!node->links[c - 'a']) return 0;
            node = node->links[c - 'a'];
        }
        return node->prefix;
    }

    void erase(string &word){
        TrieNode* node = root;
        for(char& c: word){
            node = node->links[c - 'a'];
            node->prefix--;
        }
        node->isEnd--;
    }
};
