// Similar to topological sort.

class Solution {
public:
    int outDegree[10002];
    vector<int> reverse[10002];
    queue<int> qu;

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        for (int i = 0; i < n; ++i) {
        	outDegree[i] = graph[i].size();
            if (outDegree[i] == 0)
                qu.push(i);
            else
            	for (int j = 0; j < outDegree[i]; ++j)
            		reverse[graph[i][j]].push_back(i);
        }
        
        vector<int> ans;

        while (!qu.empty()) {
        	int cur = qu.front();
            qu.pop();

        	ans.push_back(cur);

        	for (int i = 0; i < reverse[cur].size(); ++i) {
        		int v = reverse[cur][i];
        		--outDegree[v];

                if (outDegree[v] == 0)
                    qu.push(v);
        	}
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};