/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast = head, slow = head;
        ListNode meet = null;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                meet = slow;
                break;
            }
        }

        ListNode res = null;
        if (meet != null) {
            res = head;
            while (slow != res) {
                slow = slow.next;
                res = res.next;
            }
        }

        return res;
    }
}