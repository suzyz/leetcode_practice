class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 1, r = A.size()-1;

        while (l < r) {
        	int mid = l + ((r-l)>>1);

        	if (A[mid] > A[mid+1]) {
        		r = mid;
        	} else {
        		l = mid+1;
        	}
        }

        return l;
    }
};