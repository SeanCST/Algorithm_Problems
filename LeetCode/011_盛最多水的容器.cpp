class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        while(left < right) {
            int area = (right - left) * min(height[left], height[right]);
            if(area >= res) res = area;
            if(height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        
        return res;
    }
};