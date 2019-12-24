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