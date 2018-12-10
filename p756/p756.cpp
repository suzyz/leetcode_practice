// DFS + DFS. No memorization.
class Solution {
public:
	unordered_map<char, unordered_map<char, vector<char>>> m;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.length();

        for (int i = 0; i < allowed.size(); ++i)
        	m[allowed[i][0]][allowed[i][1]].push_back(allowed[i][2]);
        
        return dfs1(bottom);
    }

    bool dfs1(string& bottom) {
    	if (bottom.length() == 1)
    		return true;

    	string cur;
    	vector<string> possible;

    	dfs2(cur, bottom, possible);

    	for (int i = 0; i < possible.size(); ++i)
    		if (dfs1(possible[i]))
    			return true;

    	return false;
    }

    void dfs2(string& cur, string& bottom, vector<string>& possible) {
    	if (cur.length() == bottom.length()-1) {
    		possible.push_back(cur);
    		return;
    	}

    	int idx = cur.length();
    	char a = bottom[idx], b = bottom[idx+1];

    	for (int i = 0; i < m[a][b].size(); ++i) {
    		cur.push_back(m[a][b][i]);
    		dfs2(cur, bottom, possible);
    		cur.pop_back();
    	}
    }
};