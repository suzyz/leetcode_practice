// Brutal DFS.
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;

        dfs(0, S.length(), S, res);

        return res;
    }

    void dfs(int i, int n, string& s, vector<string>& res) {
    	if (i >= n)
    	{
    		res.push_back(s);
    		return;
    	}

		dfs(i+1, n, s, res);

    	if (s[i] >= 'a' && s[i] <= 'z')
    	{
    		s[i] -= 'a'-'A';
    		dfs(i+1, n, s, res);
    		// s[i] += 'a'-'A';
    	} else
    		if (s[i] >= 'A' && s[i] <= 'Z')
    		{
    			s[i] += 'a'-'A';
    			dfs(i+1, n, s, res);
    		}
    }
};