#include <iostream>
using namespace std;

#define MAX_SIZE 1000001

void Replace(char *str) {
    int len;
    for(len = 0; str[len] != '\0'; len++) {
        len++;
    }
    int j = len - 1;
    for(int i = len - 1; i >= 0; i--) {
        if(str[i] != '*') {
            str[j--] = str[i];
        }
    }

    while (j >= 0) {
        str[j--] = '*';
    }
}

int main() {
    char str[MAX_SIZE];
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