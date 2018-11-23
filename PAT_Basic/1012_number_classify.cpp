/* https://pintia.cn/problem-sets/994805260223102976/problems/994805311146147840 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    int N, n, remainder;
    int A1 = 0, A2 = 0, A3 = 0, A4_count = 0, A5 = 0;
    float A4_sum = 0;
    bool plusOrMinus = true, hasA2 = false;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n;
        remainder = n % 5;
        switch(remainder) {
            case 0: {
                if(n % 2 == 0)
                    A1 += n;
                break;
            }
            case 1: {
                if(plusOrMinus)
                    A2 += n;
                else
                    A2 -= n;
                plusOrMinus = !plusOrMinus;
                hasA2 = true;
                break;
            }
            case 2: {
                A3++;
                break;
            }
            case 3: {
                A4_sum += n;
                A4_count++;
                break;
            }
            case 4: {
                if(n > A5)
                    A5 = n;
                break;
            }
            default:
                break;
        }
    }
    
    if(A1 > 0)
        cout << A1 << " ";
    else
        cout << "N ";
    
    if(hasA2)
        cout << A2 << " ";
    else
        cout << "N ";
    
    if(A3 > 0)
        cout << A3 << " ";
    else
        cout << "N ";
    
    if(A4_count > 0)
        cout << fixed << setprecision(1) << A4_sum / A4_count << " ";
    else
        cout << "N ";
    
    if(A5 > 0)
        cout << A5;
    else
        cout << "N";
    
    return 0;
}
