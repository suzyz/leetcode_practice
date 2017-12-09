class Solution {
public:
	int n = 0;
	vector<bool> used;
	unordered_map<int,bool> m;

    bool canIWin(int maxChoosableInteger, int desiredTotal) {

    	if (maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal)
    		return false;

    	if (desiredTotal <= 0)
    		return true;

    	n = maxChoosableInteger;
    	used = vector<bool>(n+1,false);
    	return dfs(desiredTotal);
    }

    bool dfs(int desiredTotal)
    {
    	if (desiredTotal <= 0)
    		return false;

    	int cur = format();
    	if (m.count(cur))
    		return m[cur];

    	m[cur] = false;
    	for (int i = 1; i <= n; ++i)
    		if (!used[i])
    		{
    			used[i] = true;
    			bool flag = dfs(desiredTotal-i);
    			used[i] = false;

    			if (!flag)
    			{
    				m[cur] = true;
    				return true;
    			}
    		}

    	return false;
    }

    int format()
    {
    	int res = 0;
    	for (int i = 1; i <= n; ++i)
    		if (used[i])
    			res |= (1<<i);

    	return res;
    }
};
