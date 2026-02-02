class Solution {
    public String validIPAddress(String queryIP) {
        if (queryIP.contains(".")) {
            String[] splits = queryIP.split("\\.", -1);
            if(splits.length != 4) {
                return "Neither";
            }

            for (String split : splits) {
                if (split.length() == 0 || split.length() > 3
                    || (split.charAt(0) == '0' && split.length() > 1)) {
                    return "Neither";
                }
                int num = 0;
                for (char c : split.toCharArray()) {
                    if (c < '0' || c > '9') {
                        return "Neither";
                    }
                    num = num * 10 + (c - '0');
                }
                if (num > 255) {
                    return "Neither";
                }
            }

            return "IPv4";
        } else if (queryIP.contains(":")) {
            String[] splits = queryIP.split(":", -1);
            if(splits.length != 8) {
                return "Neither";
            }
            for (String split : splits) {
                if (split.length() == 0 || split.length() > 4) {
                    return "Neither";
                }
                for (char c : split.toCharArray()) {
                    if ((c < '0' || c > '9') && (c < 'a' || c > 'f') && (c < 'A' || c > 'F')) {
                        return "Neither";
                    }
                }
            }

            return "IPv6";
        }

        return "Neither";
    }
}