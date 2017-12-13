class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0)
        	return false;

        while (num > 1)
        {
        	int k = num & 3;
        	if (k != 0)
        		return false;
        	num >>= 2;
        }

        return true;
    }
};
