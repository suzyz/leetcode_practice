// Staight forward.
// Mind the range of n. Could be INT_MAX.

class Solution {
public:
    int arrangeCoins(int n) {
        long long sum = 0, i = 1;
        while (sum < n) {
            sum += i;
            if (sum == n)
                return i;
            
            if (sum > n)
                return i-1;
            
            ++i;
        }
        
        return 0;
    }
};