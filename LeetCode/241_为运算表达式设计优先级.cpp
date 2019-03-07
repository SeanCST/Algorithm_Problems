class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        
        for(int i = 0; i < input.size() - 1; i++) {
            char c = input[i];
            if(c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for(int l : left) {
                    for(int r : right) {
                        switch(c) {
                            case '+' : {
                                res.push_back(l + r);
                                break;
                            }
                            case '-' : {
                                res.push_back(l - r);
                                break;
                            }
                            case '*' : {
                                res.push_back(l * r);
                                break;
                            }
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