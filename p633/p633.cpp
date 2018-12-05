class Solution {
public:
    bool judgeSquareSum(int c) {
        int lim = floor(sqrt(c/2));

        for (int a = 0; a <= lim; ++a) {
        	int tmp = c - a * a;
        	int b = sqrt(tmp);
        	if (b * b == tmp)
        		return true;
        }

        return false;
    }
};