#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//min:-2147483648  max:2147483647 

class Solution {
public:
      int myAtoi(string str) {
        int len=str.length();
        int ans=0;
        bool flag=0,overflow=0,signal=0,num=0;
        int dig[20],n=0;

        for(int i=0;i<len;i++)
        {
		  if(signal)
		  {
			  if(str[i]<'0' || str[i]>'9')
				  return 0;
		  }
		  if(str[i]=='+'){ signal=1; continue;}
          if(str[i]=='-') { flag=signal=1; continue;}
		  if(str[i]==' ' && n==0) {continue;}
          if(str[i]>='0' && str[i]<='9')
          {
			  int j=i;
			  while(j<len-1  && str[j]=='0' ) j++;
			  if(j>i) j--;
			  
			  while( j<len && str[j]>='0' && str[j]<='9')
			  {
				n++;
				if(n>10){ overflow=1; break;}
				dig[n]=str[j]-'0';
				j++;
			  }
              
			  break;
          }
          else
            break;
        }
		
        if(n==10 && dig[1]>2) overflow=1;
        if(overflow) 
        {
          if(flag) return -2147483648;
          else return 2147483647;
        }
		int weight[]={-1,-10,-100,-1000,-10000,-100000,-1000000,-10000000,-100000000,-1000000000};
        for(int i=n;i>=1;i--)
        {
          if(n==10 && i==1)
              if((!flag && dig[1]==2 && ans<-147483647) || (flag && dig[1]==2 && ans<-147483648))
              {
                overflow=1;
                break;
              }
         
          ans+=dig[i]*weight[n-i];
        }
        if(overflow) 
        {
          if(flag) return -2147483648;
          else return 2147483647;
        }

        if(!flag) ans*=-1;
        return ans;
      }
};


int main()
{
      int ans;
      string s;
      fstream fin("p8.in",ios::in);
      fstream fout("p8.out",ios::out);

//      fin>>s;
	  s=" 1175109307q7";
      Solution a;
      ans=a.myAtoi(s);
      fout<<ans<<endl;
      
	  int i;
	  i=-1000000000;
	  cout<<i<<endl;
	  cin>>i;
      return 0;
}