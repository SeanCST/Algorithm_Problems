/* https://pintia.cn/problem-sets/994805260223102976/problems */

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
 
  int hundred = n / 100;
  for(int i = 0; i < hundred; i++)
    cout << "B";
  n = n - hundred * 100;
  
  int ten = n / 10;
  for(int i = 0; i < ten; i++)
    cout << "S";
  n = n - ten * 10;
  
  for(int i = 0; i < n; i++)
    cout << i + 1;
    
  return 0;
}