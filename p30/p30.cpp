#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.length();
        int m=words[0].length();
        vector<int> ans;
        if(n<m*words.size()) return ans;

        map<string,int> window;
        map<string,int> dict;
        for(int i=0;i<words.size();i++)
        	dict[words[i]]++;

        int r;
        string tmp;
        cout<<"end:"<<n-m*words.size()<<endl;
        for(int i=0;i<=n-m*words.size();i++)
        {
        	r=i;
	        window.clear();
	        while(r<=n)
	        {
	       		if(r-i==m*words.size())
	       		{
	       			ans.push_back(i);
	       			break;
	       		}
	       		if(r==n) break;

	        	tmp=s.substr(r,m);
	        	if(dict.find(tmp)==dict.end())
	        		break;

	        	if(window.find(tmp)==window.end() || window[tmp]<dict[tmp])
	        	{
	        		window[tmp]++;
	        		r+=m;
	        	}
	        	else
	        		break;
	        }
        }
        return ans;
    }
};

int main()
{
	Solution sol;

	string s="wordgoodgoodgoodbestword";
	vector<string> v;
	v.push_back("word");
	v.push_back("good");
	v.push_back("best");
	v.push_back("good");

	vector<int> res=sol.findSubstring(s,v);
	cout<<"size:"<<res.size()<<endl;
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;
	return 0;
}