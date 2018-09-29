// Using two vectors as queues.
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int kSimilarity(string A, string B) {
        if (A == B)
        	return 0;

        int ans = 1, n = A.length();
        bool flag = false;

        unordered_set<string> vis;
        vis.insert(A);

        vector<string> levels[2];
        levels[0].push_back(A);

        int lastLevel = 0;
        char c;

        while (true) {
        	// cout << "ans:"<< ans << endl;
        	levels[1 - lastLevel].clear();

        	for (int i = 0; i < levels[lastLevel].size(); ++i) {
        		string s = levels[lastLevel][i];

        		int j = 0;
        		while (s[j] == B[j])
        			++j;

        		for (int k = j+1; k < n; ++k)
        			if (s[k] == B[j] && s[k] != B[k]) {
	        			string tmp = s;
                        tmp[j] = s[k];
                        tmp[k] = s[j];

	        			if (tmp == B)
	        				return ans;

	        			if (!vis.count(tmp)) {
	        				levels[1 - lastLevel].push_back(tmp);
	        				vis.insert(tmp);
	        			}
        			}
        	}

	        lastLevel = 1 - lastLevel;
	        ++ans;
        }

        return -1;
    }
};

int main()
{
	Solution s;

	cout << s.kSimilarity("abccaacceecdeea", "bcaacceeccdeaae") << endl;
	// cout << s.kSimilarity("cdebcdeadedaaaebfbcf", "baaddacfedebefdabecc") << endl;

	return 0;
}

