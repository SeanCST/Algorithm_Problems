#include <iostream>
#include <string>

using namespace std;

bool isRotation(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    if(len1 != len2) {
        return false;
    }
    
    string dup = s1 + s1;
    if(dup.find(s2) == string::npos) { // 不存在
        return false;
    } else {
        return true;
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    
    if(isRotation(s1, s2)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}