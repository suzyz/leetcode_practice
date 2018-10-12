// DP. O(N^2) time, O(N) space.
class Solution {
public:
	int f[502];
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
        f[0] = startFuel - stations[0][0];
        f[1] = f[0] + stations[0][1];

        for (int i = 1; i < n; ++i)
        {
        	int diff = stations[i][0] - stations[i-1][0];

        	for (int j = i+1; j >= 0; --j)
        	{
                if (f[j] >= diff)
                    f[j] -= diff;
                else
                    f[j] = -1;

                if (j > 0 && f[j-1] >= diff)
                    f[j] = max(f[j], f[j-1] - diff + stations[i][1]);
            }
        }

        int lastDiff = target - stations[n-1][0];
        for (int i = 0; i <= n; ++i)
        	if (f[i] >= lastDiff)
        		return i;

        return -1;
    }
};