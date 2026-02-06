struct DoublyLinkedNode {
    int key;
    int val;
    DoublyLinkedNode *pre;
    DoublyLinkedNode *next;

    DoublyLinkedNode(int k, int x) : key(k), val(x), pre(NULL), next(NULL) {}
};

class LRUCache {
    int capa;
    map<int, DoublyLinkedNode *> m;
    DoublyLinkedNode *head;
    DoublyLinkedNode *tail;
public:
    LRUCache(int capacity) {
        capa = capacity;
        head = new DoublyLinkedNode(-2, -2);
        tail = new DoublyLinkedNode(-3, -3);
    }
    
    int get(int key) {
        if(m.empty() || m.find(key) == m.end()) {
            return -1;
        } else {
            DoublyLinkedNode *node = m[key];
            moveNodeToHead(node);
            return node->val;
        }
    }
    
    void put(int key, int value) {
        if(m.empty()) { // empty
            DoublyLinkedNode *node = new DoublyLinkedNode(key, value);
            m[key] = node;
            head->next = node;
            node->pre = head;
            node->next = tail;
            tail->pre = node;
        } else {
            DoublyLinkedNode *node;
            if(m.find(key) != m.end()) { // existed
                node = m[key];
                node->val = value;
            } else { // not existed
                node = new DoublyLinkedNode(key, value);
                m[key] = node;

                if(m.size() > capa) { // remove last node
                    DoublyLinkedNode *lastNode = tail->pre;
                    lastNode->pre->next = tail;
                    tail->pre = lastNode->pre;

                    int lastKey = lastNode->key;
                    m.erase(lastKey);
                    delete(lastNode);
                }
            }
            moveNodeToHead(node);
        }
    }

    void moveNodeToHead(DoublyLinkedNode *node) {
        if(node->pre != head) {
            if(node->pre != NULL) {
                node->pre->next = node->next;
            }
            if(node->next != NULL) {
                node->next->pre = node->pre;
            }

            node->next = head->next;
            node->pre = head;
            head->next->pre = node;
            head->next = node;
        } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */