class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        std::vector<int> ans;
        sort(arr.begin(), arr.end());

        if (x <= arr[0]) {
        	for (int i = 0; i < k; ++i)
        		ans.push_back(arr[i]);

        	return ans;
        }

        if (x >= arr[n-1]) {
        	for (int i = 0; i < k; ++i)
        		ans.push_back(arr[n-1-i]);

        	return ans;
        }

        int lo = 0, hi = n-1;
        while (lo < hi) {
        	int mid = lo + ((hi - lo) >> 1) + 1;

        	if (arr[mid] == x) {
        		lo = hi = mid;
        		break;
        	}

        	if (arr[mid] > x)
        		hi = mid-1;
        	else
        		lo = mid;
        }

        if (k == 1) {
        	ans.push_back(arr[lo]);
        	return ans;
        }

        int st = max(0, lo - k/2), en = min(n, lo + k/2);

        if (en - st < k) {
        	if (en == n)
        		st = n-k;
        	else
        		en = k;
        } 

        while (st > 0 && abs(x - arr[st-1]) < abs(x - arr[en-1])) {
        	--st;
        	--en;
        }

        while (en < n && abs(x - arr[en]) < abs(x - arr[st])) {
        	++st;
        	++en;
        }

        for (int i = st; i < en; ++i)
        	ans.push_back(arr[i]);

        return ans;
    }
};