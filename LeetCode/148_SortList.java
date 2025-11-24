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
    public ListNode sortList(ListNode head) {
        ListNode node = head;
        int len = 0, intv = 1;
        while (node != null) {
            node = node.next;
            ++len;
        }
        ListNode dummyHead = new ListNode(0, head);
        while (intv < len) {
            ListNode pre = dummyHead;
            node = dummyHead.next;
            while (node != null) {
                int i = intv;
                ListNode h1 = node;
                while (i > 0 && node != null) {
                    i--;
                    node = node.next;
                }
                if (i > 0) {
                    break;
                }
                i = intv;
                ListNode h2 = node;
                while (i > 0 && node != null) {
                    i--;
                    node = node.next;
                }
                // length of `h2` can be small than the `intv`
                int c1 = intv, c2 = intv - i;
                // merge h1 and h2
                while (c1 > 0 && c2 > 0) {
                    if (h1.val < h2.val) {
                        pre.next = h1;
                        h1 = h1.next;
                        --c1;
                    } else {
                        pre.next = h2;
                        h2 = h2.next;
                        --c2;
                    }
                    pre = pre.next;
                }
                pre.next = c1 > 0 ? h1 : h2;
                while (c1 > 0 || c2 > 0) {
                    pre = pre.next;
                    --c1;
                    --c2;
                }
                pre.next = node;
            }

            intv *= 2;
        }

        return dummyHead.next;
    }
}


// class Solution {
//     public ListNode sortList(ListNode head) {
//         if (head == null || head.next == null) {
//             return head;
//         }

//         ListNode fast = head.next, slow = head;
//         while (fast != null && fast.next != null) {
//             slow = slow.next;
//             fast = fast.next.next;
//         }
//         ListNode tmp = slow.next;
//         slow.next = null;
        
//         ListNode left = sortList(head);
//         ListNode right = sortList(tmp);

//         ListNode dummyHead = new ListNode(0);
//         ListNode node = dummyHead;
//         while (left != null && right != null) {
//             if (left.val < right.val) {
//                 node.next = left;
//                 left = left.next;
//             } else {
//                 node.next = right;
//                 right = right.next;
//             }
//             node = node.next;
//         }

//         node.next = left != null ? left : right;

//         return dummyHead.next;
//     }
// }