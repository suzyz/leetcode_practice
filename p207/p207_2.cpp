//DFS

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0)
        	return true;

        vector<int> g[numCourses];
        int pre[numCourses];
        memset(pre,0,sizeof(pre));
        for (int i = 0; i < prerequisites.size(); ++i)
        {
        	int x = prerequisites[i].first;
        	int y = prerequisites[i].second;
        	++pre[x];
        	g[y].push_back(x);
        }

        for (int i = 0; i < numCourses; ++i)
        {
        	if (pre[i] == 0)
        	{
        		dfs(i,vis);
        	}
        }

        
        return 
    }
};
