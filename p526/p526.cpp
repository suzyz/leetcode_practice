class Solution {
public:
	int count = 0;
    int countArrangement(int N) {
    	vector<bool> used(N+1,false);
        dfs(1,N,used);
        return count;
    }

    void dfs(int cur,int n,vector<bool> &used)
    {
    	if (cur > n)
    	{
    		++count;
    		return;
    	}

    	for (int i = 1; i <= n; ++i)
    		if (used[i] == false && (i%cur == 0 || cur%i == 0))
    		{
    			used[i] = true;
    			dfs(cur+1,n,used);
    			used[i] = false;
    		}
    }
};
