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
    public void reorderList(ListNode head) {
        ListNode fast = head, slow = head;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }

        ListNode reverse = slow.next;
        slow.next = null;

        ListNode reverseHead = null;
        while (reverse != null) {
            ListNode next = reverse.next;
            reverse.next = reverseHead;
            reverseHead = reverse;
            reverse = next;
        }

        ListNode tail = null;
        while (head != null) {
            if (tail != null) {
                tail.next = head;
            }
            ListNode next = head.next;
            ListNode reverseNext = reverseHead == null ? null : reverseHead.next;
            head.next = reverseHead;
            tail = reverseHead;
            head = next;
            reverseHead = reverseNext;
        }
    }
}