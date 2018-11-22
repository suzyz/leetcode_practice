// Backwards.
// Don't need to worry about exceeding the range of int.

class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        while (n >= i) {
            n -= i;
            ++i;
        }
        
        return i-1;
    }
};