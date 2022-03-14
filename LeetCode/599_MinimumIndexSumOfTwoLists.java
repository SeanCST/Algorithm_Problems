class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        List<String> res = new ArrayList<String>();

        int minIndexSum = 9999;
        for(int i = 0; i < list1.length; i++) {
            for(int j = 0; j < list2.length; j++) {
                if(list1[i].equals(list2[j])) {
                    if(i + j < minIndexSum) {
                        res.clear();
                        res.add(list1[i]);
                        minIndexSum = i + j;
                    } else if(i + j == minIndexSum) {
                        res.add(list1[i]);
                    }
                }
            }
        }

        return res.toArray(new String[0]);
    }
}