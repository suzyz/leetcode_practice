class Solution {
public:
	struct mycmp
	{
		bool operator() (pair<int,int>& a, pair<int,int>& b) {
			return a.first > b.first;
		}
	};

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> ans(2);

        vector<int> nxt(k);
        priority_queue<pair<int,int>, vector<pair<int,int>>, mycmp> pq;

        int curMax = -1e6;
        for (int i = 0; i < k; ++i) {
            if (nums[i].size() == 0)
                continue;
            
        	nxt[i] = 1;
           	pq.push(make_pair(nums[i][0], i));
           	curMax = max(curMax, nums[i][0]);
        }

        ans[0] = pq.top().first;
        ans[1] = curMax;

        while (!pq.empty()) {
        	int v = pq.top().first, id = pq.top().second;

        	if (nxt[id] == nums[id].size())
        		break;

        	pq.pop();

        	int newv = nums[id][nxt[id]];
        	++nxt[id];

        	pq.push(make_pair(newv, id));
        	curMax = max(curMax, newv);

        	int curMin = pq.top().first;
        	if (curMax - curMin < ans[1] - ans[0]) {
                ans[0] = curMin;
                ans[1] = curMax;
            }
        }

        return ans;
    }
};