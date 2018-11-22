class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size(), ans = 0;
        set<int> pos(heaters.begin(), heaters.end());

        for (int i = 0; i < n; ++i) {
        	int cur = houses[i], mind = INT_MAX;
        	set<int>::iterator it = pos.lower_bound(cur);

        	if (it != pos.end())
        		mind = *it - cur;
            
        	if (it != pos.begin()) {
        		--it;
        		mind = min(mind, cur - *it);
        	}
            
            // printf("%d:%d\n", i, mind);
        	
        	ans = max(ans, mind);
        }

        return ans;
    }
};