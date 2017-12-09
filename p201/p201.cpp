class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0)
        	return 0;

        int l1 = get_length(m);
        int l2 = get_length(n);
        if (l1 < l2)
        	return 0;

        int mutual = 1 << (l1-1);
        int k = rangeBitwiseAnd(m-mutual,n-mutual);
        return k|mutual;
    }

    int get_length(int cur)
    {
    	int l = 0;
    	while (cur > 0)
    	{
    		++l;
    		cur >>= 1;
    	}

    	return l;
    }
};
