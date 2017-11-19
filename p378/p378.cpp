// Without considering the matrix sorted.

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (n == 0)
        	return 0;
        int m = matrix[0].size();

        priority_queue<int,vector<int>,std::greater<int>> h;
        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j)
        		h.push(matrix[i][j]);

       	for (int i = 0; i < k-1; ++i)
       		h.pop();

       	return h.top();
    }
};
