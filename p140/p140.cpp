// Memory Search

class Solution {
private:
    unordered_map<string, vector<string>> m;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<string> tmp;
        m[""] = tmp;

        dfs(s, dict);

        return m[s];
    }

    void dfs(string s, unordered_set<string> &dict)
    {
        if(m.count(s))
            return;

        vector<string> res;
        if (dict.count(s))
            res.push_back(s);

        for (int i = 1; i < s.length(); ++i)
        {
            string pre = s.substr(0, i);
            if (!dict.count(pre))
                continue;

            string rem = s.substr(i, s.length() - i);
            dfs(rem, dict);
            for (int j = 0; j < m[rem].size(); ++j)
            {
                string tmp = pre + " " + m[rem][j];
                res.push_back(tmp);
            }
        }

        m[s] = res;
    }
};
