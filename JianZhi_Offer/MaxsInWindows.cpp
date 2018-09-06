/* 剑指 Offer - 滑动窗口的最大值
 
 * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
 * 那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
 * 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
 * {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， 
 * {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 **/

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> maxInWindows;
        if(num.size() >= size && size >= 1) {
            // 本题使用双端队列
            deque<int> index;
            
            // 先处理第一个窗口内的数据
            for(unsigned int i = 0; i < size; i++){
                if(!index.empty() && num[i] >= num[index.back()])  
                    index.pop_back();
                index.push_back(i);
            }
            
            // 处理后面那些窗口内的数据
            for(unsigned int i = size; i < num.size(); i++){
                // 先将 index 队首索引所对应的数添加到结果中（队首所对应的数为当前窗口的最大值）
                maxInWindows.push_back(num[index.front()]);
                // 若索引队列不为空且当前数字大于等于索引队尾对应数字，则 pop 索引队尾（它已不可能成为当前窗口最大数值，因为当前索引对应数值（窗口的最后一个值）已经大于它）
                while(!index.empty() && num[i] >= num[index.back()])
                    index.pop_back();
                // 若索引队列不为空且索引队首已经不在当前窗口了，则 pop 索引队首
                while(!index.empty() && index.front() <= (int)(i - size))
                    index.pop_front();
                // 将当前索引 push 到索引队尾
                index.push_back(i);
            }
            maxInWindows.push_back(num[index.front()]);
        } 
        
        return maxInWindows;
    }
};