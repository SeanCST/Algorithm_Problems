class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        /*
        在fast和slow第一次相遇的时候，假定slow走了n步，环路的入口是在p步，那么
           slow走的路径： p+c ＝ n； c为fast和slow相交点 距离环路入口的距离

           fast走的路径： p+c+k*L = 2*n； L为环路的周长，k是整数

          显然，如果从p+c点开始，slow再走n步的话，还可以回到p+c这个点。

          同时，fast从头开始走，步长为1，经过n步，也会达到p+c这点。

          显然，在这个过程中fast和slow只有前p步骤走的路径不同。所以当p1和p2再次重合的时候，必然是在链表的环路入口点上。
        */
        return slow;
    }
};