/* https://pintia.cn/problem-sets/994805342720868352/problems/994805526272000000 */

// #include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 数据
    int KA = 0, KB = 0, maxExp = 0, tempExp = 0, num = 0;
    float coe_A[1001] = {0}, coe_B[1001] = {0}, coe_Sum[1001] = {0}; // A 系数， B 系数
    
    // 输入
    cin >> KA;
    // scanf("%d", &KA);
    for(int i = 0; i < KA; i++) {
        cin >> tempExp;
        // scanf("%d", &tempExp);
        if (maxExp < tempExp) {
            maxExp = tempExp;
        }
        
        cin >> coe_A[tempExp];
        // scanf("%f", &coe_A[tempExp]);
    }
    cin >> KB;
    // scanf("%d", &KB);
    for(int i = 0; i < KB; i++) {
        cin >> tempExp;
        // scanf("%d", &tempExp);
        if (maxExp < tempExp) {
            maxExp = tempExp;
        }
        
        cin >> coe_B[tempExp];
        // scanf("%f", &coe_B[tempExp]);
    }
    
    
    // 处理
    for (int i = 0; i <= maxExp; i++) {
        coe_Sum[i] = coe_A[i] + coe_B[i];
        if (coe_Sum[i] != 0) {
            num ++; // 计算不为0的一共有多少项
        }
    }
    
    // 输出
    cout << num;
    // printf("%d", num);
    for (int i = maxExp; i >= 0; i--) {
        if (coe_Sum[i] != 0) {
            cout << " " << i << " " << setprecision(1) << fixed << coe_Sum[i];
            // printf(" %d %.1f", i, coe_Sum[i]);
        }
    }
    
    return 0;
}
