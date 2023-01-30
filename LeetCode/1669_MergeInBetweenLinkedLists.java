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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode cur = list1;
        for(int i = 1; i < a; i++) {
            cur = cur.next;
        }
        ListNode remove = cur.next;
        cur.next = list2;
        while(cur.next != null) {
            cur = cur.next;
        }
        for(int i = a; i <= b; i++) {
            remove = remove.next;
        }
        cur.next = remove;

        return list1;
    }
}