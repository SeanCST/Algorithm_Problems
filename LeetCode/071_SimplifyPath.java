class Solution {
    public String simplifyPath(String path) {
        String[] split = path.split("/");
        List<String> resList = new ArrayList<>();
        int i = 0;
        for (String s : split) {
            if (s.equals("..")) {
                if (i > 0) {
                    resList.remove(--i);
                }
            } else if (!s.equals("") && !s.equals(".")) {
                resList.add(s);
                i++;
            }
        }

        if (resList.isEmpty()) {
            return "/";
        } else {
            StringBuilder sb = new StringBuilder();
            for (String s : resList) {
                sb.append("/");
                sb.append(s);
            }

            return sb.toString();
        }
    }
}