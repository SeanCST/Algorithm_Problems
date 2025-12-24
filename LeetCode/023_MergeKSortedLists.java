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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) {
            return null;
        }
        PriorityQueue<ListNode> pq = new PriorityQueue<>(lists.length, 
            (node1, node2) -> Integer.compare(node1.val, node2.val));

        for (ListNode list : lists) {
            if (list != null) {
                pq.offer(list);
            }
        }
        ListNode dummyHead = new ListNode();
        ListNode cur = dummyHead;
        while (!pq.isEmpty()) {
            ListNode list = pq.poll();
            cur.next = list;
            cur = cur.next;
            if (list.next != null) {
                pq.offer(list.next);
            }
        }

        return dummyHead.next;
    }
}