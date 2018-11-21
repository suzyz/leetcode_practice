class Solution {
public:
    string smallestGoodBase(string n) {
        long long m = 0;
        for (int i = 0; i < n.length(); ++i)
        	m = m * 10 + n[i] - '0';
        
        for (int len = log2(m + 1); len > 2; --len)
        {
        	long long l = 2, r = pow(m, 1.0/(len-1));
        	while (l <= r) {
        		long long mid = l + ((r-l)>>1);

        		long long sum = 1, w = mid;
        		for (int i = 1; i < len; ++i)
        		{
        			sum += w;
        			w *= mid;
        		}

        		if (sum == m)
        			return to_string(mid);

        		if (sum > m)
        			r = mid - 1;
        		else
        			l = mid + 1;
        	}
        }

        return to_string(m - 1);
    }
};