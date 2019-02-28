class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;  // 小顶堆, 默认 lesser 为大顶堆
        
        for(int item : nums) { // 遍历数组
            pq.push(item);  // 依次对各个数入小顶堆
            // 若小顶堆内元素数目超过 k，则 pop 掉堆顶元素（已经小于目前最大的 k 个元素了），
            // 保留目前为止的最大的 k 个数
            if(pq.size() > k)  
                pq.pop();
        }
        // 返回堆顶元素，堆内元素为第 1~k 大的元素，堆顶元素为第 k 大的元素
        return pq.top(); 
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int j = Partition(nums, l, r);
            if(k == j)
                break;
            else if (j < k) 
                l = j + 1;
            else
                r = j - 1;
        }
        
        return nums[k];
    }
    
    int Partition(vector<int>& nums, int l, int r) {
        int i = l - 1;
        // nums[l...i] 值小于等于 nums[r]
        // nums[i+1...j-1] 值大于 nums[r]
        // nums[j...r-1] 值不确定
        for(int j = l; j < r; j++) {
            if(nums[j] < nums[r]) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[i+1], nums[r]);
        return i + 1;
    }
};