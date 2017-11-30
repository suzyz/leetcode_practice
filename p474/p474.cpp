class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int num = strs.size();
        if (num == 0)
        	return 0;

        int f[m+2][n+2];
        memset(f,0,sizeof(f));
        for (int i = 0; i < num; ++i)
        {
        	int x = 0, y = 0;
        	for (int j = 0; j < strs[i].length(); ++j)
        		if (strs[i][j] == '0')
        			++x;

        	y = strs[i].length() - x;

        	for (int j = m; j >= x; --j)
        		for (int k = n; k >= y; --k)
        			f[j][k] = max(f[j][k],f[j-x][k-y]+1);
        }

        return f[m][n];
    }
};
