class Solution {
    public List<Integer> diffWaysToCompute(String expression) {
        List<Integer> res = new ArrayList<>();
        if(!expression.contains("+") && !expression.contains("-") && !expression.contains("*")) {
            res.add(Integer.valueOf(expression));
            return res;
        }

        for(int i = 0; i < expression.length(); i++) {
            if(expression.charAt(i) == '+' || expression.charAt(i) == '-' || expression.charAt(i) == '*') {
                List<Integer> leftRes = diffWaysToCompute(expression.substring(0, i));
                List<Integer> rightRes = diffWaysToCompute(expression.substring(i + 1, expression.length()));
                for(Integer left : leftRes) {
                    for(Integer right : rightRes) {
                        if(expression.charAt(i) == '+') {
                            res.add(left + right);
                        } else if(expression.charAt(i) == '-') {
                            res.add(left - right);
                        } else if(expression.charAt(i) == '*') {
                            res.add(left * right);
                        }
                    }
                }
            }
        }

        return res;
    }
}

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