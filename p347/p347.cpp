class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> freq;

       	for (int i = 0; i < n; ++i)
       	{
       		if (freq.count(nums[i]))
       	}
       	
       	k = freq.size() < k ? freq.size():k;
       	vector<int> res(n,0);
       	map<int>::iterator it = freq.begin();
       	for (int i = 0; i < k; ++i)
       		res.push_back(it->first);
       	
       	return res;
    }
};
