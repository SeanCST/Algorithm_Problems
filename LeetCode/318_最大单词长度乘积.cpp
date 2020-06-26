class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size() <= 1) {
            return 0;
        }

        vector<int> bitWords;
        for(string word : words) {
            int x = 0;
            for(char c : word) {
                int k = c - 'a';
                x |= 1 << k;
            }
            bitWords.push_back(x);
        }

        int res = 0;
        for(int i = 0; i < words.size() - 1; i++) {
            for(int j = i + 1; j < words.size(); j++) {
                if((bitWords[i] & bitWords[j]) == 0) {
                    int mult = words[i].length() * words[j].length();
                    res = max(res, mult);
                }
            }
        }

        return res;
    }
};