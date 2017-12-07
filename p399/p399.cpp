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

       	vector<double> res;
    }
};
