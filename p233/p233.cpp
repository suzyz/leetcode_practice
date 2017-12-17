// unfinished
class Solution {
public:
    int countDigitOne(int n) {
    	if (n < 1)
    		return 0;
        if (n < 10)
        	return 1;

        int b = n%10;
        return countDigitOne(n/10) + b+1 + countDigitOne(b);
    }
};
