class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	int n = nums.size();
    	if (n<2)
    		return n;

    	int f[n+2];
    	f[1] = nums[0];

    	int len = 1;
    	for (int i = 1; i < n; ++i)
    	{
    		if (nums[i] > f[len])
    			f[++len] = nums[i];
    		else
    		if (nums[i] == f[len])
    			continue;
    		else
    		{
    			int pos = binary_search(nums[i],len,f);
    			f[pos] = nums[i];
    		}
    	}
    	return len;
    }

    int binary_search(int cur,int size,int *f) /* return k, s.t. f[k-1] < cur <= f[k] */
    {
    	int l = 1, r = size;
    	while (l<r)
    	{
    		int mid = l + ((r-l)>>1);
    		if (f[mid] == cur)
    			return mid;
    		else
    		if (f[mid] < cur)
    			l = mid+1;
    		else
    			r = mid;
    	}
    	return l;
    }
};
