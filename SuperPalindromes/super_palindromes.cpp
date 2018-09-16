class Solution {
public:
	long long l = 0, r = 0, lo, hi;
	int loLength = 0, hiLength = 0, ans = 0;

	int digits[20], d[20];

	void check(long long v) {
		int len = 0;
		while (v > 0) {
			d[len] = v%10;
			v /= 10;

			len++;
		}

		int i = 0, j = len-1;
		while (i < j) {
			if (d[i] != d[j])
				return;
			i++;
			j--;
		}

		ans++;
	}

	void dfs(int cur, int tot) {
		if (cur > (tot+1)/2) {
			int v = 0;
			for (int i = 1; i < cur; ++i)
				v = 10*v + digits[i];

			if (tot&1)
				for (int i = cur-2; i > 0; --i)
					v = 10*v + digits[i];
			else 
				for (int i = cur-1; i > 0; --i)
					v = 10*v + digits[i];
				
			if (v < lo || v > hi)
				return;
            
            // cout << "v:" << v << endl;

			long long vv = v;
			vv *= vv;
			if (vv >= l && vv <= r)
				check(vv);

			return;
		}

		for (int i = 0; i <= 9; ++i) {
			if (cur == 1 && i == 0)
				continue;

			digits[cur] = i;
			dfs(cur+1, tot);
		}
	}

    int superpalindromesInRange(string L, string R) {
       
        for (int i = 0; i < L.length(); ++i)
        	l = l*10 + L[i]-'0';

		for (int i = 0; i < R.length(); ++i)
        	r = r*10 + R[i]-'0';

        lo = ceil(sqrt(l));
        hi = floor(sqrt(r));
        // cout << l << " " << r << " " << lo << " " << hi<< endl;
        long long tmp = lo;
        while (tmp > 0) {
        	tmp /= 10;
        	loLength++;
        }

        tmp = hi;
        while (tmp > 0) {
        	tmp /= 10;
        	hiLength++;
        }
        
        cout <<  loLength << " " << hiLength<< endl;

        for (int i = loLength; i <= hiLength; ++i)
        	dfs(1, i);

        return ans;
    }
};