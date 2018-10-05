class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size(), m = nums[0].size();
        if (n * m != r * c)
        	return nums;

        int curRow = 0, curCol = 0;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j)
        	{
        		res[curRow][curCol] = nums[i][j];

        		++curCol;
        		if (curCol >= c) {
        			curCol = 0;
        			++curRow;
        		}
        	}

        return res;
    }
};