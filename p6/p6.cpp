#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string convert(string s, int numRows) {
    if(numRows<=1) return s;

    int len=s.length();
    string res=s;

    int p=0,q,q2;
    int d=(numRows-1)<<1;

    for(int i=0;i<numRows;i++)
    {
    	q=i;
    	q2=d-i;
    	while(q<len)
    	{
    		res[p]=s[q];
    		p++;
    		q+=d;
    		if(i>0 && i<numRows-1 && q2<len)
            {
                res[p]=s[q2];
                p++;
                q2+=d;
            }
    	}
    }

    return  res;
}


int main()
{
	string s;
	int n;
	fstream fin("p6.in",ios::in);
	fstream fout("p6.out",ios::out);

	fin>>s;
	fin>>n;
	fout<<convert(s,n)<<endl;

	return 0;
}
