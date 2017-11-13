class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        if (n < 3)
        	return res;

        vector<bool> is_prime(n,true);

        res = 1;
        int lim = sqrt(n);
        for (int i = 3; i < n; i += 2)
        	if (is_prime[i])
	        {
	        	++res;

	        	if (i > lim)
	        		continue;

	        	int j = i*i;
	        	while (j < n)
	        	{
	        		is_prime[j] = false;
	        		j += (i<<1);
	        	}
	        }
        return res;
    }
};
