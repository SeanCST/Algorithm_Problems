/* 剑指 Offer - 二叉搜索树的后序遍历序列

 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 * 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 **/
 
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int size = sequence.size();
        if(size == 0) 
            return false;
        return judge(sequence, 0, size-1);
    }
    
private:
    bool judge(vector<int>& seq, int l, int r) {
        if(l >= r)
            return true;
        int i = r;
        while(i > l && seq[i-1] > seq[r])
            --i;
        for(int j = i - 1; j >= l; j--) {
            if(seq[j] >= seq[r])
                return false;
        }
        return judge(seq, l, i - 1) && judge(seq, i, r -1);
    }
};