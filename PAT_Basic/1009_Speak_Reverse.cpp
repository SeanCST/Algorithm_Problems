/* https://pintia.cn/problem-sets/994805260223102976/problems/994805314941992960 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    getline(cin, s); // 输入
    
    reverse(s.begin(), s.end());
    int rLeft = 0, rRight = 0;
    for(int i = 1; i < s.length(); i++) {
        if(s[i] == ' ') {
            rRight = i;
            reverse(s.begin() + rLeft, s.begin() + rRight);
            rLeft = rRight + 1;
        }
        
        if(i == s.length() - 1) {
            // rRight = i;
            reverse(s.begin() + rLeft, s.end());
        }
    }
    
    cout << s;
    
    return 0;
}
