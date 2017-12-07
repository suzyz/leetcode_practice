// Recursive.

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> chosen(n,false);

        sort(nums.begin(), nums.end());
        dfs(0,n,cur,chosen,nums,res);

        return res;
    }

    void dfs(int i,int n,vector<int> &cur,vector<bool> &chosen,vector<int> &nums,vector<vector<int>> &res)
    {
    	if (i >= n)
    	{
    		res.push_back(cur);
    		return;
    	}

    	dfs(i+1,n,cur,chosen,nums,res);

    	if (i > 0 && nums[i] == nums[i-1] && !chosen[i-1])
    		return;

    	chosen[i] = true;
    	cur.push_back(nums[i]);
    	dfs(i+1,n,cur,chosen,nums,res);
    	cur.pop_back();
    	chosen[i] = false;
    }
};
