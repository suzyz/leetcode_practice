// O(N). Nearly brutal..
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length(), tot = 0;

        vector<bool> vis(26);
        vector<int> count(26);

        for (int i = n-1; i >= 0; --i) {
        	int c = s[i] - 'a';
        	count[c] = tot;

        	if (!vis[c]) {
        		vis[c] = true;
        		++tot;
        	}
        }

        string res(tot, 'a');

        for (int i = 0; i < tot; ++i) {
        	char best;
        	int maxCount = 0;

        	for (int j = 0; j < 26; ++j)
        		if (vis[j] && count[j] > maxCount) {
        			best = 'a' + j;
        			maxCount = count[j];
        		}

        	res[i] = best;
        	vis[best-'a'] = false;

        	if (i == tot-1)
        		break;


        	count = vector<int>(26, 0);
        	vector<bool> seen(26);

        	int sum = 0;
        	for (int j = n-1; j >= 0; --j) {
        		int c = s[i] - 'a';
        		if (vis[c]) {
        			count[i] = sum;

        			if (!seen[c]) {
        				seen[c] = true;
        				++sum;
        			}
        		}
        	}
        }

        return res;
    }
};