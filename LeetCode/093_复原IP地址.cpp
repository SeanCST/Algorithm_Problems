class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<vector<string>> res;
        vector<string> cur;

        process(s, res, cur, 4);

        vector<string> ans;
        for(vector<string> r : res) {
            string tmp = "";
            for(int i = 0; i < r.size(); i++) {
                if(tmp.length() > 0) {
                    tmp += ".";
                }
                tmp += r[i];
            }
            ans.push_back(tmp);
        }

        return ans;
    }

    void process(string s, vector<vector<string>>& res, vector<string> cur, int k) {
        int len = s.length();
        if(len > 3 * k || len < k) {
            return;
        } else if(k == 0 && len == 0) {
            res.push_back(cur);
            return;
        }

        int curMaxLen = min(len, 3);
        curMaxLen = s[0] == '0' ? 1 : curMaxLen;
        for(int i = 1; i <= curMaxLen; i++) {
            string sub = s.substr(0, i);
            if(i == 3 && stoi(sub) > 255) {
                break;
            } else {
                cur.push_back(sub);
                process(s.substr(i), res, cur, k - 1);
                cur.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> addresses;
        string tempAddress;
        doRestore(0, tempAddress, addresses, s);
        return addresses;
    }

    void doRestore(int k, string tempAddress, vector<string>& addresses, string s) {
        if(k == 4 || s.length() == 0) {
            if(k == 4 && s.length() == 0) {
                addresses.push_back(tempAddress);
            }
            return;
        }

        for(int i = 0; i <= 2 && i < s.length(); i++) {
            if(i > 0 && s[0] == '0') { // IP 任何长度大于 1 的一小节都不能以 0 开头
                break;
            }
            string part = s.substr(0, i + 1);
            if(stoi(part) <= 255) {
                if(tempAddress.length() > 0) {
                    part = "." + part;
                }
                tempAddress += part;
                doRestore(k + 1, tempAddress, addresses, s.substr(i + 1));
                tempAddress = tempAddress.substr(0, tempAddress.length() - part.length());
            }
        }
    }
};