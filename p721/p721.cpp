class Solution {
public:
    int getfa(int cur, vector<int>& fa) {
        if (fa[cur] == cur)
            return cur;
        
        fa[cur] = getfa(fa[cur], fa);
        return fa[cur];
    }
    
    void unify(int a, int b, vector<int>& fa) {
        int x = getfa(a, fa);
        int y = getfa(b, fa);
        
        if (x != y)
            fa[x] = y;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& data) {
        int n = data.size(), tot = 0;
        unordered_map<string, string> name;

        vector<string> emails;
        unordered_map<string, int> idx;
        
        for (int i = 0; i < n; ++i) 
            for (int j = 1; j < data[i].size(); ++j) {
                name[data[i][j]] = data[i][0];

                if (!idx.count(data[i][j])) {
                    emails.push_back(data[i][j]);
                    idx[data[i][j]] = tot++;
                }
            }
        
        vector<int> fa(tot);
        for (int i = 0; i < tot; ++i)
            fa[i] = i;

        for (int i = 0; i < n; ++i)
            if (data[i].size() > 2) {
                int x = idx[data[i][1]];
                for (int j = 2; j < data[i].size(); ++j)
                    unify(x, idx[data[i][j]], fa);
            }

        unordered_map<int, unordered_set<string>> s;

        for (int i = 0; i < tot; ++i)
            s[getfa(i, fa)].insert(emails[i]);

        vector<vector<string>> res;
        for (unordered_map<int, unordered_set<string>>::iterator i = s.begin();
            i != s.end(); ++i) {
            res.push_back(vector<string>());

            unordered_set<string>::iterator j = i->second.begin();
            res.back().push_back(name[*j]);
            for ( ; j != i->second.end(); ++j)
                res.back().push_back(*j);
        }

        for (int i = 0; i < res.size(); ++i)
            sort(res[i].begin()+1, res[i].end());

        return res;
    }
};