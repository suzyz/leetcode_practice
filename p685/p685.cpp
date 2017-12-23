class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_set<int> children[n];

        for (int i = n-1; i >= 0; --i)
        {
        	int x = edges[i][0]-1, y = edges[i][1]-1;
        	
        	
        }

        return vector<int>(2,0);
    }
};
