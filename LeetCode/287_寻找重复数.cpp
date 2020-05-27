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
        在 fast 和 slow 第一次相遇的时候，假定 slow 走了 n 步，环路的入口是在 p 步，那么
          slow 走的路径： p + c ＝ n； c 为 fast 和 slow 相交点 距离环路入口的距离
          fast 走的路径： p + c + k * L = 2 * n； L 为环路的周长，k 是整数
          显然，如果从 p + c 点开始，slow 再走 n 步的话，还可以回到 p + c 这个点
          同时，fast 从头开始走，步长为 1，经过 n 步，也会达到 p + c 这点
          显然，在这个过程中 fast 和 slow 只有前 p 步骤走的路径不同。所以当 p1 和 p2 再次重合的时候，必然是在链表的环路入口点上。
        */

        return slow;
    }
};