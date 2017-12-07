class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
        	return false;
        
        int lowbit = n&(-n);
        return n == lowbit;
    }
};
