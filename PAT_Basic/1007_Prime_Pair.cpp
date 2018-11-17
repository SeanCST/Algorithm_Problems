#include <iostream>
using namespace std;

bool isPrime(int n) {
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
    if(isPrime(i - 2) && isPrime(i))
      count++;
  }
  
  cout << count;
  return 0;
}