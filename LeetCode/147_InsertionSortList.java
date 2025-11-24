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
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode(Integer.MIN_VALUE);
        ListNode cur = head;
        while (cur != null) {
            ListNode p = dummy;
            ListNode next = cur.next;

            while (p.next != null && p.next.val < cur.val) {
                p = p.next;
            }
            
            cur.next = p.next;
            p.next = cur;

            cur = next;
        }

        return dummy.next;
    }
}