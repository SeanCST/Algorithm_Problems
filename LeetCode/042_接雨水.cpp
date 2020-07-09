
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) {
            return 0;
        }
        
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        for(int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i - 1]); // 左边最大值
        }
        for(int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i + 1]); // 右边最大值
        }

        int res = 0;
        for(int i = 1; i < n - 1; i++) {
            res += max(0, min(left[i], right[i]) - height[i]);
        }

        return res;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) {
            return 0;
        }
        int res = 0;
        int highestIndex = 0, secondHighIndex = -1;
        int left = 0, right = 0; // 双指针
        int i = 1;
        while(highestIndex < n - 1) {
            if(height[i] < height[highestIndex]) { // 遇到了小于左指针的，直接入栈
                if(secondHighIndex == -1 || height[secondHighIndex] < height[i]) {
                    secondHighIndex = i;
                }
                right = i;
                i++;
                
                if (i == n) { // 到了末尾，遇到的还是比左指针高小的，pop 到倒数第二高，然后计算左指针到倒数第二高之间的容量
                    while(right > secondHighIndex) {
                        right--;
                    }
                    int highest = height[secondHighIndex];
                    while(right > left) {
                        int h = height[right];
                        res += highest - h;
                        right--;
                    }
                    left = secondHighIndex;
                    highestIndex = secondHighIndex;
                    i = secondHighIndex + 1;
                    secondHighIndex = -1;
                }
            }  else { // 遇到了高度大于等于左指针的，计算这之间的容量
                int highest = height[highestIndex];
                while(right > left) {
                    int h = height[right];
                    right--;
                    res += highest - h;
                }
                left = i;
                highestIndex = i;
                i++;
                secondHighIndex = -1;
            }
        }

        return res;
    }
};