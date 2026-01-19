class Solution {
    public String addStrings(String num1, String num2) {
        int len1 = num1.length(), len2 = num2.length();
        int i = len1 - 1, j = len2 - 1;
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int d1 = i >= 0 ? num1.charAt(i--) - '0' : 0;
            int d2 = j >= 0 ? num2.charAt(j--) - '0' : 0;
            int cur = d1 + d2 + carry;
            carry = cur / 10;
            cur %= 10;
            sb.append(cur);
        }

        return sb.reverse().toString();
    }
}

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

class Solution {
    public String addStrings(String num1, String num2) {
        int i = num1.length() - 1, j = num2.length() - 1;
        StringBuilder builder = new StringBuilder();
        int carry = 0;
        while(i >= 0 || j >= 0) {
            int sum = carry;
            if(i >= 0) {
                sum += num1.charAt(i) - '0';
                i--;
            }
            if(j >= 0) {
                sum += num2.charAt(j) - '0';
                j--;
            }
            carry = sum >= 10 ? 1 : 0;
            sum %= 10;
            builder.append(sum);
        }

        if(carry > 0) {
            builder.append(1);
        }

        return builder.reverse().toString();
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