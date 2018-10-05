class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size(), ans = 0;

        for (int i = 0; i < n; ++i)
        	if (A[i][0] == 0)
        		for (int j = 0; j < m; ++j)
        			A[i][j] = 1-A[i][j];

        for (int j = 0; j < m; ++j)
       	{
       		int count = 0;
       		for (int i = 0; i < n; ++i)
       			count += A[i][j];

       		count = max(count, n - count);

       		ans += (1<<(m-1-j)) * count;
       	}

        return ans;
    }
};