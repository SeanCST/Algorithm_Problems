/* https://pintia.cn/problem-sets/994805260223102976/problems/994805317546655744 */
#include <iostream>
using namespace std;

bool isPrime(int n) {
  // 测试n是否为素数的最基本方法为试除法。将n除以每个大于1且小于等于n的平方根之整数m
  // 若 n = a*b 是个合数（其中a与b ≠ 1），则其中一个约数a或b必定至大为 根号n
  for(int i = 2; i * i <= n; i++) { 
    if(n % i == 0)
      return false;
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  int count = 0;

  for(int i = 5; i <= N; i = i + 2) {
    if(isPrime(i - 2) && isPrime(i)) // 使用 && 在 i-2 不是素数的情况下不需要再计算 i 了，节省时间
      count++;
  }
  
  cout << count;
  return 0;
}