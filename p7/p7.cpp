#include <iostream>
#include <fstream>

using namespace std;
//min:-2147483648  max:2147483647 
#define maxint 2147483647

class Solution {
public:
    int reverse(int x) {
       int dig[20];
       bool flag=0;
	   if(x==-2147483648) return 0;
       if(x==0) return 0;
       if(x<0)
       {
       	flag=1;
       	x*=-1;
       }
       int tmp=x;
       int len=1,i;
       for(i=0;i<10;i++)
       {
       	if(tmp==0){break;}
       	dig[i]=tmp%10;
       	tmp/=10;
		cout<<"i:"<<i<<" dig[i]:"<<dig[i]<<endl;
       }
	   if(tmp>0) return 0;
	   len=i;
	   cout<<len<<endl;
	   if(len==10 && dig[0]>2) return 0;
       int weight=1;
       int ans=0;
       for(i=len-1;i>=0;i--)
       {
       	//if(dig[i]*weight<0 || ans+dig[i]*weight<0) return 0;
		//cout<<"ans:"<<ans<<" dig[i]*w: "<<dig[i]*weight<<" w:"<<weight<<endl;
		//if(dig[i]*weight>maxint) cout<<"no"<<endl;
		if(len==10 && i==0 && dig[0]==2 && ans>147483647) return 0;
       	ans+=dig[i]*weight;
		weight*=10;
       }
       if(flag) ans*=-1;

       return ans;
    }
};


int main()
{
	int n,ans;
	fstream fin("p7.in",ios::in);
	fstream fout("p7.out",ios::out);

	fin>>n;
	Solution a;
	ans=a.reverse(n);
	fout<<ans<<endl;
	cin>>n;
	return 0;
}