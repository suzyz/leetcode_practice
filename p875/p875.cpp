class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1, hi = 1;
        for (int i = 0; i < piles.size(); ++i)
        	if (piles[i] > hi) {
        		hi = piles[i];
        	}
       
        while (lo < hi) {
        	int mid = lo + ((hi-lo)>>1);

        	if (check(mid, H, piles)) {
        		hi = mid;
        	} else {
        		lo = mid+1;
        	}
        }

        return lo;
    }

    bool check(int speed, int H, vector<int>& piles) {
    	int h = 0;
    	for (int i = 0; i < piles.size(); ++i) {
    		h += piles[i]/speed;
    		if (piles[i]%speed)
    			h++;

    		if (h > H) {
    			return false;
    		}
    	}

    	return true;
    }
};
