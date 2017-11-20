class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<string> res;
        // if (n==0)
        // 	return res;

        int count[300];
        memset(count,0,sizeof(count));
        
        for (int i = 0; i < wordDict.size(); ++i)
        	for (int j = 0; j < wordDict[i].length(); ++j)
        		++count[wordDict[i][j]];

        for (int i = 0; i < n; ++i)
        	if (count[s[i]] == 0)
        		return res;

        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        bool insert_space[n+2];
        memset(insert_space,0,sizeof(insert_space));

        dfs(0,-1,n,s,insert_space,dict,res);

        return res;
    }

    void dfs(int cur,int last,int n,string &s,bool *insert_space,unordered_set<string>& dict,vector<string>& res)
    {
    	if (cur == n-1)
    	{
	    	string tmp = s.substr(last+1,cur-last);
	    	if (!dict.count(tmp))
	    		return;    			

    		string t = s;
    		int k = 1;
    		for (int i = 0; i < n-1; ++i)
    			if (insert_space[i])
    			{
    				t.insert(i+k,1,' ');
    				++k;
    			}

    		res.push_back(t);
    		return;
    	}

    	dfs(cur+1,last,n,s,insert_space,dict,res);

    	string tmp = s.substr(last+1,cur-last);

    	if (!dict.count(tmp))
    		return;

    	insert_space[cur] = true;
    	dfs(cur+1,cur,n,s,insert_space,dict,res);
    	insert_space[cur] = false;
    }
};
