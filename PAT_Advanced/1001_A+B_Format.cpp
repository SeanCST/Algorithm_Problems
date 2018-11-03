/* PAT - 1001 A+B Format （20 分）

Calculate a+b and output the sum in standard format -- that is, 
the digits must be separated into groups of three by commas (unless there are less than four digits).

Input Specification:
Each input file contains one test case. Each case contains a pair of integers a and b where −10^6 ≤ a, b ≤ 10​^6. 
The numbers are separated by a space.

Output Specification:
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input:
-1000000 9

Sample Output:
-999,991 
**/

#include<iostream>
using namespace std;

int main() {
    int num1, num2;
    cin >> num1 >> num2;

    int sum = num1 + num2;
    bool isMinus = sum < 0;
    if(isMinus)
        sum = -sum;

    string s = to_string(sum);
    int length = s.length();
    string res;

    if (length > 3) {
        int n = length % 3;
        if(n > 0) {
            res += s.substr(0, n);
            res += ',';
        }
        
        for(int i = n; i < length; i = i + 3)
        {
            res += s.substr(i, 3);
            res += ',';
        }

        // res = res.substr(0, res.length() - 1);
        res.pop_back();
    }       
    else {
        res = s;
    }    

    if(isMinus)
        res.insert(0, "-");

    cout << res;
    return 0;
}