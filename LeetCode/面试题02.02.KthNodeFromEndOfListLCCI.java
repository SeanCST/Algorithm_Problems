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
    public int kthToLast(ListNode head, int k) {
        ListNode node1 = head;
        while (k-- > 0) {
            node1 = node1.next;
        }

        ListNode node2 = head;
        while (node1 != null) {
            node1 = node1.next;
            node2 = node2.next;
        }

        return node2.val;
    }
}