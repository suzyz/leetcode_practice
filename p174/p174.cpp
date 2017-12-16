class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        if (n == 0)
        	return 0;
        int m = dungeon[0].size();
        if (m == 0)
        	return 0;

        vector<int> f(m+1,0);
        
        f[m] = 1;
        for (int j = m-1; j >= 0; --j)
        {
        	int need = f[j+1] - dungeon[n-1][j];
        	f[j] = need > 0 ? need : 1;
        }

        f[m] = INT_MAX;
        for (int i = n-2; i >= 0; --i)
        	for (int j = m-1; j >= 0; --j)
        	{
        		int need = min(f[j],f[j+1]) - dungeon[i][j];
        		f[j] = need > 0 ? need : 1;
        	}

        return f[0];
    }
};
