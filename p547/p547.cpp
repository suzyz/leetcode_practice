
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int res = n;
        vector<int> fa(n);
        for (int i = 0; i < n; ++i)
        	fa[i] = i;

        for (int i = 1; i < n; ++i)
        {
        	int x = getfa(i,fa);
        	for (int j = 0; j < i; ++j)
        		if (M[i][j] == 1)
        		{
        			int y = getfa(j,fa);
        			if (y != x)
        			{
        				--res;
        				fa[y] = x;
        			}
        		}
        }

        return res;
    }

    int getfa(int cur,vector<int> &fa)
    {
    	if (cur == fa[cur])
    		return cur;

    	while (cur != fa[cur])
    		cur = fa[cur];
    	
    	return cur;
    }
};
