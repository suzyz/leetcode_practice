class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();
        bool f[n+2];
       	memset(f,0,sizeof(f));
       	f[0] = true;
       	for (int i = 0; i < n; ++i)
       		if (f[i])
       		{
       			for (int j = i+1; j <= n; ++j)
       				if (!f[j])
       				{
       					string t = s.substr(i,j-i);
       					if (dict.count(t))
       						f[j] = true;
       				}

       			if (f[n])
       				break;
       		}

       	return f[n];
    }
};
