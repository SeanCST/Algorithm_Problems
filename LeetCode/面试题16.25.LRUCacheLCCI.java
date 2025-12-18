import java.util.HashMap;
import java.util.Map;

class LRUCache {

    class DoublyLinkedNode {
        int key;
        int value;
        DoublyLinkedNode pre;
        DoublyLinkedNode next;
        
        DoublyLinkedNode() {}
        DoublyLinkedNode(int _key, int _value) { key = _key; value = _value; }
    }

    private Map<Integer, DoublyLinkedNode> map;
    private DoublyLinkedNode head;
    private DoublyLinkedNode tail;
    private int capacity;

    public LRUCache(int capacity) {
        map = new HashMap<>();
        head = new DoublyLinkedNode();
        tail = new DoublyLinkedNode();
        head.next = tail;
        tail.pre = head;
        this.capacity = capacity;
    }
    
    public int get(int key) {
        DoublyLinkedNode node = map.get(key);
        if (node == null) {
            return -1;
        }
        moveToHead(node);

        return node.value;
    }
    
    public void put(int key, int value) {
        DoublyLinkedNode node = map.get(key);
        if (node == null) {
            node = new DoublyLinkedNode(key, value);
            if (map.size() == capacity) {
                map.remove(tail.pre.key);
                removeNode(tail.pre);
            }
            map.put(key, node);
            putToHead(node);
        } else {
            node.value = value;
            moveToHead(node);
        }
    }

    private void removeNode(DoublyLinkedNode node) {
        node.next.pre = node.pre;
        node.pre.next = node.next;
    }

    private void putToHead(DoublyLinkedNode node) {
        node.next = head.next;
        head.next.pre = node;
        head.next = node;
        node.pre = head;
    }

    private void moveToHead(DoublyLinkedNode node) {
        removeNode(node);
        putToHead(node);
    }

}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */