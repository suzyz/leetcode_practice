#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        vector<string> res;
        if (n < 4 || n > 12)
        	return res;

        vector<int> pos(3,0);
        dfs(0,0,n,s,pos,res);

        return res;
    }

    void dfs(int st,int num,int n,string &s,vector<int> &pos,vector<string> &res)
    {
    	if (num == 3)
    	{
    		if (s[pos[2]+1] == '0' && pos[2] < n-2)
    			return;

    		if (n-pos[2]-1 > 3)
    			return;

    		string tmp = s.substr(pos[2]+1,n-pos[2]-1);
    		int d = atoi(tmp.c_str());
    		if (d > 255)
    			return;

    		string cur = s;
    		for (int j = 0; j < 3; ++j)
    			cur.insert(pos[j]+j+1,1,'.');
    		res.push_back(cur);
    		return;
    	}
    	if (st >= n || num >= 3)
    		return;

    	for (int i = st; i < n-1 && i-st+1 < 4; ++i)
    	{
    		if (s[st] == '0' && i > st)
    			return;

    		string tmp = s.substr(st,i-st+1);
    		int d = atoi(tmp.c_str());
    		//printf("st:%d i:%d tmp:%s d:%d\n", st,i,tmp.c_str(),d);
    		if (d > 255)
    			continue;
    		pos[num] = i;
    		dfs(i+1,num+1,n,s,pos,res);
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<string> res = s.restoreIpAddresses("000022");
	cout <<"size:" << res.size() << endl;
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	return 0;
}
