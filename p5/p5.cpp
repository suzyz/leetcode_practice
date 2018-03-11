#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static string longestPalindrome(string s) {
        int len=s.length();
		if(len==0) return "";

		int best=1,best_st=0;
		for(int i=0;i<len;i++)
		{
			int j=1;
			while(i+j<len && i-j>=0 && s[i+j]==s[i-j]) j++;
			j--;

			if(2*j+1>best)
			{
				best=2*j+1;
				best_st=i-j;
			}

			if(i<len-1 && s[i]==s[i+1])
			{
				int j=1;
				while(i+j+1<len && i-j>=0 && s[i+j+1]==s[i-j]) j++;
				j--;

				if(2*(j+1)>best)
				{
					best=2*(j+1);
					best_st=i-j;
				}
			}
		}

		char ans[10000];
		s.copy(ans,best,best_st);
		ans[best]='\0';
		string res(ans);
		return res;
    }
};

int main()
{
	string s;
	cin>>s;
	cout<<Solution::longestPalindrome(s)<<endl;

	return 0;
}
