class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        
        for(int i = 0; i < d.size(); i++) {
            string curr = d[i]; // 当前待检查的字符串
            if(res.length() <= curr.length()) { // 只有已匹配成功的长度小于当前字符串长度时才判断当前字符串
                int s_index = 0, curr_index = 0;
                while(s_index < s.length() && curr_index < curr.length()) {
                    if(s[s_index] == curr[curr_index]) {
                        curr_index++;
                    }
                    s_index++;
                }
                if(curr_index == curr.length()) { // 经检查后能匹配
                    // 长度不同，结果为更长的
                    // 长度相同，结果为字典靠前的
                    if(res.length() < curr.length() || curr < res) { 
                        res = curr;
                    }
                }
            }
        }
        
        return res;
    }
};