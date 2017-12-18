class NumArray {
public:
	int len = 0;
	vector<int> sum;
    NumArray(vector<int> nums) {
    	len = nums.size();
    	if (len == 0)
    		return;
    	sum.push_back(nums[0]);
        for (int i = 1; i < len; ++i)
        	sum.push_back(nums[i] + sum[i-1]);
    }
    
    int sumRange(int i, int j) {
        if (i < 0 || j >= len || i > j)
        	return 0;

       	if (i == 0)
       		return sum[j];
       	else
       		return sum[j] - sum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
