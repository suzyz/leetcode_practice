class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (numCourses == 0)
        	return res;

        int pre[numCourses];
        vector<int> g[numCourses];
        memset(pre,0,sizeof(pre));
        for (int i = 0; i < prerequisites.size(); ++i)
        {
        	int x = prerequisites[i].first, y = prerequisites[i].second;
        	++pre[x];
        	g[y].push_back(x);
        }
        
        for (int i = 0; i < numCourses; ++i)
       		if (pre[i] == 0)
       		{
       			--pre[i];
       			res.push_back(i);
       		}

       	int idx = 0;
       	while (idx < res.size() && res.size() < numCourses)
       	{
       		int x = res[idx];
       		++idx;
       		
       		for (int i = 0; i < g[x].size(); ++i)
       		{
       			int y = g[x][i];
       			--pre[y];
       			if (pre[y] == 0)
       			{
       				--pre[y];
       				res.push_back(y);
       			}
       		}
       	}

       	if (res.size() == numCourses)
       		return res;
       	else
       		return vector<int>();
    }
};
