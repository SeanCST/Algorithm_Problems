class Solution {
    public int calPoints(String[] ops) {
        ArrayList<Integer> scores = new ArrayList<>();

        for(String s : ops) {
            int n = scores.size();
            if(s.equals("+")) {
                scores.add(scores.get(n - 1) + scores.get(n - 2));
            } else if (s.equals("D")) {
                scores.add(scores.get(n - 1) * 2);
            } else if (s.equals("C")) {
                scores.remove(n - 1);
            } else {
                Integer score = new Integer(s);
                scores.add(score);
            }
        }

        int res = 0;
        for(Integer score : scores) {
            res += score;
        }

        return res;
    }
}