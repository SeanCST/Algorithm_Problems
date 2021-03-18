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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy;

        for(int i = 1; i < left; i++) {
            pre = pre.next;
        }

        head = pre.next;
        for(int i = left; i < right; i++) {
            ListNode nextNode = head.next;
            head.next = nextNode.next;
            nextNode.next = pre.next;
            pre.next = nextNode;
        }

        return dummy.next;
    }
}

class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(left == right) {
            return head;
        }
        int reversedLen = right - left + 1;

        ListNode beforeReverseNode = null;
        ListNode curNode = head;
        for(int i = 1; i < left; i++) {
            beforeReverseNode = curNode;
            curNode = curNode.next;
        }

        ListNode toReverseHead = beforeReverseNode == null ? head : beforeReverseNode.next;
        ArrayList<ListNode> reversedResult = reverse(toReverseHead, reversedLen);
        if(beforeReverseNode != null) {
            beforeReverseNode.next = reversedResult.get(0);
        } else {
            head = reversedResult.get(0);
        }
        toReverseHead.next = reversedResult.get(1);

        return head;
    }

    private ArrayList<ListNode> reverse(ListNode head, int len) {
        int k = 0;
        ListNode reversedHead = null;
        while(k < len) {
            ListNode nextNode = head.next;
            head.next = reversedHead;
            reversedHead = head;
            head = nextNode;

            k++;
        }

        ArrayList<ListNode> res = new ArrayList<ListNode>();
        res.add(reversedHead);
        res.add(head);
        return res;
    }
}