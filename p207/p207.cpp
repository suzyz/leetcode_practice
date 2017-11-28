//BFS

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

        int sum = 0;
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
        	if (pre[i] == 0)
        	{
        		++sum;
        		--pre[i];

        		q.push(i);
        	}
        }

        while (q.size() && sum < numCourses)
        {
        	int x = q.front();
        	q.pop();

        	for (int i = 0; i < g[x].size(); ++i)
        	{
        		int y = g[x][i];
        		--pre[y];
        		if (pre[y] == 0)
        		{
        			++sum;
        			--pre[y];
        			q.push(y);
        		}
        	}
        }

        return sum == numCourses;
    }
};
