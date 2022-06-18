/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
    public Node insert(Node head, int insertVal) {
        Node insertNode = new Node(insertVal);
        if(head == null) {
            insertNode.next = insertNode;
            return insertNode;
        }

        Node node = head;
        boolean headVisited = false;
        while(node != head || !headVisited) {
            if(node == head) {
                headVisited = true;
            }
            if((node.val <= insertVal && node.next.val >= insertVal) || 
                (node.next.val < node.val && node.val <= insertVal 
                                      && node.next.val <= insertVal) ||
                (node.next.val < node.val && node.val >= insertVal 
                                      && node.next.val >= insertVal)
            ) {
                insertNode.next = node.next;
                node.next = insertNode;
                return head;
            }
            node = node.next;
        }
        
        insertNode.next = node.next;
        node.next = insertNode;

        return head;
    }
}