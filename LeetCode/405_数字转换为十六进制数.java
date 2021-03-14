class Solution {
    public String toHex(int num) {
        if(num == 0) {
            return "0";
        }
        char[] chars = {'0', '1', '2', '3', '4', '5','6', '7','8', '9',
                        'a', 'b', 'c', 'd', 'e', 'f'};
        StringBuffer sb = new StringBuffer();
        
        while (num != 0) {
            sb.insert(0, chars[num & 0b1111]);
            num >>>= 4; // 无符号右移
        }

        return sb.toString();
    }
}