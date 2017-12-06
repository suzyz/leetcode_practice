// O(N^2)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 2)
        	return 0;

        int sum = 0;
        vector<pair<int,int>> h;
        
        for (int i = 0; i < n; ++i)
        {
        	if (height[i] == 0)
        		continue;

        	if (!h.empty())
        	{
        		sum += (i - h.back().first - 1) * min(h.back().second, height[i]);

        		int last = h.back().second;
        		for (int j = h.size()-2; j >= 0 && last <= height[i]; --j)
        		{
        			if (i > h[j].first)
        				sum += (i - h[j].first - 1) * (min(h[j].second,height[i]) - last);
        			last = h[j].second;
        		}
        	}
        	
        	while (!h.empty() && h.back().second < height[i])
        		h.pop_back();

        	h.push_back(make_pair(i,height[i]));
        }

        return sum;
    }
};
