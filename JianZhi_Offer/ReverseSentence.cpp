/* 剑指 Offer - 翻转单词顺序列

 * 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
 * 同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
 * 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
 * Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
 **/

class Solution {
public:
    string ReverseSentence(string str) {
        // 先整个翻转过来
        reverse(str.begin(), str.end());

        // 再对每一个单词进行翻转
        int left = 0, len = str.length();
        for(int i = 0; i < len; i++){
            if(str[i] == ' ' || i == len - 1){
                int right = i - 1;
                if(i == len - 1)
                    right += 1;

                while(left < right) {
                    swap(str[left], str[right]);
                    left++;
                    right--;
                }
                left = i + 1;
            }
        }

        return str;
    }
};