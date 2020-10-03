class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int n = strs.size();

        map<string, int> m;
        int k = 0;
        for(int i = 0; i < n; i++) {
            string tempStr = strs[i];
            sort(tempStr.begin(), tempStr.end());
            
            if(m.find(tempStr) != m.end()) {
                vector<string> tempGroup = res[m[tempStr]];
                tempGroup.push_back(strs[i]);
                res[m[tempStr]] = tempGroup;
            } else {
                vector<string> tempGroup;
                tempGroup.push_back(strs[i]);
                res.push_back(tempGroup);
                m[tempStr] = k++;
            }
        }

        return res;
    }
};