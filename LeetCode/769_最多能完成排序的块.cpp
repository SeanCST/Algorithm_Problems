class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;

        int curMax = -1;
        for(int i = 0; i < arr.size(); i++) {
            curMax = max(curMax, arr[i]);
            if(curMax == i) {
                res++;
            }
        }

        return res;
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        // int left = 0;
        // int innerCount = 0;
        int innerMax = 0;
        for(int i = 0; i < arr.size(); i++) {
            innerMax = max(innerMax, arr[i]);
            if(innerMax == i) {
                res++;
            }
            // innerCount++;
            // if(innerMax <= i && innerCount == i - left + 1) { // 找到对应区间
            //     res++;
            //     left = i + 1;
            //     innerCount = 0;
            // }
        }

        return res;
    }
};