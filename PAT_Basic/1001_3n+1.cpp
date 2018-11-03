/* https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528 */


#include <iostream>
using namespace std;

int main() {
  // 输入
  int n;
  cin >> n;
  
  int count = 0;
  while(n != 1) {
    if(n % 2 == 0) // 偶数
      n /= 2;
    else // 奇数
      n = (3 * n + 1) / 2 ;
      
    count ++;
  }
  
  cout << count;
}