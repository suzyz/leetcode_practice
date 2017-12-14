// The code is too much. No need to remember or pass along so many things.
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size(); // n >= 2 and n < 1100

        if (stones[1] != 1)
        	return false;

        unordered_map<int,int> pos;
        for (int i = 0; i < n; ++i)
        	pos[stones[i]] = i;

        bool success = false;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        dfs(0,1,n,stones,pos,vis,success);

        return success;
    }

    void dfs(int pre,int cur,int n,vector<int>& stones,unordered_map<int,int> &pos,vector<vector<bool>> &vis,bool &success)
    {
    	if (cur == n-1)
    	{
    		success = true;
    		return;
    	}

    	if (vis[pre][cur])
    		return;

    	vis[pre][cur] = true;

    	int d = stones[cur] - stones[pre];
    	for (int i = -1; i <= 1; ++i)
    	{
    		int next = stones[cur] + d + i;

			if (pos.count(next) == 1 && pos[next] > cur)
			{
	    		dfs(cur,pos[next],n,stones,pos,vis,success);
	    		if (success)
	    			return;
			}
    	}
    		
    }
};
