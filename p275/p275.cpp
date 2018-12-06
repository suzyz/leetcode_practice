class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0)
        	return 0;

        int lo = 0, hi = n-1;
        while (lo <= hi) {
            int mid = lo + ((hi-lo)>>1);
            
            if (citations[mid] == n - mid)
                return citations[mid];
            
            if (citations[mid] < n - mid)
                lo = mid+1;
            else
                hi = mid-1;
        }

        return n - hi - 1;
    }
};