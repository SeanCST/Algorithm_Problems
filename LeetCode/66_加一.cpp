class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for(int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + 1 == 10) { // 要进位
                digits[i] = 0;
                if (i == 0) { // 最高位要进位
                    digits.insert(digits.begin(), 1);
                }
                
            } else { // 不用进位
                digits[i] += 1;
                return digits;
            }
        }

        return digits;
    }
};