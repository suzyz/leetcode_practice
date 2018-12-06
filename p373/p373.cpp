class Solution {
public:
    struct mycmp
    {
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }
    };

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<pair<int, int>> res;

        k = min(k, m * n);
        if (k == 0)
            return res;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>,
            mycmp> pq;

        for (int i = 0; i < n; ++i)
            pq.push(make_pair(i, nums1[i] + nums2[0]));

        vector<int> idx(n);

        for (int i = 0; i < k; ++i) {
            pair<int, int> cur = pq.top();
            pq.pop();

            int x = cur.first;
            cur.first = nums1[x];
            cur.second = nums2[idx[x]];
            res.push_back(cur);
            ++idx[x];

            if (idx[x] < m)
               pq.push(make_pair(x, nums1[x] + nums2[idx[x]]));
        }

        return res;
    }
};