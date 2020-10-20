class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0, run = 0, rest = 0;
        for(int i = 0; i < n; i++) {
            run += (gas[i] - cost[i]);
            rest += (gas[i] - cost[i]);
            if(run < 0) {
                start = i + 1;
                run = 0;
            }
        }

        return rest < 0 ? -1 : start;
    }
};

// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         for(int i = 0; i < n; i++) {
//             if(gas[i] >= cost[i]) {
//                 int curGas = gas[i] - cost[i];
//                 for(int j = (i + 1) % n; j != i; j = (j + 1) % n) {
//                     curGas += gas[j];
//                     curGas -= cost[j];
//                     if(curGas < 0) {
//                         break;
//                     }
//                 }
//                 if(curGas >= 0) {
//                     return i;
//                 }
//             }
//         }

//         return -1;
//     }
// };