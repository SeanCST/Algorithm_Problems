/* https://pintia.cn/problem-sets/994805260223102976/problems/994805323154440192 */
#include <iostream>
#include <map>
using namespace std;

// 总结出：aPbTc ：只有 a中'A'的个数 * b中'A'的个数 == c中'A'的个数 时，才正确，且 b中'A'的个数至少为1
int main() {
  int n;
  cin >> n;
  string s;
  
  int pLoc, tLoc;
  
  for(int i = 0; i < n; i++) {
    cin >> s;
    map<char, int> m;
    for(int j = 0; j < s.size(); j++) {
      m[s[j]]++;
      // 记录下 P 和 T 的位置
      if(s[j] == 'P') pLoc = j;
      if(s[j] == 'T') tLoc = j;
    }
    
    /*
      m['P'] == 1 : P 有1个
      m['T'] == 1 : T 有1个
      m['A'] != 0 : A 的个数至少为1个
      m.size() == 3 : 一共只有三个字母
      tLoc - pLoc != 1 : 中间'A'的个数至少为1个
      pLoc * (tLoc - pLoc - 1) == (s.size() - tLoc - 1) : a中'A'的个数 * b中'A'的个数 == c中'A'的个数
    */
    if(m['P'] == 1 && m['T'] == 1 && m['A'] != 0 && m.size() == 3 
    && tLoc - pLoc != 1 && pLoc * (tLoc - pLoc - 1) == (s.size() - tLoc - 1))
      cout << "YES";
    else
      cout << "NO";
    
    if(i < n - 1)
      cout << endl;
  }
  

}