// Sort + Greedy. O(N*logN)

bool mycmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size(), ans = 0;

        sort(pairs.begin(), pairs.end(), mycmp);

        int lastEnd = INT_MIN;
        for (int i = 0; i < n; ++i)
            if (pairs[i][0] > lastEnd)
            {
                ++ans;
                lastEnd = pairs[i][1];
            }
        
        return ans;
    }
};