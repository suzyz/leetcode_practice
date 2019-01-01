// O(N^2)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for (int i = 0; i < n-2; ++i) {
            int a = nums[i], st = i+2, en = i+2;
            for (int j = i+1; j < n-1; ++j) {
                int b = nums[j];

                st = max(st, j+1);
                while (st < n && nums[st] <= b-a)
                    ++st;

                if (st == n)
                    break;
                
                if (nums[st] >= a+b)
                    continue;

                en = max(en, st);
                while (en+1 < n && nums[en+1] < a+b)
                    ++en;
                
                ans += en - st + 1;
            }
        }
        
        return ans;
    }
};