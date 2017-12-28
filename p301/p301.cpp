class Solution {
public:
	const char parentheses[2][2] = {{'(',')'}, {')','('}};

    vector<string> removeInvalidParentheses(string s) {
       	vector<string> ans;

       	dfs(0,0,0,s,ans);

       	return ans;
    }

    void dfs(int st,int last_remove,int idx,string s,vector<string> &ans)
    {
    	int count = 0;
    	for (int i = st; i < s.length(); ++i)
    	{
    		if (s[i] == parentheses[idx][0]) 
    			++count;
    		else
    		if (s[i] == parentheses[idx][1])
    			--count;

    		if (count < 0)
    		{
    			for (int j = last_remove; j <= i; ++j)
    				if (s[j] == parentheses[idx][1] && (j == last_remove || s[j-1] != parentheses[idx][1]))
    					dfs(i,j,idx,s.substr(0,j) + s.substr(j+1,s.length()), ans);
    			return;
    		}
    	}

    	string rev = s;
    	reverse(rev.begin(), rev.end());

    	if (idx == 0)
    		dfs(0,0,1,rev,ans);
    	else
    		ans.push_back(rev);
    }
};
