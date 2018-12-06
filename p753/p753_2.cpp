// DFS.
class Solution {
public:
	string ans;
	vector<string> s;
	unordered_set<string> vis;

    string crackSafe(int n, int k) {
    	if (n == 1) {
    		for (int i = 0; i < k; ++i)
    			ans += (char)('0' + i);
    		return ans;
    	}

        ans = string(n, '0');
        vis.insert(ans);

        dfs(1, pow(k, n), n, k);

        return ans;
    }

    bool dfs(int count, int tot, int n, int k) {
    	if (count == tot)
    		return true;

        string firstPart = ans.substr(ans.length()-n+1);

    	for (int i = 0; i < k; ++i)
    	{
    		string t = firstPart + (char)('0'+i);
            if (!vis.count(t)) {
                ans.push_back('0'+i);
                vis.insert(t);

                if (dfs(count+1, tot, n, k))
                    return true;

                ans.pop_back();
                vis.erase(t);
            }
    	}

    	return false;
    }
};