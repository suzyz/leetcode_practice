class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();
        bool f[n+2];
       	memset(f,0,sizeof(f));
       	f[0] = true;
       	for (int i = 1; i <= n; ++i)
       	{
            for (int j = i-1; j >= 0; --j)
                if (f[j])
                {
                    string t = s.substr(j, i-j);
                    if (dict.count(t))
                    {
                        f[i] = true;
                        break;
                    }
                }
        }

       	return f[n];
    }
};
