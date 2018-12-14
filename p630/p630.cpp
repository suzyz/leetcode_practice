class Solution {
public:
	const int maxT = 10000;

	struct myCMP
	{
		bool operator() (vector<int>&a, vector<int>& b) {
			if (a[1] == b[1])
				return a[0] < b[0];
			return a[1] < b[1];
		}
	} mycmp;

    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        
        for (int i = 0; i < n; ++i)
            courses[i][1] -= courses[i][0];

        sort(courses.begin(), courses.end(), mycmp);

        priority_queue<int> pq;

        int ans = 0, curTime = 0;
        for (int i = 0; i < n; ++i) {
        	int t = courses[i][0];
        	int lim = courses[i][1] + t;

        	curTime += t;
        	pq.push(t);

        	while (curTime > lim) {
        		curTime -= pq.top();
        		pq.pop();
        	}

        	ans = max(ans, pq.size());
        }
        
        return ans;
    }
};