class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0)
        	return false;
        int m = matrix[0].size();
        if (m == 0 || matrix[0][0] > target)
        	return false;
        if (matrix[n-1][m-1] < target)
        	return false;

        int j = m-1;
        for (int i = 0; i < n; ++i)
        {
        	if (matrix[i][0] > target)
        		return false;
        	if (matrix[i][m-1] < target)
        		continue;

        	while (j >= 0 && matrix[i][j] > target)
        		--j;

        	if (matrix[i][j] == target)
        		return true;
        }

        return false;
    }
};
