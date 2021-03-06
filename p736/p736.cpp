// Recursive.
class Solution {
public:
    int evaluate(string s) {
        unordered_map<string,int> dict;
        return helper(s, dict);
    }

    int helper(string s, unordered_map<string,int>& dict) {
        if (isdigit(s[0]) || s[0] == '-')
            return atoi(s.c_str());

        if (islower(s[0]))
            return dict[s];
        
        int n = s.length();
        vector<string> exprs;

        if (s[1] == 'a' || s[1] == 'm') {
            int st = s[1] == 'a' ? 5 : 6;
            splitExpr(s.substr(st, n-1-st), exprs);

            int a = helper(exprs[0], dict);
            int b = helper(exprs[1], dict);

            return s[1] == 'a' ? a + b : a * b;
        }

        splitExpr(s.substr(5, n-6), exprs);
        
        int len = exprs.size();
        unordered_map<string,int> newDict = dict;

        for (int i = 0; i < len-1; i += 2)
            newDict[exprs[i]] = helper(exprs[i+1], newDict);
        
        return helper(exprs[len-1], newDict);
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