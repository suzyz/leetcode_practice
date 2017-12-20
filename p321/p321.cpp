class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0)
        	return vector<int>();

        int n = nums1.size(), m = nums2.size();

        // make sure that n is positive.
        if (n < m)
        	return maxNumber(nums2,nums1,k);

        string res(k,0),a,b,c;
        for (int i = max(1,k-m); i <= min(n,k); ++i)
        {
        	best(nums1,i,a);
        	best(nums2,k-i,b);

        	combine(a,b,c);
        	if (res < c)
        		res = c;
        }

        vector<int> r;
        for (int i = 0; i < k; ++i)
        	r.push_back(res[i]);

        return r;
    }

    void best(vector<int> &source,int len,string &res)
    {
    	res = "";
    	int st = 0, n = source.size();
    	for (int i = 0; i < len; ++i)
    	{
    		int maxv = -1, idx = -1;
    		for (int j = st; j <= n-len+i; ++j)
    			if (source[j] > maxv)
    			{
    				maxv = source[j];
    				idx = j;
    			}

    		res += (char)maxv;
    		st = idx+1;
    	}
    }

    void combine(string &a,string &b,string &c)
    {
    	int n = a.length(), m = b.length(), i = 0, j = 0;
    	c = "";
    	while (i < n && j < m)
    	{
    		if (a[i] > b[j])
    			c += a[i++];
    		else
    		if (a[i] == b[j])
    		{
    			if (a.substr(i+1) > b.substr(j+1))
    				c += a[i++];
    			else
    				c += b[j++];
    		}
    		else
    			c += b[j++];
    	}

    	while (i < n)
    	{
    		c += a[i];
    		++i;
    	}

    	while (j < m)
    	{
    		c += b[j];
    		++j;
    	}
    }
};
