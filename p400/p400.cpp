class Solution {
public:
    int findNthDigit(int n) {
    	if (n < 10)
    		return n;
    	
        vector<int> len(32,0);
        len[1] = 9;
        int min = 10, max = 99;
        for (int i = 2; i <= 31; ++i)
        {
        	len[i] = len[i-1] + (max-min)*i;
        	max = 10*max + 9;
        	min *= 10;
        	if (l[i] >= n)
        	{
        		int k = n-l[i-1];
        	}
        }
        return 0;
    }
};
