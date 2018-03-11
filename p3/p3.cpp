#include <iostream>
#include "stdlib.h"

using namespace std;

int main()
{
	char s[100000];
	cin>>s;
	
	int len=strlen(s);
	int ans;
	
	if(len>0) ans=1;
	else ans=0;
	
	int u[260];
	int j,k;
	for(j=0;j<len-1;j++)
	{
		memset(u,0,sizeof(u));
		for(k=j;k<len;k++)
		{
			if(u[s[k]]==0) u[s[k]]=1;
			else
				break;
		}
		ans=ans>(k-j) ? ans:(k-j);
	}
	

	cout<<ans<<endl;
	
	int i;
	cin>>i;

	return 0;
}