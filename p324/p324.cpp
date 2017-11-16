class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    	int n = nums.size();
    	if (n < 2)
    		return;

        int i = 0, j = n-1, k = 0; 
        auto m = nums.begin() + n/2;
        nth_element(nums.begin(),m,nums.end());
        int median = *m;

        while (k <= j)
        {
        	if (nums[get_idx(n,k)] > median)
        	{
        		swap(nums[get_idx(n,i)],nums[get_idx(n,k)]);
        		++i;
        		++k;
        	}
        	else
        	if (nums[get_idx(n,k)] < median)
        	{
        		swap(nums[get_idx(n,j)],nums[get_idx(n,k)]);
        		--j;
        	}
        	else
        		++k;
        }
    }

    int get_idx(int n,int k)
    {
    	return (2*k + 1)%(n|1);
    }
};
