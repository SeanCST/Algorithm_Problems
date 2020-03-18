class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
    
    int mergeSort(vector<int>& nums, int left, int right) {
        int pairsCount = 0;
        if(left >= right) {
            return pairsCount;
        }
        
        // 分治
        int mid = left + (right - left) / 2;
        pairsCount += mergeSort(nums, left, mid); // left...mid 有序
        pairsCount += mergeSort(nums, mid + 1, right); // mid+1...right 有序
        
        // 使用两个数组分别装入
        int len1 = mid - left + 1;
        int len2 = right - mid;
        vector<int> leftNums(len1 + 1, 0);
        for(int i = 0; i < len1; i++) {
            leftNums[i] = nums[left + i];
        }
        leftNums[len1] = INT_MAX;
        vector<int> rightNums(len2 + 1, 0);
        for(int i = 0; i < len2; i++) {
            rightNums[i] = nums[mid + 1 + i];
        }
        rightNums[len2] = INT_MAX;
        
        // 合并
        int i1 = 0, i2 = 0, i = left;
        while(i1 <= len1 && i2 <= len2 && i <= right) {
            if(leftNums[i1] <= rightNums[i2]) {
                nums[i++] = leftNums[i1++];
            } else {
                nums[i++] = rightNums[i2++];
                pairsCount += len1 - i1;
            }
        }
        
        return pairsCount;
    }
};