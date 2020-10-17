class Solution {
public:
    string removeKdigits(string num, int k) {
        for(int i = 0; i < k; i++) {
            int deletePos = num.length() - 1;
            for(int j = 0; j < num.length() - 1; j++) {
                if(num[j] > num[j + 1]) {
                    deletePos = j;
                    break;
                }
            }
            num.erase(deletePos, 1);
            
            if(num.length() > 1 && num[0] == '0') {
                int zeroCounts = 0;
                while(num[zeroCounts] == '0') {
                    zeroCounts++;
                }
                num.erase(0, zeroCounts);
            }
        }

        return num == "" ? "0" : num;
    }
};