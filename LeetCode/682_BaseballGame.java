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

class Solution {
    public int calPoints(String[] operations) {
        List<Integer> points = new ArrayList<>();
        int res = 0;
        for (int i = 0 ; i < operations.length; i++) {
            int size = points.size();
            int cur = 0;

            switch(operations[i]) {
                case "+": 
                    cur = points.get(size - 1) + points.get(size - 2);
                    points.add(cur);
                    res += cur;
                    break;
                case "D": 
                    cur = points.get(size - 1) * 2;
                    res += cur;
                    points.add(cur);
                    break;
                case "C": 
                    res -= points.get(size - 1);
                    points.remove(size - 1);
                    break;
                default: 
                    cur = Integer.valueOf(operations[i]);
                    res += cur;
                    points.add(cur);
            }
        }

        return res;
    }
}