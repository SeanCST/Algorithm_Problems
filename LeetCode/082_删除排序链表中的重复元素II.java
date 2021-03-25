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
        ListNode dummy = new ListNode(-101, head);
        
        ListNode pre = dummy;
        ListNode cur = pre.next;
        while(cur != null && cur.next != null) {
            if(cur.val == cur.next.val) {
                ListNode duplicateNode = cur.next;
                while(duplicateNode != null && cur.val == duplicateNode.val) {
                    duplicateNode = duplicateNode.next;
                }
                pre.next = duplicateNode;
            } else {
                pre = pre.next;
            }
            
            if(pre != null) {
                cur = pre.next;
            } else {
                break;
            }
        }

        return dummy.next;
    }
}