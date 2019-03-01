class Solution {
public:
    string frequencySort(string s) {
        string res;
        // 计数
        map<char, int> m;
        for(char c : s) {
            m[c]++;
        }
        
        // 使用桶来装具有相同频率的字符串
        vector<vector<char>> bucket(s.length() + 1);
        map<char, int>::iterator iter = m.begin();
        while(iter != m.end()) {
            bucket[iter->second].push_back(iter->first);
            iter++;
        }
        
        for(int i = s.length(); i >= 0; i--) {
            if(!bucket[i].empty()) { // 存在出现频率为该频率的字符
                for(char c : bucket[i]) {
                    for(int j = 0; j < i; j++) 
                       res += c;
                }
            }
        }
        
        return res;
    }
};