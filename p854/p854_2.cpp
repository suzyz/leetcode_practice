// Using a queue.
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int kSimilarity(string A, string B) {
        if (A == B)
        	return 0;

        int ans = 1, n = A.length();

        unordered_set<string> vis;
        vis.insert(A);

        queue<string> qu;
        qu.push(A);

        while (true) {
        	// cout << "ans:"<< ans << endl;
        	
            int num = qu.size();
            while (num > 0) {
                --num;

                string s = qu.front();
                qu.pop();

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
                            qu.push(tmp);
                            vis.insert(tmp);
                        }
                    }
            }

	        ++ans;
        }

        return -1;
    }
};

int main()
{
	Solution s;

	// cout << s.kSimilarity("abccaacceecdeea", "bcaacceeccdeaae") << endl;
	cout << s.kSimilarity("cdebcdeadedaaaebfbcf", "baaddacfedebefdabecc") << endl;

	return 0;
}

