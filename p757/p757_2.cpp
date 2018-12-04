// O(N*logN). Greedy.
// Diffirent sort. So no need to eliminate completely overlaping intervals.

bool mycmp(vector<int>& a, vector<int>& b) {
    if (a[1] == b[1])
        return a[0] > b[0];

    return a[1] < b[1];
}

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end(), mycmp);

        int tot = 0, p1 = -1, p2 = -1;

        for (int i = 0; i < n; ++i) {
            if (p1 >= intervals[i][0])
                continue;

       		if (tot == 0 || p2 < intervals[i][0]) {
       			tot += 2;
       			p2 = intervals[i][1];
       			p1 = p2-1;

       		} else {
       			++tot;
       			p1 = p2;
       			p2 = intervals[i][1];
       		}
       	}

       	return tot;
    }
};