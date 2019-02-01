class Solution {
public:
    string countAndSay(int n) {
        string res = to_string(1);
        for(int i = 1; i < n; i++)
        {
            int count = 1;
            string temp_res = "";
            for(int j = 1; j < res.length(); j++)
            {
                if(res[j] == res[j - 1]) {
                    count++;
                } else if(res[j] != res[j - 1]) {
                    temp_res += to_string(count);
                    temp_res += res.substr(j - 1, 1);
                    count = 1;
                }
            }
            // 处理最后一个元素
            temp_res += to_string(count);
            temp_res += res.substr(res.length() - 1, 1);

            res = temp_res;
        }
        
        return res;
    }
};