class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        
        for(int i = 0; i < size; i++) {
            if(flowerbed[i] == 0) {  // 当前块未种
                int pre = i == 0 ? 0 : flowerbed[i-1];
                int next = i == size - 1 ? 0 : flowerbed[i+1];
                if(pre == 0 && next == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
            }
            
            if(n <= 0) return true;
        }
        
        return false;
    }
};

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if(size == 1 && flowerbed[0] == 0 && n <= 1) return true;
        
        for(int i = 0; i < size; i++) {
            if(flowerbed[i] == 0) {  // 当前块未种
                if(i == 0) {
                    if(i + 1 < size && flowerbed[i+1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }
                } else if(i == size - 1) {
                    if(i - 1 >= 0 && flowerbed[i-1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }
                } else {
                    if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
            }
            
            if(n <= 0) return true;
        }
        
        return false;
    }
};