class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;

        for(int i = 0; i < input.length(); i++) {
            char c = input[i];
            if(c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for(auto l : left) {
                    for(auto r : right) {
                        if(c == '+') {
                            res.push_back(l + r);
                        } else if(c == '-') {
                            res.push_back(l - r);
                        } else {
                            res.push_back(l * r);
                        }
                    }
                }
            }
        }

        if(res.empty()) {
            res.push_back(stoi(input));
        }

        return res;
    }
};