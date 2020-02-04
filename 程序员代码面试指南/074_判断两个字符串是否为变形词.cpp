#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isDeformation(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    if(len1 != len2) {
        return false;
    }
    
    map<char, int> m;
    for(int i = 0; i < len1; i++) {
        m[s1[i]]++;
    }
    
    for(int i = 0; i < len2; i++) {
        if(m[s2[i]]-- == 0) {
            return false;
        } 
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    
    if(isDeformation(s1, s2)) {
        cout << "true";
    } else {
        cout << "false";
    }
    
    return 0;
}