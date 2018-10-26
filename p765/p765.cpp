// Take all couples as vertex in a graph.

// For even i, if a person from couple u and a person from couple v sit on position i and i+1,
// then connect u and v.

// Suppose finally we have T components and they have n1, n2,...,nT vertex respectively.
// Obviously n1 + n2 + ... + nT = n.
// For each component we only need ni - 1 swaps (Think about permutation!) to make all couples
// in this component holding hands.
// So in total we need n1 - 1 + n2 - 1 + ... + nT - 1 = n - 1 swaps.

class Solution {
public:
	int fa[32];
    int minSwapsCouples(vector<int>& row) {
        int n = row.size()/2;
        int components = n;

        for (int i = 0; i < n; ++i)
        	fa[i] = i;

        for (int i = 0; i < n; ++i)
        {
        	int a = row[2*i]/2, b = row[2*i+1]/2;

        	if (a == b)
        		continue;

        	int u = getFa(a), v = getFa(b);
        	if (u != v)
        	{
        		fa[u] = v;
        		--components;
        	}
        }

        return n - components;
    }

    int getFa(int cur) {
    	if (fa[cur] == cur)
    		return fa[cur];

    	fa[cur] = getFa(fa[cur]);
    	return fa[cur];
    }
};