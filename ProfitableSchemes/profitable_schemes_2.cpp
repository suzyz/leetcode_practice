// worse coded.
class Solution {
public:
    int f[102][102]; // f[i][j]: i persons, profit j.
    const int mo = 1e9 + 7;
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int n = group.size(), profitSum = 0, ans = 0;

        f[0][0] = 1;
        for (int k = 0; k < n; ++k)
        {
            profitSum += profit[k];
            for (int i = G; i >= group[k]; --i)
                for (int j = min(profitSum, P+profit[k]); j >= profit[k]; --j)
                {
                    f[i][min(j, P)] += f[i-group[k]][j-profit[k]];
                    if (f[i][min(j, P)] >= mo)
                        f[i][min(j, P)] -= mo;
                }
        }

        for (int i = 1; i <= G; ++i)
        {
            ans += f[i][P];
            if (ans >= mo)
                ans -= mo;
        }
        
//         for (int i = 1; i <= G; ++i)
//             for (int j = 1; j <= P; ++j)
//                 if (f[i][j] > 0)
//                     printf("%d %d:%d\n", i,j, f[i][j]);

        return ans;
    }
};