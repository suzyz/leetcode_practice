class Solution {
public:
	int n, m;
    unordered_map<int, unordered_set<int>> used;

    Solution(int n_rows, int n_cols) {
        n = n_rows;
        m = n_cols;
    }
    
    vector<int> flip() {
        int x = rand()%n, y = rand()%m;
        while (used[x].count(y)) {
        	x = rand()%n;
        	y = rand()%m;
        }

        used[x].insert(y);
        
        vector<int> res(2);
        res[0] = x;
        res[1] = y;
        return res;
    }
    
    void reset() {
        used.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */