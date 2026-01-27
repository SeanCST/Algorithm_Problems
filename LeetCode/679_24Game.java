class Solution {
    private static final double TARGET = 24.0;
    private static final double EPS = 1e-6;

    public boolean judgePoint24(int[] cards) {
        List<Double> list = new ArrayList<>();
        for (int card : cards) {
            list.add((double) card);
        }

        return dfs(list);
    }

    private boolean dfs(List<Double> list) {
        int n = list.size();
        if (n == 1) {
            return Math.abs(list.get(0) - TARGET) < EPS;
        }

        for (int i = 0; i < n; i++) {
            double a = list.get(i);
            for (int j = i + 1; j < n; j++) {
                double b = list.get(j);
                List<Double> next = new ArrayList<>();
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) {
                        next.add(list.get(k));
                    }
                }
                for (double cur : compute(a, b)) {
                    next.add(cur);
                    if (dfs(next)) {
                        return true;
                    }
                    next.remove(next.size() - 1);
                }
            }
        }

        return false;
    }

    private List<Double> compute(double a, double b) {
        List<Double> res = new ArrayList<>();
        res.add(a + b);
        res.add(a - b);
        res.add(b - a);
        res.add(a * b);
        if (Math.abs(a) > EPS) {
            res.add(b / a);
        }
        if (Math.abs(b) > EPS) {
            res.add(a / b);
        }
        return res;
    }
}