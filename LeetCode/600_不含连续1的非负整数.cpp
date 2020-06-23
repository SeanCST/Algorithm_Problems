class Solution {
public:
    int findIntegers(int num) {
        if(num <= 2) {
            return num + 1;
        }

        string numBinary = bitset<32>(num).to_string();
        int i = 0;
        while(numBinary[i] == 0) {
            i++;
        }
        numBinary = numBinary.substr(i);
        // reverse(numBinary.begin(), numBinary.end());
        int len = numBinary.length();

        vector<int> dp(len, 0);
        dp[0] = 1;
        dp[1] = 2;
        
        for(i = 2; i < len; i++) {
            // dp[i] 表示所有 i 位数字中可以包含的不含连续1的数字的个数
            // 如 dp[3] 表示 000 ~ 111 中包含的不含连续1的数字的个数
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int res = 0;
        for(i = 0; i < len; i++) {
            if(numBinary[i] == '1'){
                res += dp[len - i - 1];
                if(i > 0 && numBinary[i - 1] == '1') { 
                    // 遇到两个连续的1，则以他两为开头的数中不可能会有不含连续1的数字了，直接 return
                    return res;
                }
            }
        }

        res++; // 加上自身
        return res;
    }
};