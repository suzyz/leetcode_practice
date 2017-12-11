class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	if (nums.size() == 0)
    		return vector<int>();

        deque<pair<int,int>> q;
        vector<int> res(nums.size()-k+1,0);

        for (int i = 0; i < nums.size(); ++i)
        {
        	while (!q.empty() && q.front().first <= i-k)
        		q.pop_front();

        	while (!q.empty() && q.back().second <= nums[i])
        		q.pop_back();

        	q.push_back(make_pair(i,nums[i]));
        	if (i >= k-1)
        		res[i-k+1] = q.front().second;
        }
        return res;
    }
};
