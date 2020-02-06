#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 空间复杂度 O(n)
// bool onlyOnce(vector<int> arr) {
//     map<int, bool> m;
//     for(int i = 0; i < arr.size(); i++) {
//         if(m[arr[i]]) {
//             return false;
//         } else {
//             m[arr[i]] = true;
//         }
//     }
    
//     return true;
// }

// // 空间复杂度 O(1)
// bool onlyOnce(vector<int> arr) {
//     sort(arr.begin(), arr.end());
//     for(int i = 1; i < arr.size(); i++) {
//         if(arr[i] == arr[i - 1]) {
//             return false;
//         }
//     }
    
//     return true;
// }

void swap(vector<int>& arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void heapify(vector<int>& arr, int i, int size) {
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = i;
    while(left < size) {
        if(arr[left] > arr[largest]) {
            largest = left;
        }
        if(right < size && arr[right] > arr[largest]) {
            largest = right;
        }
        if(largest != i) {
            swap(arr, i, largest);
        } else {
            break;
        }
        i = largest;
        left = i * 2 + 1;
        right = i * 2 + 2;
    }
}

void heapInsert(vector<int>& arr, int i) {
    int parent = 0;
    while (i != 0) {
        parent = (i - 1) / 2;
        if(arr[parent] < arr[i]) {
            swap(arr, parent, i);
            i = parent;
        } else {
            break;
        }        
    }
}

void heapSort(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        heapInsert(arr, i);
    }
    for(int i = arr.size() - 1; i > 0; i--) {
        swap(arr, 0, i);
        heapify(arr, 0, i);
    }
}

// 空间复杂度 O(1) （堆排序）
bool onlyOnce(vector<int> arr) {
    heapSort(arr);
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] == arr[i - 1]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    if(onlyOnce(arr)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}