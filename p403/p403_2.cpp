// Shorter code. The memorization in search is removed, but a few checkups before the DFS are added to prevent TLE.
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size(); // n >= 2 and n < 1100

        if (stones[1] != 1)
        	return false;

        for (int i = 1; i < n-1; ++i)
            if (stones[i+1] - stones[i] > i+1)
                return false;

        unordered_set<int> pos(stones.begin(), stones.end());

        bool success = false;
        dfs(1,1,pos,stones[n-1],success);

        return success;
    }

    void dfs(int cur,int last_step,unordered_set<int> &pos,int destination,bool &success)
    {
    	if (cur == destination)
    	{
    		success = true;
    		return;
    	}

    	for (int i = 1; i >= -1; --i)
    	{
    		int next = cur + last_step + i;
			if (pos.count(next) == 1 && next > cur)
			{
	    		dfs(next,last_step+i,pos,destination,success);
	    		if (success)
	    			return;
			}
    	}
    }
};
