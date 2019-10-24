class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 1, size = nums.size();
        while(right < size) {
            if(nums[left] == 0) { // left 数据 需要交换
                if(nums[right] != 0) { // right 数据满足交换条件
                    swap(nums[left], nums[right]);
                } else { // right 数据不满足交换条件，找到满足为止
                    right++;
                }
            } else { // left 数据 不需要交换
                left++;
                right = left + 1;
            }
        }
    }
};

/* 更好的方法 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int num : nums) {
            if(num != 0) {
                nums[idx++] = num;
            }
        }

        while(idx < nums.size()) {
            nums[idx++] = 0;
        }
    }
};