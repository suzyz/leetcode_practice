class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j) {
        		int count = 0;
        		for (int x = -1; x <= 1; ++x) {
        			int tx = i + x;
        			if (tx < 0 || tx >= n)
        				continue;

        			for (int y = -1; y <= 1; ++y) {
        				int ty = j + y;
        				if (ty < 0 || ty >= m)
        					continue;

        				ans[i][j] += matrix[tx][ty];
        				++count;
        			}
        		}

        		ans[i][j] /= count;
        	}

        return ans;
    }
};