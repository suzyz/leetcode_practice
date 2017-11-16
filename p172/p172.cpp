class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        long long i = 5;
        while (i <= n)
        {
        	res += n/i;
        	i *= 5;
        }
        return res;
    }
};
