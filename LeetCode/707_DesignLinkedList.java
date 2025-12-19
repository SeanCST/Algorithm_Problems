class MyLinkedList {
    private static class Node {
        int val;
        Node next;

        Node() {}
        Node(int _val) { val = _val; }
    }

    private Node dummyHead;

    public MyLinkedList() {
        dummyHead = new Node();
    }
    
    public int get(int index) {
        Node pre = findNthNodePre(index);
        if (pre == null || pre.next == null) {
            return -1;
        }
        return pre.next.val;
    }
    
    public void addAtHead(int val) {
        Node node = new Node(val);
        node.next = dummyHead.next;
        dummyHead.next = node;
    }
    
    public void addAtTail(int val) {
        Node node = new Node(val);
        Node cur = dummyHead;
        while (cur.next != null) {
            cur = cur.next;
        }
        cur.next = node;
    }
    
    public void addAtIndex(int index, int val) {
        Node pre = findNthNodePre(index);
        if (pre == null) {
            return;
        }
        Node node = new Node(val);
        node.next = pre.next;
        pre.next = node;
    }
    
    public void deleteAtIndex(int index) {
        Node pre = findNthNodePre(index);
        if (pre == null || pre.next == null) {
            return;
        }
        Node deleteNode = pre.next;
        pre.next = deleteNode.next;
        deleteNode.next = null;
    }

    private Node findNthNodePre(int n) {
        if (n < 0) {
            return null;
        }
        Node node = dummyHead;
        while (n-- > 0) {
            node = node.next;
            if (node == null) {
                return node;
            }
        }

        return node;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */