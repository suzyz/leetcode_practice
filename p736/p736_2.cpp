// Also recursive.
class Solution {
public:
    vector<unordered_map<string, int>> scopes;

    int evaluate(string s) {
        if (isdigit(s[0]) || s[0] == '-')
            return atoi(s.c_str());

        if (islower(s[0])) {
            for (int i = scopes.size()-1; i >= 0; --i)
                if (scopes[i].count(s))
                    return scopes[i][s];

            return 0;
        }
        
        int n = s.length();
        vector<string> exprs;

        if (s[1] == 'a' || s[1] == 'm') {
            int st = s[1] == 'a' ? 5 : 6;
            splitExpr(s.substr(st, n-1-st), exprs);

            int a = evaluate(exprs[0]);
            int b = evaluate(exprs[1]);

            return s[1] == 'a' ? a + b : a * b;
        }

        unordered_map<string, int> tmp;
        scopes.push_back(tmp);

        splitExpr(s.substr(5, n-6), exprs);
        int len = exprs.size();

        for (int i = 0; i < len-1; i += 2)
            scopes.back()[exprs[i]] = evaluate(exprs[i+1]);
        
        int ans = evaluate(exprs[len-1]);

        scopes.pop_back();

        return ans;
    }

    void splitExpr(string s, vector<string>& res) {
        int i = 0, n = s.length();
        
        while (i < n) {
            int j = i, count = 0;
            while (j < n) {
                if (s[j] == '(')
                    ++count;
                else
                    if (s[j] == ')')
                        --count;
                    else
                        if (s[j] == ' ' && count == 0)
                            break;

                ++j;
            }
            res.push_back(s.substr(i, j-i));
            i = j+1;
        }
    }
};