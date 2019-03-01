class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {        
        // 计算出各数出现的频率
        map<int, int> freqForNum;
        for(int num : nums) {
            freqForNum[num]++;
        }
        
        // 优先队列 ，操作之后 pq 内存储的是最大的 k 个 freq 
        priority_queue<int, vector<int>, greater<int>> pq; // 小顶堆
        map<int, int>::iterator iter = freqForNum.begin();
        while(iter != freqForNum.end()) { // 遍历字典
            if(pq.size() == k) { 
                if(iter->second > pq.top()) {
                    pq.push(iter->second);
                    pq.pop();
                }
            } else {
                pq.push(iter->second);
            }
            iter++;
        }
        
        vector<int> res; // 存放结果
        map<int, bool> itemAdded; // 标记是否即加入到结果当中
        int minTopKFreq = pq.top();  // 满足 topK 最小的频率
        for(int num : nums) {  
            // 当出现频率大于“最小满足 topK 频率” 且还未被加入到结果当中才加入，避免将一个数多次加入到结果当中
            if(freqForNum[num] >= minTopKFreq && itemAdded[num] == false) {
                res.push_back(num);
                itemAdded[num] = true;
            }
        }
        
        return res;
    }
};