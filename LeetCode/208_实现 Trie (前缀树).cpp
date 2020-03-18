class Trie {
    Trie *child[26];
    bool isWord;
public:
    /** Initialize your data structure here. */
    Trie() {
        isWord = false;
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *t = this;
        for(char c : word) {
            if(!t->child[c - 'a']) {
                t->child[c - 'a'] = new Trie();
            }
            t = t->child[c - 'a'];
        }
        t->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *t = this;
        for(char c : word) {
            if(!t->child[c - 'a']) {
                return false;
            } else {
                t = t->child[c - 'a'];
            }
        }
        return t->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *t = this;
        for(char c : prefix) {
            if(!t->child[c - 'a']) {
                return false;
            } else {
                t = t->child[c - 'a'];
            }
        }
        return true;
    }
};


struct TrieNode {
    bool isWord;
    vector<TrieNode *> child;
    
    TrieNode() : isWord(false), child(26, nullptr) {}
    ~TrieNode() {
        for(auto& c : child) {
            delete c;
        }
    }
};

class Trie {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for(char c : word) {
            int i = c - 'a';
            if(!p->child[i]) 
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for (char c : word) {
            int i = c - 'a';
            if(!p->child[i])
                return false;
            p = p->child[i];
        }
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (char c : prefix) {
            int i = c - 'a';
            if(!p->child[i])
                return false;
            p = p->child[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */