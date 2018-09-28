// Union find.
class Solution {
public:

	bool isSimilar(string& a, string& b) {
		int count = 0;
		for (int i = 0; i < a.length(); ++i)
			if (a[i] != b[i]) {
				++count;

				if (count > 2)
					return false;
			}

		return true;
	}

	int getfa(int cur, vector<int>& fa) {
        if (fa[cur] == -1)
            return cur;

        fa[cur] = getfa(fa[cur], fa);
        return fa[cur];
    }

    int numSimilarGroups(vector<string>& A) {
        int n = A.size(), ans = n;
        if (n < 2)
            return n;

        vector<int> fa(n, -1);

        for (int i = 0; i < n; ++i)
        	for (int j = i+1; j < n; ++j) {
        		if (isSimilar(A[i], A[j])) {
        			int a = getfa(i, fa);
                    int b = getfa(j, fa);

                    if (a != b) {
                        fa[a] = b;
                        --ans;
                    }
        		}
        	}

        return ans;
    }
};