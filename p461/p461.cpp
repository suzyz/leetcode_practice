class Solution {
public:
    int hammingDistance(int x, int y) {
        int d = 0;
        x ^= y;
        while (x != 0)
        {
        	d += (x&1);
        	x >>= 1;
        }
        return d;
    }
};
