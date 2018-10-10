class Solution {
public:
	int f[102][102]; // f[i][j]: i persons, profit j.
					// store all f[i][j](j>=P) in f[i][P];
	const int mo = 1e9 + 7;
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int n = group.size();

        f[0][0] = 1;
       	for (int k = 0; k < n; ++k)
       	{
       		int g = group[k], p = profit[k];

       		for (int i = G-g; i >= 0; --i)
       			for (int j = P; j >= 0; --j)
       			{
       				f[i+g][min(j+p, P)] += f[i][j];
       				f[i+g][min(j+p, P)] %= mo;
       			}
       	}

        long long ans = 0;
       	for (int i = 1; i <= G; ++i)
	       	ans += f[i][P];

        return ans%mo;
    }
};