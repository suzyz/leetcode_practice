// f[i][j]: i至j堆石头，先手至多超出后手多少。
// After optimizing, we can use only O(N) space.

const int maxn = 502;
class Solution {
public:
	int f[maxn];
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        for (int i = 0; i < n; ++i)
        	f[i] = piles[i];

        for (int len = 2; len <= n; ++len)
        	for (int st = 0; st <= n-len; ++st)
        	{
        		int en = st + len - 1;
        		f[st] = max(piles[st] - f[st+1], 
        			piles[en] - f[st]);
        	}

        return f[0] > 0;
    }
};