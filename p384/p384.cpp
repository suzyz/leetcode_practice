class Solution {
public:
    int n;
    vector<int> init;
    Solution(vector<int> nums) {
        init = nums;
        n = init.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return init;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> cur(init);
        for (int i = 0; i < n; ++i)
            swap(cur[i],cur[rand()%n]);
        
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
