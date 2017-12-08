class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int idx = 0, i = 0;
        while (i < n)
        {
        	int j = i+1;
        	if (j >= n || nums[i] != nums[j])
        		nums[idx++] = nums[i++];
        	else
        	{
        		++j;
        		while (j < n && nums[j] == nums[i])
        			++j;

        		nums[idx++] = nums[i];
        		nums[idx++] = nums[i];

        		i = j;
        	}
        }

        return idx;
    }
};
