class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), minsum = INT_MAX, sum = 0, start = 0;
        
        for (int i = 0; i < n; ++i) {
            sum += gas[i] - cost[i];
            if (sum < minsum) {
                minsum = sum;
                start = i+1;
            }
        }
        
        if (sum < 0)
            return -1;
        else
            return start % n;
    }
};