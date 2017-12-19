class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();

        unordered_map<pair<int,int>,string> f;
        f[make_pair(0,0)] = "";
        for (int i = 1; i <= k; ++i)
        {
        	for (int j = max(1,i-m); j <= min(k,n); ++j)
        	{
        		for (int p = j-1; p >= max(1,i-m); ++p)
        		{
        			if (better(j,))
        		}
        	}
        }
    }
};
