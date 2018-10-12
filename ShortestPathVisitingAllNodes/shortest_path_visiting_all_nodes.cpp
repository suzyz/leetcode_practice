// Brutal BFS.
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1)
        	return 0;

        int fullState = (1<<n) - 1;

        queue<pair<int, int>> qu;
        for (int i = 0; i < n; ++i)
        	qu.push(make_pair(i, 1<<i));

        int steps = 0;
        while (!qu.empty()) {

        	int levelCount = qu.size();
        	bool flag = false;
        	vector<vector<bool>> vis(n, vector<bool>(fullState+1, false));

            // printf("steps:%d levelCount:%d\n", steps, levelCount);
        	while (levelCount > 0) {
        		--levelCount;

        		pair<int, int> cur = qu.front();
        		qu.pop();
    
                // printf("cur:%d %d\n", cur.first, cur.second);
                
        		int u = cur.first;
        		for (int i = 0; i < graph[u].size(); ++i)
        		{
        			int v = graph[u][i];

        			int newState = cur.second | (1<<v);
        			if (newState == fullState)
        				return steps+1;
        			else if (!vis[v][newState]) {
        				qu.push(make_pair(v, newState));
        				vis[v][newState] = true;
        			}
        		}
        	}

        	++steps;
        }

        return steps;
    }
};