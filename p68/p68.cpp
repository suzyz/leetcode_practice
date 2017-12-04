#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> justified;

        int space = -1, n = -1, sum = 0;
        vector<int> rem,last;
        for (int i = 0; i < words.size(); ++i)
        {
        	if ((int)words[i].length() > space)
        	{
				int new_space = maxWidth - words[i].length() - 1;

        		++n;
        		last.push_back(i);
        		rem.push_back(maxWidth-sum);
        		space = new_space;
        		sum = words[i].length();
        	}
        	else
        	{
        		sum += words[i].length();
        		space -= words[i].length() + 1;
        		if (space < 0)
        			space = 0;

        		last[n] = i;
        		rem[n] = maxWidth-sum;
        	}
        }

        int st = 0;
        for (int i = 0; i < n; ++i)
        {
        	int k = last[i]-st, r = rem[i];

        	string cur;
        	while (st <= last[i])
        	{
        		cur += words[st];

        		if (st < last[i])
        		{
        			cur += string(ceil(1.0*r/k),' ');
        			r -= ceil(1.0*r/k);
        			--k;
        		}
        		++st;
        	}

        	if (cur.length() < maxWidth)
        		cur += string(maxWidth-cur.length(),' ');

        	justified.push_back(cur);
        }

        if (n >= 0)
        {
        	string cur;
        	while (st <= last[n])
        	{
        		cur += words[st];

        		if (st < last[n])
        			cur += " ";
        		++st;
        	}

        	if (cur.length() < maxWidth)
        		cur += string(maxWidth-cur.length(),' ');

        	justified.push_back(cur);
        }

        return justified;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string words[] = {"This", "is", "an", "example", "of", "text", "justification."};
	string words2[] = {"What","must","be","shall","be."};
	vector<string> v(words,words+7);
	vector<string> v2(words2,words2+5);
	vector<string> v3;
	vector<string> res = s.fullJustify(v2,12);
	//vector<string> res = s.fullJustify(v3,0);
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	return 0;
}
