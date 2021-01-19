class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder sb = new StringBuilder();
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
        while(i >= 0 || j >= 0 || carry != 0) {
            if(i >= 0) {
                carry += num1.charAt(i--) - '0';
            }
            if(j >= 0) {
                carry += num2.charAt(j--) - '0';
            }
            sb.append(carry % 10);
            carry = carry / 10;
        } 

        return sb.reverse().toString();
    }
}

// class Solution {
//     public String addStrings(String num1, String num2) {
//         String r_num1 = new StringBuilder(num1).reverse().toString();
//         String r_num2 = new StringBuilder(num2).reverse().toString();

//         String res = "";
//         int carry = 0;
//         int i = 0;
//         for (; i < r_num1.length() && i < r_num2.length(); i++) {
//             int cur = r_num1.charAt(i) - '0' + r_num2.charAt(i) - '0' + carry;
//             carry = cur >= 10 ? 1 : 0;
//             cur = cur % 10;
//             res += String.valueOf(cur);
//         }

//         r_num1 = r_num1.length() >= r_num2.length() ? r_num1 : r_num2;
//         while (i < r_num1.length()) {
//             int cur = r_num1.charAt(i) - '0' + carry;
//             carry = cur >= 10 ? 1 : 0;
//             cur = cur % 10;
//             res += String.valueOf(cur);
//             i++;
//         }

//         if (carry > 0) {
//             res += '1';
//         }

//         return new StringBuilder(res).reverse().toString();
//     }
// }