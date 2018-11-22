/* https://pintia.cn/problem-sets/994805260223102976/problems/994805312417021952 */

#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  long long A, B, C;
  for (int i = 0; i < T; i++) {
    cin >> A >> B >> C;
    cout << "Case #" << i + 1 << ": ";
    if(A + B > C)
      cout << "true";
    else
      cout << "false";
    if(i != T - 1)
      cout << endl;
  }
}