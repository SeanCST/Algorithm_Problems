class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int res = 0;
        // i 指向饼干尺寸,j 指向各小孩的胃口值
        for(int i = 0, j = 0; i < s.size() && j < g.size(); i++) { 
            if(s[i] >= g[j]) {
                res++;
                j++;
            }
        }
        
        return res;
    }
};