class Solution {
public:
    int nthUglyNumber(int n) {
    	int f[n+1];
    	f[0] = 0;
    	f[1] = 1;
    	int p1,p2,p3;
    	p1 = p2 = p3 = 1;

    	for (int i = 2; i <= n; ++i)
    	{
    		f[i] = min(f[p1]<<1,min(f[p2]*3,f[p3]*5));

    		if (f[i] == (f[p1]<<1))
    			++p1;
    		if (f[i] == f[p2]*3)
    			++p2;
    		if (f[i] == f[p3]*5)
    			++p3;
    	}

    	return f[n];
    }
};
