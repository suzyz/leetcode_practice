class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0)
        	return 0;
        int m = matrix[0].size();
        if (m == 0)
        	return 0;

        int f[2][m], pre = 0, res = 0;

        for (int i = 0; i < m; ++i)
        {
        	f[0][i] = matrix[0][i]-'0';
        	if (f[0][i] == 1)
        		res = 1;
        }

        for (int i = 1; i < n; ++i)
        {
        	f[1-pre][0] = matrix[i][0]-'0';
        	res = max(res,f[1-pre][0]);

        	for (int j = 1; j < m; ++j)
        		if (matrix[i][j] == '1')
        		{
        			f[1-pre][j] = min(min(f[pre][j],f[pre][j-1]),f[1-pre][j-1]) + 1;
        			res = max(res,f[1-pre][j]);
        		}
        		else
        			f[1-pre][j] = 0;

        	pre = 1-pre;
        }

        return res * res;
    }
};
