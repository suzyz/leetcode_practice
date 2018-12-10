class Solution {
public:
	int n, tot;
	vector<int> sum;

	std::mt19937 gen;
    std::uniform_int_distribution<> dis;

    Solution(vector<int> w) {
        sum = w;
        n = sum.size();

        for (int i = 1; i < n; ++i)
        	sum[i] += sum[i-1];

        tot = sum[n-1];

        std::random_device rd;
        gen = std::mt19937(rd());
        dis = std::uniform_int_distribution<>(1, tot);
    }
    
    int pickIndex() {
        int v = dis(gen);
        if (v <= sum[0])
        	return 0;

        int lo = 1, hi = n-1;
        while (lo < hi) {
        	int mid = lo + ((hi-lo)>>1);

        	if (sum[mid] < v)
        		lo = mid+1;
        	else
        		hi = mid;
        }

        return lo;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */