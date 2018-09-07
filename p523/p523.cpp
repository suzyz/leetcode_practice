class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       	unordered_set<int> setOfSums;
       	int sum = 0, pre = 0;

       	for (int i = 0; i < nums.size(); ++i)
       	{
       		sum += nums[i];
       		if (k != 0)
       			sum %= k;

       		if (setOfSums.count(sum)) {
       			return true;
       		}

       		setOfSums.insert(pre);
       		pre = sum;
       	}

       	return false;
    }
};