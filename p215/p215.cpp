// O(N^2)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return find_kth(nums,0,n-1,k);
    }
    int find_kth(vector<int> &nums,int st,int en,int k)
    {
    	int idx = st;
    	for (int i = st; i < en; ++i)
    		if (nums[i] >= nums[en])
    		{
    			if (i != idx)
    				swap(nums[i],nums[idx]);
    			++idx;
    		}

    	if (idx != en)
    		swap(nums[en],nums[idx]);

    	if (idx-st == k-1)
    		return nums[idx];
    	else
    	if (idx-st < k-1)
    		return find_kth(nums,idx+1,en,k-(idx-st+1));
    	else
    		return find_kth(nums,st,idx-1,k);
    }
};
