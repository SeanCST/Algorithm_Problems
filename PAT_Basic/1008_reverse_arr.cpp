/* https://pintia.cn/problem-sets/994805260223102976/problems/994805316250615808 */

// 不改变数组本身
#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    int arr[100], ROR = N - (M % N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if(i > ROR)
            cout << " ";
        if(i >= ROR)
            cout << arr[i];
    }
    
    for(int i = 0; i < ROR; i++)
        if(i == 0 && (M == 0 || ROR == N))
            cout << arr[i];
        else
            cout << " " << arr[i];
    
    
    return 0;
}

// 改变数组本身

// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     m %= n;
    
//     if (m != 0) {
//         reverse(a.begin(), a.begin() + m);
//         reverse(a.begin() + m + 1, a.end());
//         reverse(a.begin(), a.end());
//     }
    
//     for (int i = 0; i < n - 1; i++)
//         cout << a[i] << " ";
//     cout << a[n - 1];
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    m %= n;
    if (m != 0) {
        reverse(begin(a), begin(a) + n);
        reverse(begin(a), begin(a) + m);
        reverse(begin(a) + m, begin(a) + n);
    }
    for (int i = 0; i < n - 1; i++)
        cout << a[i] << " ";
    cout << a[n - 1];
    return 0;
}
