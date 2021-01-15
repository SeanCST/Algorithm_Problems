
class Solution {
    public int removeStones(int[][] stones) {
        UnionField unionField = new UnionField();

        for (int[] stone : stones) {
            unionField.union(stone[0], stone[1] + 10001);
        }

        return stones.length - unionField.getCount();
    }

    private class UnionField {
        private Map<Integer, Integer> parent;
        private int count; // 标志连通分量的个数

        public UnionField() {
            this.parent = new HashMap<>();
            this.count = 0;
        }

        public int getCount() {
            return count;
        }

        public int find(int x) {
            if (!parent.containsKey(x)) {
                parent.put(x, x);
                // 并查集集中新加入一个结点，结点的父亲结点是它自己，所以连通分量的总数 +1
                count++;
            }

            if (x != parent.get(x)) {
                parent.put(x, find(parent.get(x)));
            }

            return parent.get(x);
        }

        public void union(int x, int y) {
            int xRoot = find(x);
            int yRoot = find(y);

            if(xRoot != yRoot) {
                // 把两个连通分量连接起来
                parent.put(xRoot, yRoot);
                // 两个连通分量合并成为一个，连通分量的总数 -1
                count--;
            }
        }
    }
}