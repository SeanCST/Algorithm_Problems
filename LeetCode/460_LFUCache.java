class LFUCache {
    private static class DoublyLinkedNode {
        int key;
        int value;
        int freq;
        DoublyLinkedNode pre;
        DoublyLinkedNode next;

        DoublyLinkedNode() {}
        DoublyLinkedNode(int _key, int _value, int _freq) { key = _key; value = _value; freq = _freq; }
    }

    private static class DoublyLinkedList {
        DoublyLinkedNode head;
        DoublyLinkedNode tail;

        DoublyLinkedList() {
            head = new DoublyLinkedNode();
            tail = new DoublyLinkedNode();
            head.next = tail;
            tail.pre = head;
        }

        public void putToHead(DoublyLinkedNode node) {
            node.pre = head;
            node.next = head.next;
            head.next = node;
            node.next.pre = node;
        }

        public DoublyLinkedNode removeLast() {
            return removeNode(tail.pre);
        }

        public DoublyLinkedNode removeNode(DoublyLinkedNode node) {
            node.pre.next = node.next;
            node.next.pre = node.pre;
            return node;
        }

        public boolean isEmpty() {
            return head.next == tail;
        }
    }

    private Map<Integer, DoublyLinkedNode> cacheMap;
    private Map<Integer, DoublyLinkedList> freqMap;
    private int capacity;
    private int minFreq;

    public LFUCache(int capacity) {
        cacheMap = new HashMap<>();
        freqMap = new HashMap<>();
        this.capacity = capacity;
        minFreq = 1;
    }
    
    public int get(int key) {
        DoublyLinkedNode node = cacheMap.get(key);
        if (node == null) {
            return -1;
        }
        moveNode(node);

        return node.value;          
    }
    
    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        DoublyLinkedNode node = cacheMap.get(key);
        if (node == null) {
            if (cacheMap.size() == capacity) {
                DoublyLinkedList list = freqMap.get(minFreq);
                DoublyLinkedNode removed = list.removeLast();
                cacheMap.remove(removed.key);
                if (list.isEmpty()) {
                    freqMap.remove(minFreq);
                }
            }

            node = new DoublyLinkedNode(key, value, 1);
            cacheMap.put(key, node);
            insertNode(node);
            minFreq = 1;
        } else {
            moveNode(node);
            node.value = value;
        }
    }

    private void moveNode(DoublyLinkedNode node) {
        DoublyLinkedList list = freqMap.get(node.freq);
        list.removeNode(node);
        if (list.isEmpty()) {
            freqMap.remove(node.freq);
            if (node.freq == minFreq) {
                minFreq++;
            }
        }                
        node.freq++;
        insertNode(node);
    }

    private void insertNode(DoublyLinkedNode node) {
        DoublyLinkedList list = freqMap.get(node.freq);
        if (list == null) {
            list = new DoublyLinkedList();
            freqMap.put(node.freq, list);
        }
        list.putToHead(node);
    }

}

/**
    * Your LFUCache object will be instantiated and called as such:
    * LFUCache obj = new LFUCache(capacity);
    * int param_1 = obj.get(key);
    * obj.put(key,value);
    */