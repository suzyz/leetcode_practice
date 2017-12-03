// Also DFS. Each time, search the next element of the combination.
class Solution {
private:
	int n = 0;
	vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	sort(candidates.begin(),candidates.end());
    	while (candidates.size() > 0 && candidates.back() > target)
    		candidates.pop_back();

        n = candidates.size();
        vector<int> combination;
        dfs(0,target,candidates,combination);

        return res;
    }

    void dfs(int start,int target,vector<int>& candidates,vector<int>& combination)
    {
    	if (target == 0)
    	{
    		res.push_back(combination);
    		return;
    	}

    	if (start >= n || target < 0)
    		return;

    	for (int i = start; i < candidates.size(); ++i)
    	{
    		if (candidates[i] > target)
                break;

            combination.push_back(candidates[i]);
    		dfs(i,target - candidates[i],candidates,combination);
            combination.pop_back();
    	}
    }
};
