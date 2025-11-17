/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode smallerNode = new ListNode(-200);
        ListNode smallerDummyHead = smallerNode;
        ListNode largerNode = new ListNode(-200);
        ListNode largerDummyHead = largerNode;
        ListNode curNode = head;
        while (curNode != null) {
            if (curNode.val < x) {
                smallerNode.next = curNode;
                smallerNode = smallerNode.next;
            } else {
                largerNode.next = curNode;
                largerNode = largerNode.next;
            }
            curNode = curNode.next;
        }
        
        largerNode.next = null;
        smallerNode.next = largerDummyHead.next;
        return smallerDummyHead.next;
    }
}