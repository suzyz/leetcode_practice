// O(N*logK)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,std::greater<int>> h;
        for (int i = 0; i < k && i < n; ++i)
            h.push(nums[i]);

        for (int i = k; i < n; ++i)
            if (nums[i] > h.top())
            {
                h.pop();
                h.push(nums[i]);
            }
        return h.top();
    }
};
