/* https://pintia.cn/problem-sets/994805260223102976/problems/994805309963354112 */
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {
    for(int i = 2; i * i <= num; i++)
        if(num % i == 0)
            return false;
    
    return true;
}

int main() {
    int M, N;
    cin >> M >> N;
    int count = 0;
    vector <int> res;
    
    for(int i = 2; count <= N; i++)
        if(isPrime(i)) {
            count ++;
            res.push_back(i);
        }
    
    count = 0;
    for(int i = M - 1; i < N; i++) {
        cout << res[i];
        count ++;
        if(i != N -1) {
            if(count % 10 != 0)
                cout << " ";
            else
                cout << endl;
        }
        
    }
}
