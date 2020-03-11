class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        map<char, int> last_map;
        // 记录每个字符最后出现的位置
        for(int i = 0; i < S.length(); i++) {
            last_map[S[i]] = i;
        }
        

        for(int start = 0; start < S.length(); start++) {
            int last = last_map[S[start]]; // 本段首字符的最后出现的位置
            // 若本段中某字符最后出现的位置大于首字符最后出现的位置，则更新最后位置
            for(int i = start; i < last; i++) { 
                if(last_map[S[i]] > last)
                    last = last_map[S[i]];
            }
            res.push_back(last - start + 1); // 本段长度
            start = last; // 更新下一段首字符位置
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        
        map<char, int> lastAppearIndex; // 记录最后出现的位置
        for(int i = 0; i < S.length(); i++) {
            lastAppearIndex[S[i]] = i;
        }

        int curLeft = 0, curRight = 0;
        for(int i = 0; i < S.length(); i++) {
            if(lastAppearIndex[S[i]] > curRight) {
                curRight = lastAppearIndex[S[i]];
            } 
            if(i == curRight) {
                res.push_back(curRight - curLeft + 1);
                curLeft = i + 1;
            }
        }

        return res;
    }
};