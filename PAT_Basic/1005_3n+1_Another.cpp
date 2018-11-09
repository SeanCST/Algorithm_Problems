/* https://pintia.cn/problem-sets/994805260223102976/problems/994805320306507776 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10000]; // 记录有没有验证过

bool cmp(int a, int b) {return a > b;}

int main() {
  int k, n, flag = 0;
  cin >> k;
  vector<int> v(k); // 保存输入的数
  
  for(int i = 0; i < k; i++) {
    cin >> n;
    v[i] = n;
    
    while(n != 1) {
      if(n % 2 == 1) // 是奇数
        n = n * 3 + 1;
        
      n /= 2;
      
      if(arr[n] == 1) // 之前已经验证过了
        break;
      arr[n] = 1; // 记录下途中验证到的数，标记为已验证
    }
  }
  sort(v.begin(), v.end(), cmp);
  for(int i = 0; i < v.size(); i++) {
    if(arr[v[i]] == 0) {
      if(flag == 1) // 第一个数前面不输入空格，后面的数前面都输入空格
        cout << " ";
      cout << v[i];
      flag = 1;
    }
  }
  
  return 0;
}