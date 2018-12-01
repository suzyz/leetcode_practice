class Solution {
public:
	int n, m;
	vector<int> B;
    
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;

    Solution(int N, vector<int> blacklist) {
    	m = blacklist.size();
    	n = N - m;

        B = blacklist;
        sort(B.begin(), B.end());
        
        std::random_device rd;
        gen = std::mt19937(rd());
        dis = std::uniform_int_distribution<>(0, n-1);
    }
    
    int pick() {
        int k = dis(gen);

        if (m == 0 || k < B[0])
        	return k;

        if (k >= B[m-1])
        	return k + m;
        
        long long lo = 0, hi = m-1;
        while (lo < hi) {
        	long long mid = lo + ((hi - lo) >> 1) + 1;

        	if (B[mid] == k) {
        		lo = hi = mid;
        		break;
        	}

        	if (B[mid] < k)
        		lo = mid;
        	else
        		hi = mid - 1;
        }

        return k + lo;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */