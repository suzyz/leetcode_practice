class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> res(m, vector<int>(n));

        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j)
        		res[j][i] = A[i][j];

        return res;
    }
};