class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sumCost = accumulate(cost.begin(), cost.end(), 0), sumGas = accumulate(gas.begin(), gas.end(), 0);
        if (sumCost > sumGas) return -1;

        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            sum += diff;

            if(sum < 0) {
                sum = 0;
                ans = i + 1;
            }
            
        }

        return ans;
    }
};
