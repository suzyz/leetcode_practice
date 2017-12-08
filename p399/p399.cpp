class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
       	unordered_map<string,int> m;

       	int n = 0;
       	vector<vector<pair<int,double>>> g;
       	for (int i = 0; i < equations.size(); ++i)
       	{
       		string x = equations[i].first;
       		string y = equations[i].second;

       		if (m.count(x) == 0)
       		{
       			m[x] = n++;
       			g.push_back(vector<pair<int,double>>());
       		}
       		if (m.count(y) == 0)
       		{
       			m[y] = n++;
       			g.push_back(vector<pair<int,double>>());
       		}

			g[m[x]].push_back(make_pair(m[y],values[i]));
			g[m[y]].push_back(make_pair(m[x],1.0/values[i]));
       	}

       	vector<bool> calculated(n,false);
       	vector<vector<double>> dist(n,vector<double>(n,-1));
       	vector<double> res(queries.size(),-1);
       	for (int i = 0; i < queries.size(); ++i)
       	{
       		string a = queries[i].first;
       		string b = queries[i].second;

       		if (m.count(a) == 0 || m.count(b) == 0)
       			continue;

       		int x = m[a];
       		int y = m[b];

       		if (x == y)
       			res[i] = 1;
       		else
       		if (calculated[x])
       			res[i] = dist[x][y];
       		else
       		if (calculated[y])
       			res[i] = 1.0/dist[y][x];
       		else
       		{
       			calculated[x] = true;
       			dijkstra(x,n,g,dist);
       			res[i] = dist[x][y];
       		}
       	}

       	return res;
    }

    void dijkstra(int s,int n,vector<vector<pair<int,double>>> &g,vector<vector<double>> &dist)
    {
    	vector<bool> vis(n,false);

    	dist[s][s] = 0;
    	vis[s] = true;
    	for (int i = 0; i < g[s].size(); ++i)
    	{
    		int y = g[s][i].first;
    		double d = g[s][i].second;
    		if (dist[s][y] < -1e-6 || dist[s][y] > d)
    			dist[s][y] = d;
    	}

    	for (int i = 0; i < n; ++i)
    	{
    		int k = -1;
            double mind = 1e100;
    		for (int j = 0; j < n; ++j)
    			if (!vis[j] && dist[s][j] > -1e-6 && dist[s][j] < mind)
	    		{
	    			k = j;
	    			mind = dist[s][j];
	    		}

	    	if (k == -1)
	    		return;

	    	vis[k] = true;
	    	for (int j = 0; j < g[k].size(); ++j)
	    	{
	    		int y = g[k][j].first;
	    		if (!vis[y])
	    		{
	    			double d = g[k][j].second;
	    			if (dist[s][y] < -1e-6 || dist[s][y] > mind * d)
	    				dist[s][y] = mind * d;
	    		}
	    	}
    	}
    }
};
