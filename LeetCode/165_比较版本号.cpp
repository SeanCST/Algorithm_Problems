class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> arr1 = versionArrayWithString(version1);
        vector<int> arr2 = versionArrayWithString(version2);

        int size1 = arr1.size(), size2 = arr2.size();
        for(int i = 0; i < size1 && i < size2; i++) {
            if(arr1[i] < arr2[i]) {
                return -1;
            } else if(arr1[i] > arr2[i]) {
                return 1;
            }
        }

        if(size1 < size2) {
            for(int i = size1; i < size2; i++) {
                if(arr2[i] > 0) {
                    return -1;
                }
            }
        } else if(size1 > size2) {
            for(int i = size2; i < size1; i++) {
                if(arr1[i] > 0) {
                    return 1;
                }
            }
        }

        return 0;
    }

    vector<int> versionArrayWithString(string str) {
        vector<int> arr;
        int i = 0, k = 0;
        while(i <= str.length()) {
            if(i == str.length() || str[i] == '.') {
                int len = i - k;
                string s = str.substr(k, len);
                int num = stoi(s);
                arr.push_back(num);
                i++;
                k = i;
            } else {
                i++;
            }
        }

        return arr;
    }
};