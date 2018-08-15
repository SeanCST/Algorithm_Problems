/* 剑指 Offer - 把数组排成最小的数

 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
 * 打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
 * 则打印出这三个数字能排成的最小数字为321323。
 */

class Solution {
public:
    static bool cmp(int a, int b) {
        string A = "";
        string B = "";
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);
        
        return A < B;
    }
    
    string PrintMinNumber(vector<int> numbers) {
        string answer = "";
        sort(numbers.begin(), numbers.end(), cmp);  // 将 numbers 数组按照自定义的 cmp 比较规则从小到大排序
        for (int i = 0; i < numbers.size(); i++) {  // 再将排好序的数组从头至尾组合成字符串
            answer += to_string(numbers[i]);
        }
        
        return answer;
    }
    
};