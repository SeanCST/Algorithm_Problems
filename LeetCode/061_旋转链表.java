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
    public ListNode rotateRight(ListNode head, int k) {
        int len = 0;
        ListNode node = head;
        ListNode tail = null;
        while(node != null) {
            len++;
            if(node.next == null) {
                tail = node;
            }
            node = node.next;
        }

        if(k == 0 || len == 0 || k % len == 0) {
            return head;
        }
        k %= len;
        

        int forward = len - k;
        node = head;
        while(--forward > 0) {
            node = node.next;
        }

        ListNode res = node.next;
        node.next = null;
        tail.next = head;

        return res;
    }
}