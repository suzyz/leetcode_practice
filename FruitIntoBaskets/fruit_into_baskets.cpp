class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size(), ans = 0;

        vector<int> maxl(n,1);

        for (int i = 1; i < n; ++i)
        	if (tree[i-1] == tree[i])
        		maxl[i] = maxl[i-1]+1;

        int j = n-1, i = n-1-maxl[n-1];

        while (j >= 0) {
        	if (i < 0) {
        		if (maxl[j] > ans)
        			ans = maxl[j];

        		return ans;
        	}

        	int sum = maxl[i] + maxl[j];
        	int pre = i - maxl[i];
        	if (pre >= 0 && tree[pre] == tree[j]) {

        		while (pre >= 0 && tree[pre] == tree[j]) {
        			sum += maxl[pre];

        			j = i;
        			i = pre;
        			pre = i - maxl[i];
        		}
        		
        		if (sum > ans)
        			ans = sum;

        	} else {
        		if (sum > ans)
        			ans = sum;

        		j = i;
        		i = pre;
        	}
        }

        return ans;
    }
};