#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        int n = s.length();

        vector<vector<bool> > is_palindrome(n,vector<bool>(n,false));

        for (int i = 0; i < n; ++i)
        {
        	helper(s,i,i,is_palindrome);
        	if (i < n-1)
        		helper(s,i,i+1,is_palindrome);
        }

        vector<string> cur;
        vector<vector<string> > res;
        dfs(0,s,cur,is_palindrome,res);

        return res;
    }

    void helper(string &s,int st,int en,vector<vector<bool> > &is_palindrome)
    {
    	while (st >= 0 && en < s.length())
    	{
    		if (s[st] != s[en])
    			return;

    		is_palindrome[st][en] = true;
    		--st;
    		++en;
    	}
    }

    void dfs(int i,string &s,vector<string> &cur,vector<vector<bool> > &is_palindrome,vector<vector<string> > &res)
    {
    	if (i >= s.length())
    	{
    		res.push_back(cur);
    		return;
    	}

    	for (int j = i; j < s.length(); ++j)
    		if (is_palindrome[i][j])
    		{
    			string tmp = s.substr(i,j-i+1);
    			cur.push_back(tmp);
    			dfs(j+1,s,cur,is_palindrome,res);
    			cur.pop_back();
    		}
    }
};

int main(int argc, char const *argv[])
{
	Solution s;

	vector<vector<string> > res = s.partition("aab");

	printf("size:%d\n", res.size());
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		    cout << res[i][j] << " ";
		cout <<endl;
	}
	return 0;
}
