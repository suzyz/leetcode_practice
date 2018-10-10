// f[i][j]: i至j堆石头，先手至多超出后手多少。
// O(N^2) space.

const int maxn = 502;
class Solution {
public:
	int f[maxn][maxn];
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        for (int i = 0; i < n; ++i)
        	f[i][i] = piles[i];

        for (int len = 2; len <= n; ++len)
        	for (int st = 0; st <= n-len; ++st)
        	{
        		int en = st + len - 1;
        		f[st][en] = max(piles[st] - f[st+1][en], 
        			piles[en] - f[st][en-1]);
        	}

        return f[0][n-1] > 0;
    }
};