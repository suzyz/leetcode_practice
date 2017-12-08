class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;

        vector<int> cur;
        dfs(1,n,k,cur,res);

        return res;
    }

    void dfs(int st,int n,int k,vector<int> &cur,vector<vector<int>> &res)
    {
    	if (k == 0)
    	{
    		res.push_back(cur);
    		return;
    	}

    	for (int j = st; j <= n-k+1; ++j)
	    {
	    	cur.push_back(j);
	    	dfs(j+1,n,k-1,cur,res);
	    	cur.pop_back();
	    }
    }
};
