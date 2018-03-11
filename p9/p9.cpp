#include <iostream>

using namespace std;

bool isPalindrome(int x) {
        
        if(x<0) return false;

        int y=x;
        int dig[40],len=0;
        while(y)
        {
        	dig[len]=y%10;
        	y/=10;
        	len++;
        }

        if(len==1) return true;
        for(int i=0;i<(len>>1);i++)
        	if(dig[i]!=dig[len-1-i]) return false;

        return true;
    }


int main()
{
	int i;
	while(1)
	{
		cin>>i;
		cout<<isPalindrome(i)<<endl;
	}
	//cin>>i;
	return 0;
}