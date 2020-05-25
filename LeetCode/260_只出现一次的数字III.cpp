class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x_or = 0;
        // 对所有元素进行异或，则结果为两个只出现一次的元素的异或结果
        for(int num : nums) {
            x_or ^= num;
        }

        // 找到 x_or 右边起第一个不为 0 的那一位
        int k = 1;
        while((x_or & k) == 0) {
            k <<= 1;
        } 

        int res1 = 0, res2 = 0;
        for(int num : nums) {
            if(num & k) {
                res1 ^= num;
            } else {
                res2 ^= num;
            }
        }

        return {res1, res2};
    }
};