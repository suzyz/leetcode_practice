#include <iostream>
#include <string>

using namespace std;

int romanToInt(string s) {
 	int ans=0;
 	int v[300];
 	memset(v,0,sizeof(v));
 	v['I']=1; v['V']=5; v['X']=10; v['L']=50; v['C']=100; v['D']=500; v['M']=1000;

 	int i=0,len=s.length();
 	while(i<len)
 	{
 		if(i<len-1 && (s[i]=='I' || s[i]=='X' || s[i]=='C'))
 		{
 			int j=i;
 			while(j<len && j-i<=3 && s[j]==s[i]) j++;
 			if(j==len)
 			{
 				ans+=v[s[i]]*(len-i);
 				return ans;
 			}
 			else
 			if(j-i>3 || v[s[j]]<v[s[i]])
 			{
 				ans+=v[s[i]];
 				i++;
 				continue;
 			}
 			else
 			{
 				ans+=v[s[j]]-v[s[i]]*(j-i);
 				i=j+1;
 				continue;
 			}
 		}
 		else
 		{
 			ans+=v[s[i]];
 			i++;
 		}
	}

	return ans;
}


int main()
{
	int i;
	string s;
	while(1)
	{
		cin>>s;
		cout<<romanToInt(s)<<endl;
	}

	return 0;
}