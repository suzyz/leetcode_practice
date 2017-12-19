class Solution {
public:
    bool canWinNim(int n) {
    	if (n == 0)
    		return false;
    	if (n < 4)
    		return true;

    	return n%4 != 0;

       	vector<bool> f(n+2);

       	f[0] = false;
       	f[1] = f[2] = f[3] = true;
       	for (int i = 4; i <= n; ++i)
       	{
       		if (!f[i-1] || !f[i-2] || !f[i-3])
       			f[i] = true;
       		else
       			f[i] = false;
       	}

       	return f[n];
    }
};
