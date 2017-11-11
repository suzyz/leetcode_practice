
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        if (n==0)
        	return vector<int>();

        if (edges.size() == 0)
        {
        	if (n == 1)
        		return vector<int>(1,0);
        	else
        		return vector<int>();
        }

        vector<unordered_set<int>> g(n);
        for (int i = 0; i < edges.size(); ++i)
        {
        	int a = edges[i].first, b = edges[i].second;
        	g[a].insert(b);
        	g[b].insert(a);
        }

        vector<int> leaves;
        for (int i = 0; i < n; ++i)
        	if (g[i].size() == 1)
        		leaves.push_back(i);
        
        n -= leaves.size();
        while (n)
        {
        	vector<int> new_leaves;
	       	
	       	for (int i = 0; i < leaves.size(); ++i)
	       	{
	       		int cur = leaves[i];
		       	for (unordered_set<int>::iterator j = g[cur].begin(); j != g[cur].end(); )
	        	{
	        		g[*j].erase(cur);
	        		if (g[*j].size() == 1)
	        		{
	        			new_leaves.push_back(*j);
	        			j = g[cur].erase(j);
	        		}
	        		else
	        			++j;
	        	}	
	       	}
        	leaves = new_leaves;
        	n -= leaves.size();
        }

        return leaves;
    }
};
