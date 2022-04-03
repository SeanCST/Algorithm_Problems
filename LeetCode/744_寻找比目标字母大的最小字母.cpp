class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int len = letters.length;
        int l = 0, r = len - 1;

        while(l < r) {
            int mid = l + (r - l) / 2;
            if(mid < len - 1 && letters[mid] <= target && letters[mid + 1] > target) {
                return letters[mid + 1];
            } else if (letters[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return letters[0];
    }
}

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, h = letters.size() - 1, mid;
            
        while(l <= h) {
            mid = l + (h - l) / 2;
            if(letters[mid] <= target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        
        return l < letters.size() ? letters[l] : letters[0];
    }
};