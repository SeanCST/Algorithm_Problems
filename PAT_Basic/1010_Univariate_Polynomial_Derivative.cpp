/* https://pintia.cn/problem-sets/994805260223102976/problems/994805313708867584 */

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  int coefficient, exponent; // 系数，指数
  int flag = 0;
  
  while(scanf("%d%d", &coefficient, &exponent) != EOF) {
    
    if(exponent > 0) {
      if(flag) cout << " ";
      cout << coefficient * exponent; // 求导后的系数
      cout << " " << exponent - 1; // 求导后的指数
      flag = 1;
    } else {
      break;
    }
    
  }
  
  if(flag == 0)
    cout << "0 0";
    
  return 0;
}