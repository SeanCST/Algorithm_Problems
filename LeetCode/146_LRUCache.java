class LRUCache {
    private static class DLinkedNode {
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