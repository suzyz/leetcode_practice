//DFS

class Solution {
public:
    int sum = 0;
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0)
        	return true;

        vector<vector<int>> g(numCourses,vector<int>());
        vector<int> pre(numCourses,0);
        for (int i = 0; i < prerequisites.size(); ++i)
        {
        	int x = prerequisites[i].first;
        	int y = prerequisites[i].second;
        	++pre[x];
        	g[y].push_back(x);
        }

        for (int i = 0; i < numCourses; ++i)
        	if (pre[i] == 0)
            {
                --pre[i];
        		dfs(i,pre,g);
            }
        
        return sum == numCourses;
    }

    void dfs(int cur,vector<int> &pre,vector<vector<int>> &g)
    {
        ++sum;
        for (int i = 0; i < g[cur].size(); ++i)
        {
            --pre[g[cur][i]];
            if (pre[g[cur][i]] == 0)
            {
                --pre[g[cur][i]];
                dfs(g[cur][i],pre,g);
            }
        }
    }
};
