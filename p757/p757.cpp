// O(N*logN). Greedy.
// Handle completely overlaping intervals with stack.

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());

        vector<bool> vis(n);

        // handle completely overlaping intervals
        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
        	while (!st.empty() && intervals[st.top()][1] >= intervals[i][1]) {
        		vis[st.top()] = true;
        		st.pop();
        	}

        	st.push(i);
        }

        int tot = 0, p1, p2;

        for (int i = 0; i < n; ++i)
       		if (!vis[i]) {
       			if (tot == 0 || p2 < intervals[i][0]) {
       				tot += 2;
       				p2 = intervals[i][1];
       				p1 = p2-1;

       				continue;
       			}

       			if (p1 < intervals[i][0]) {
       				++tot;
       				p1 = p2;
       				p2 = intervals[i][1];
       			}
       		}

       	return tot;
    }
};