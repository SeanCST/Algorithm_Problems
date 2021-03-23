/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    private ArrayList<Integer> arrayList;
    private int curIndex;

    public NestedIterator(List<NestedInteger> nestedList) {
        arrayList = new ArrayList<Integer>();
        addToArrayList(nestedList);
        curIndex = 0;
    }

    private void addToArrayList(List<NestedInteger> nestedList) {
        for (NestedInteger nestedInteger : nestedList) {
            if (nestedInteger.isInteger()) {
                arrayList.add(nestedInteger.getInteger());
            } else {
                addToArrayList(nestedInteger.getList());
            }
        }
    }

    @Override
    public Integer next() {
        if (curIndex < arrayList.size()) {
            return arrayList.get(curIndex++);
        } else {
            return -1;
        }
    }

    @Override
    public boolean hasNext() {
        return curIndex < arrayList.size();
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */