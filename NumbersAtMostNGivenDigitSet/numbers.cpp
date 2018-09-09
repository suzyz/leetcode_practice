class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int m = D.size();
       	bool isInSet[11];
       	memset(isInSet, 0, sizeof(isInSet));

        for (int i = 0; i < m; ++i)
        {
        	isInSet[D[i][0]-'0'] = true;
        }

        int digits[10], l = 0, n = N;
        while (n > 0) {
        	digits[l] = n%10;
        	n /= 10;
        	l++;
        }

        long long res = 0;
        for (int i = 1; i < l; ++i)
        	res += pow(m, i)
        
        n = N;

        bool flag  = true;

        for (int i = l-1; i >= 0; --i)
        {
        	int lo = 0;
        	for (int j = 1; j < digits[i]; ++j)
        	{
        		if (isInSet[j])
        			lo++;
        	}

        	if (lo > 0) {
        		res += pow(m, i) * lo;
        	}

        	if (!isInSet[digits[i]]) {
        		flag = false;
        		break;
        	}
        }

       	if (flag) {
       		res++;
       	}

       	return res;
    }
};