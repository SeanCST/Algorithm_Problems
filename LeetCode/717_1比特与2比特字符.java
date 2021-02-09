class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int len = bits.length;

        int i = 0;
        while(i < len - 1) {
            if(bits[i] == 0) {
                i += 1;
            } else if(bits[i] == 1) {
                i += 2;
            }
        }

        return i == len - 1;
    }
}

// class Solution {
//     public boolean isOneBitCharacter(int[] bits) {
//         return isLastOneBit(bits, 0);
//     }

//     private boolean isLastOneBit(int[] bits, int curIndex) {
//         int len = bits.length;
//         if(curIndex == len - 1) {
//             return bits[curIndex] == 0;
//         }
//         if(curIndex == len - 2) {
//             if(bits[curIndex] == 1) {
//                 return false;
//             } else {
//                 return bits[curIndex + 1] == 0;
//             }
//         }

//         if(bits[curIndex] == 0) {
//             return isLastOneBit(bits, curIndex + 1);
//         } else {
//             return isLastOneBit(bits, curIndex + 2);
//         }
//      }
// }