// DP. O(N^2) time, O(N^2) space.
class Solution {
public:
	int f[502][502];
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        if (n == 0) {
        	if (startFuel >= target)
        		return 0;
        	else
        		return -1;
        }

        if (startFuel < stations[0][0])
        	return -1;

        memset(f, -1, sizeof(f));
        f[0][0] = startFuel - stations[0][0];
        f[0][1] = f[0][0] + stations[0][1];

        for (int i = 0; i < n-1; ++i)
        {
        	int diff = stations[i+1][0] - stations[i][0];

        	for (int j = 0; j <= i+1; ++j)
        		if (f[i][j] >= diff)
        		{
        			f[i+1][j] = max(f[i+1][j], f[i][j] - diff);
        			f[i+1][j+1] = max(f[i+1][j+1], f[i][j] - diff + stations[i+1][1]);
        		}
        }

        int lastDiff = target - stations[n-1][0];
        for (int i = 0; i <= n; ++i)
        	if (f[n-1][i] >= lastDiff)
        		return i;

        return -1;
    }
};