#include <iostream>
#include <time.h>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int> > findSubsequences(vector<int>& nums) {
        vector<vector<int> > ans, cur;
        cur.push_back(vector<int>());

        unordered_map<int, int> m;

        int n = nums.size(), st;
        for (int i = 0; i < n; ++i) {
            if (m.count(nums[i]))
                st = m[nums[i]];
            else 
                st = 0;

            int lim = cur.size();
            m[nums[i]] = lim;
            for (int j = st; j < lim; j++) {
                if (cur[j].size() > 0 && nums[i] < cur[j].back())
                    continue;

                cur.push_back(cur[j]);
                cur.back().push_back(nums[i]);

                if (cur.back().size() >= 2)
                    ans.push_back(cur.back());
            }
        }

        return ans;
    }
};

int main() {
    int d1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    double t1, t2;
    Solution s;
    vector<int> v(d1, d1+15);

    t1 = clock();
    s.findSubsequences(v);
    t2 = clock();
    printf("%f ms\n", (t2-t1)*1000/CLOCKS_PER_SEC);

    return 0;
}
