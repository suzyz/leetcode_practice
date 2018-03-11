#include <iostream>
#include <vector>
#include <string>

using namespace std;

    string intToRoman(int num) {
        		string ans;

		int tmp;
		if(num>=1000)
		{
			tmp=num/1000;
			while(tmp)
			{
				ans.push_back('M');
				num-=1000;
				tmp--;
			}
		}

		if(num>=500)
		{	
			if(num>=900) {ans.append("CM");}
			else
			if(num>=800) ans.append("DCCC");
			else
			if(num>=700) ans.append("DCC");
			else
			if(num>=600) ans.append("DC");
			else ans.push_back('D');

			num%=100;
		}

		if(num>=100)
		{
			if(num>=400) ans.append("CD");
			else
			if(num>=300) ans.append("CCC");
			else
			if(num>=200) ans.append("CC");
			else ans.push_back('C');

			num%=100;
		}

		if(num>=50)
		{
			if(num>=90) ans.append("XC");
			else
			if(num>=80) ans.append("LXXX");
			else
			if(num>=70) ans.append("LXX");
			else
			if(num>=60) ans.append("LX");
			else ans.push_back('L');

			num%=10;
		}

		if(num>=10)
		{
			if(num>=40) ans.append("XL");
			else
			if(num>=30) ans.append("XXX");
			else
			if(num>=20) ans.append("XX");
			else ans.push_back('X');

			num%=10;
		}

		if(num>0)
		{
			if(num==9) ans.append("IX");
			else
			if(num==8) ans.append("VIII");
			else
			if(num==7) ans.append("VII");
			else
			if(num==6) ans.append("VI");
			else
			if(num==5) ans.push_back('V');
			else
			if(num==4) ans.append("IV");
			else
			if(num==3) ans.append("III");
			else
			if(num==2) ans.append("II");
			else ans.push_back('I');
		}

	return ans;
    }

int main()
{
	int i;
	vector<string> d;
	string s;

	while(1)
	{
		cin>>i;
		cout<<intToRoman(i)<<endl;
	}

	return 0;
}