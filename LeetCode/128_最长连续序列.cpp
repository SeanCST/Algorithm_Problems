class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> m;
        int maxLength = 0;

        for(int num : nums) {
            if(m.find(num) == m.end()) {
                int left = m.find(num - 1) == m.end() ? 0 : m[num - 1];
                int right = m.find(num + 1) == m.end() ? 0 : m[num + 1];

                int curLength = 1 + left + right;
                maxLength = curLength > maxLength ? curLength : maxLength;

                m[num] = curLength;
                m[num - left] = curLength;
                m[num + right] = curLength;
            }
        }

        return maxLength;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> m;
        for(int num : nums) {
            m[num] = 1;
        }

        for(int num : nums) {
           forward(m, num);
        }

        return maxCount(m);
    }
private:
    int forward(map<int, int>& m, int num) {
        if (m.find(num) == m.end()) { // 不包含
            return 0;
        }
        int cnt = m[num];
        if(cnt > 1) {
            return cnt;
        }
        cnt = forward(m, num + 1) + 1;
        m[num] = cnt;
        return cnt;
    }
    
    int maxCount(map<int, int> m) {
        int res = 0;
        map<int, int>::iterator iter = m.begin();
        while(iter != m.end()) {
            res = max(res, iter->second);
            iter++;
        }

        return res;
    }
};