class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        while (candidates.size() > 0 && candidates.back() > target)
        	candidates.pop_back();

        vector<int> cur;
        vector<vector<int>> res;

        dfs(0,candidates.size(),target,false,cur,candidates,res);

        return res;
    }

    void dfs(int i,int n,int target,bool last_is_chosen,vector<int> &cur,vector<int> &candidates,vector<vector<int>> &res)
    {
    	if (target == 0)
    	{
    		res.push_back(cur);
    		return;
    	}

    	if (i >= n || target < candidates[i])
    		return;

    	dfs(i+1,n,target,false,cur,candidates,res);

    	if (i > 0 && candidates[i-1] == candidates[i])
    	{
    		if (!last_is_chosen)
    			return;
    	}

    	cur.push_back(candidates[i]);
    	dfs(i+1,n,target-candidates[i],true,cur,candidates,res);
    	cur.pop_back();
    }
};
