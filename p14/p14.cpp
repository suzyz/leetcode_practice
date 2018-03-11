#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if(strs.size()==0) return "";
	if(strs.size()==1) return strs[0];

	string s;
	int max=strs[0].length();
	int n=strs.size();
	for(int i=1;i<n;i++)
	{
		max=strs[i].length()<max ? strs[i].length():max;
	}
	if(max==0) return "";

	bool flag;
	int i=0;
	while(i<max)
	{
		flag=1;
		for(int j=1;j<n;j++)
			if(strs[j][i]!=strs[0][i])
			{
				flag=0;
				break;
			}

		if(!flag) break;
		s.push_back(strs[0][i]);
		i++;
	}

	return s;
}


int main()
{
	int i;
	vector<string> d;
	string s;

	while(1)
	{
		d.clear();
		for(int i=0;i<4;i++){ cin>>s; d.push_back(s);}
		s=longestCommonPrefix(d);
			cout<<s<<endl;
	}

	return 0;
}