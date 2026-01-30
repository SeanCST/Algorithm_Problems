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

// class Solution {
//     public ListNode reverseList(ListNode head) {
//         ListNode dummyHead = new ListNode();
//         ListNode node = head;
//         while (node != null) {
//             ListNode next = node.next;
//             node.next = dummyHead.next;
//             dummyHead.next = node;
//             node = next;
//         }

//         return dummyHead.next;
//     }
// }

class Solution {
    public ListNode reverseList(ListNode head) {
        return reverse(head, null);
    }

    private ListNode reverse(ListNode node, ListNode pre) {
        if (node == null) {
            return pre;
        }

        ListNode next = node.next;
        node.next = pre;
        return reverse(next, node);
    }
}