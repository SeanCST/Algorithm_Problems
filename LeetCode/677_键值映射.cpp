
/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

struct TrieNode {
    TrieNode *child[26];
    // bool isKey;
    int value;
    TrieNode() {
        // isKey = false;
        value = 0;
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }  
    ~TrieNode() {
        for(auto& c : child) {
            delete c;
        }
    }
};

class MapSum {
    TrieNode *t;
public:
    /** Initialize your data structure here. */
    MapSum() {
        t = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode *node = t;
        for(char c : key) {
            if(!node->child[c - 'a']) {
                node->child[c - 'a'] = new TrieNode();
            }
            node = node->child[c - 'a'];
        }
        // t->isKey = true;
        node->value = val;
    }
    
    int sum(string prefix) {
        TrieNode *node = t;
        for(char c : prefix) {
            if(!node->child[c - 'a']) {
                return 0;
            } else {
                node = node->child[c - 'a'];
            }
        }
        
        return sumOfNode(node);
    }

    int sumOfNode(TrieNode *node) {
        int sum = 0;
        sum += node->value;
        for(TrieNode *n : node->child) {
            if(n != NULL) {
                sum += sumOfNode(n);
            }
        }
        return sum;
    }
};


 
struct TrieNode {
    bool isWord;
    int value;
    vector<TrieNode *> child;
    
    TrieNode() : isWord(false), value(0), child(26, nullptr) {}
    ~TrieNode() {
        for(auto& c : child) {
            delete c;
        }
    }
};


class MapSum {
private:
    TrieNode *root;
    
    int sumOfNode(TrieNode *node) {
        int res = 0;
        if(node == NULL) return 0;
        if(node->isWord) res += node->value;
        for(TrieNode *cNode : node->child) {
            if(cNode != NULL)
                res += sumOfNode(cNode);
        }
        
        return res;
    }
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode *node = root;
        for(char c : key) {
            int i = c - 'a';
            if(!node->child[i]) {
                node->child[i] = new TrieNode();
            }
            node = node->child[i];
        }
        node->isWord = true;
        node->value = val;
    }
    
    int sum(string prefix) {
        TrieNode *node = root;
        for(char c : prefix) {
            int i = c - 'a';
            if(!node->child[i]) {
                return 0;
            }
            node = node->child[i];
        }
        return sumOfNode(node);
    }
};
