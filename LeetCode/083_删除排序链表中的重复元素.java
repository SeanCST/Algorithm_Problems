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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode pNode = head;
        while(pNode != null) {
            ListNode cur = pNode.next;
            while(cur != null && cur.val == pNode.val) {
                cur = cur.next;
            }
            pNode.next = cur;
            pNode = pNode.next;
        }

        return head;
    }
}