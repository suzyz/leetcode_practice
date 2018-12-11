class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
        	int cur = asteroids[i];

        	if (cur > 0)
        		ans.push_back(cur);
        	else {
        		while (!ans.empty() && ans.back() > 0 && ans.back() < -cur)
        			ans.pop_back();
        		
        		if (ans.empty() || ans.back() < 0)
        			ans.push_back(cur);
        		else
        			if (ans.back() == -cur)
        				ans.pop_back();
        	}
        }

        return ans;
    }
};