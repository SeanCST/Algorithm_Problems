#include <iostream>
#include <string>
using namespace std;

// int main() {
//     string s;
//     getline(cin, s);
//     string res = "";
//     for(int i = 0; i < s.length(); i++) {
//         if(s[i] != ' ') {
//             res += s[i];
//         } else {
//             res += "%20";
//         }
//     }
    
//     cout << res;
    
//     return 0;
// }

#define MAX_SIZE 1000001

void Replace(char *str) {
    int spaceCount = 0;
    int len;
    for(len = 0; str[len] != '\0'; len++) {
        if(str[len] == ' ') {
            spaceCount++;
        }
    }

    int j = spaceCount * 2 + len - 1;
    for(int i = len - 1; i >= 0; i--) {
        if(str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = str[i];
        }
    }
}

int main() {
    char str[3 * MAX_SIZE];
    char ch;
    int i = 0;
    while((ch = getchar()) != EOF && ch != '\n') {
        str[i++] = ch;
    }
    str[i] = '\0';
    
    Replace(str);
    cout << str;
    
    return 0;
}