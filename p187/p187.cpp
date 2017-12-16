#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> res;

        if (n < 10)
        	return res;

        int trans[100];
        trans['A'] = 0;
        trans['C'] = 1;
        trans['G'] = 2;
        trans['T'] = 3;

        int sub = 0;
        const int mask = (1<<20)-1;
        for (int i = 0; i < 10; ++i)
        	sub = (sub << 2) | trans[s[i]];
        
        unordered_set<int> vis,stored;
        vis.insert(sub);
        printf("9: sub:%d\n", sub);
        for (int i = 10; i < n; ++i)
        {
        	sub = ((sub << 2) | trans[s[i]]) & mask;
        	printf("i:%d sub:%d\n", i,sub);
        	if (vis.count(sub) && !stored.count(sub))
        	{
        		res.push_back(s.substr(i-9,10));
        		stored.insert(sub);
        	}
        	else
        		vis.insert(sub);
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<string> res = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
);
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i)
	{
		cout<< "i:" << i << " " << res[i] << endl;
	}
	return 0;
}
