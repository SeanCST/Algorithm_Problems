/* 剑指 offer - 数组中出现次数超过一半的数字
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
 * 如果不存在则输出0。
 */

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int lastNum, count = 0;  
        for (int i = 0; i < numbers.size(); i++) {
            if (count == 0) {
                lastNum = numbers[i];
                count ++;
            } else {
                // 若重复遇到，则次数 ++，否则 --
                if (numbers[i] == lastNum)
                    count ++;
                else 
                    count --;
            }
        }
       
        // 验证
        int verifyCount = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (lastNum == numbers[i])
                verifyCount ++;
        }
        if (verifyCount * 2 > numbers.size())
            return lastNum;
        else 
            return 0;

        
    }
};