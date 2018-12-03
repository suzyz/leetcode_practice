class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int last = n&1, cur;
        n >>= 1;
        while (n > 0) {
            cur = n&1;
            if (cur == last)
                return false;
            
            last = cur;
            n >>= 1;
        }
        
        return true;
    }
};