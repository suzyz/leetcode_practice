class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0)
            return 0;
        
        sort(citations.begin(),citations.end());

        int st, en;
        for (int i = min(n, citations[n-1]); i > 0; --i) {
            en = n-1;
        	while (en >= 0 && citations[en] > i)
        		--en;
            
            if (en < 0 && i == n)
                return n;

        	if (en < 0)
        		continue;

        	if (citations[en] == i) {
        		st = en;
        		while (st >= 0 && citations[st] == i)
        			--st;

        		if (n-1 - st >= i && st+1 <= n-i)
        			return i;

        		// en = st;

        	} else {
        		if (n-1 - en == i)
        			return i;
        	}
        }

        return 0;
    }
};