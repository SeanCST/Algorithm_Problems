class MedianFinder {
    priority_queue <int, vector<int>, less<int>> q1; // 大顶堆
    priority_queue <int, vector<int>, greater<int>> q2; // 小顶堆
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        int n1 = q1.size();
        int n2 = q2.size();

        if(n1 == 0 && n2 == 0) {
            q1.push(num);
        } else if(n1 == n2) {
            if(q1.top() >= num) {
                q1.push(num);
            } else {
                q2.push(num);
            }
        } else if(n1 - 1 == n2) {
            if(num >= q1.top()) {
                q2.push(num);
            } else {
                q2.push(q1.top());
                q1.pop();
                q1.push(num);
            }
        } else if(n1 + 1 == n2) {
            if(num <= q2.top()) {
                q1.push(num);
            } else {
                q1.push(q2.top());
                q2.pop();
                q2.push(num);
            }
        }
    }
    
    double findMedian() {
        int n1 = q1.size();
        int n2 = q2.size();

        if(n1 + n2 == 0) {
            return 0;
        }

        if(n1 > n2) {
            return q1.top();
        } else if(n1 < n2) {
            return q2.top();
        } else {
            return (q1.top() + q2.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */