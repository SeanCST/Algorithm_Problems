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
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k <= 1) {
            return head;
        }

        ListNode dummy = new ListNode(0, head);
        ListNode prevGroupTail = dummy;

        while (true) {
            ListNode kth = prevGroupTail;
            for (int i = 0; i < k && kth != null; i++) {
                kth = kth.next;
            }
            if (kth == null) {
                break;
            }

            ListNode nextGroupHead = kth.next;
            ListNode prev = nextGroupHead, cur = prevGroupTail.next;
            while (cur != nextGroupHead) {
                ListNode next = cur.next;
                cur.next = prev;
                prev = cur;
                cur = next;
            }

            ListNode newHead = prev;
            ListNode newTail = prevGroupTail.next;

            prevGroupTail.next = newHead;
            prevGroupTail = newTail;
        }

        return dummy.next;
    }
}

// class Solution {
//     public ListNode reverseKGroup(ListNode head, int k) {
//         if (head == null || k <= 1) {
//             return head;
//         }

//         ListNode tail = head;
//         int cnt = k;
//         while (tail != null && --cnt > 0) {
//             tail = tail.next;
//         }
//         if (cnt > 0) {
//             return head;
//         }

//         ListNode cur = head, tailNext = tail.next, prev = null;
//         while (cur != tailNext) {
//             ListNode next = cur.next;
//             cur.next = prev;
//             prev = cur;
//             cur = next;
//         }
        
//         head.next = reverseKGroup(tailNext, k);
//         return prev;
//     }
// }