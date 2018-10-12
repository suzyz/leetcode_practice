// Greedy. Priority Queue. O(N*logN) time, O(N) space.
class Solution {
public:
	int f[502][502];
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size(), i = 0, count = 0, maxPos = startFuel;
        priority_queue<int> pq;

        while (maxPos < target) {
            while (i < n && stations[i][0] <= maxPos) {
                pq.push(stations[i][1]);
                ++i;
            }

            if (pq.empty())
                return -1;

            maxPos += pq.top();
            pq.pop();

            ++count;
        }
        
        return count;
    }
};