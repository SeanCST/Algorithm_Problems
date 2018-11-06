/* https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384 */
#include<iostream>
#include<string>
using namespace std;

int main() {
    string s; // 数字太大，只有将其当做字符输入
    int sum = 0;
    cin >> s; 
    
    string str[10] =  {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    for(int i = 0; i < s.length(); i++) {
      sum += (s[i] - '0');
    }
    
    string res = to_string(sum);
    for(int i = 0; i < res.length(); i++) {
        if(i != 0)
            cout << " ";
        cout << str[res[i] - '0'];
    }
}
