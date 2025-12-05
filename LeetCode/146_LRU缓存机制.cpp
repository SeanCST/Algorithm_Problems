class LRUCache {
    class DLinkedNode {
        int key;
        int value;
        DLinkedNode pre;
        DLinkedNode next;

        public DLinkedNode() {}
        public DLinkedNode(int _key, int _value) { key = _key; value = _value; }
    }

    private Map<Integer, DLinkedNode> map;
    private DLinkedNode head;
    private DLinkedNode tail;
    private int capacity;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>();
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head.next = tail;
        tail.pre = head;
    }
    
    public int get(int key) {
        DLinkedNode node = map.get(key);
        if (node == null) {
            return -1;
        }
        moveToHead(node);

        return node.value;
    }
    
    public void put(int key, int value) {
        DLinkedNode node = map.get(key);
        if (node == null) {
            node = new DLinkedNode(key, value);
            addToHead(node);
            map.put(key, node);

            if (map.size() > capacity) {
                DLinkedNode last = tail.pre;
                removeNode(last);
                map.remove(last.key);
            }
        } else {
            node.value = value;
            moveToHead(node);
        }
    }

    private void removeNode(DLinkedNode node) {
        node.pre.next = node.next;
        node.next.pre = node.pre;
    }

    private void addToHead(DLinkedNode node) {
        node.pre = head;
        node.next = head.next;
        head.next.pre = node;
        head.next = node;
    }

    private void moveToHead(DLinkedNode node) {
        removeNode(node);
        addToHead(node);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

 

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