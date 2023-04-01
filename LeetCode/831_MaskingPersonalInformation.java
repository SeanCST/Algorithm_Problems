class Solution {
    public String maskPII(String s) {
        if(s.contains("@")) {
            String[] splits = s.split("@");
            return String.format("%c*****%c@%s", 
                        splits[0].toLowerCase().charAt(0),
                        splits[0].toLowerCase().charAt(splits[0].length() - 1),
                        splits[1].toLowerCase()); 
        } else {
            String res = "";
            int count = 0;
            for(int i = s.length() - 1; i >= 0; i--) {
                if(s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                    count++;
                    if(count <= 4) {
                        res = s.charAt(i) + res;
                    }
                }
            }
            if(count == 10) {
                res = "***-***-" + res;
            } else if (count == 11) {
                res = "+*-***-***-" + res;
            } else if (count == 12) {
                res = "+**-***-***-" + res;
            } else if (count == 13) {
                res = "+***-***-***-" + res;
            }
            return res;
        }
    }
}