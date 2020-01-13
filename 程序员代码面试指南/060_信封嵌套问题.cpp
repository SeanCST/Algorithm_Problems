#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Envelope {
public:
    int len;
    int wid;
    Envelope() {}
    Envelope(int length, int width) : len(length), wid(width) {}
    // bool operator < (const Envelope &other) const {
    //     // 按照长度从小到大，长度相等情况下宽度从大到小的顺序进行排序
    //     return len != other.len ? len < other.len : wid > other.wid;
    // }
};

bool compare(Envelope first, Envelope second) {
    return first.len != second.len ? first.len < second.len : first.wid > second.wid;
}

vector<Envelope> getSortedEnvelopes(vector<vector<int>> matrix) {
    vector<Envelope> envelopes;
    for(int i = 0; i < matrix.size(); i++) {
        envelopes.push_back(Envelope(matrix[i][0], matrix[i][1]));
    }
    // sort(envelopes.begin(), envelopes.end());
    sort(envelopes.begin(), envelopes.end(), compare);
    
    return envelopes;
}

int maxEnvelopes(vector<vector<int>> matrix) {
    vector<Envelope> envelopes = getSortedEnvelopes(matrix);
    int n = matrix.size();

    // 根据 wid 求最大递增子序列
    vector<int> ends(n, 0);
    ends[0] = envelopes[0].wid;
    int right = 0;
    int l = 0, r = 0, m = 0;
    for (int i = 1; i < n; i++) {
        l = 0; 
        r = right;
        while (l <= r) {
            m = (l + r) / 2;
            if(envelopes[i].wid > ends[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        right = max(right, l);
        ends[l] = envelopes[i].wid;
    }
    return right + 1;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(2, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << maxEnvelopes(matrix);
    
    return 0;
}