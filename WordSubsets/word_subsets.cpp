// O(N). After contest.
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    	int n = A.size(), m = B.size();

    	vector<string> res;
    	
        vector<int> maxCount(26, 0);

    	for (int i = 0; i < B.size(); ++i) {
            vector<int> curCount(26, 0);
            for (int j = 0; j < B[i].length(); ++j)
                ++curCount[B[i][j]-'a'];

            for (int j = 0; j < 26; ++j)
                maxCount[j] = max(maxCount[j], curCount[j]);
        }
    		

        for (int i = 0; i < n; ++i) {
 			vector<int> curCount(26, 0);

            for (int j = 0; j < A[i].length(); ++j)
                ++curCount[A[i][j]-'a'];

            bool flag = true;
            for (int j = 0; j < 26; ++j)
                if (curCount[j] < maxCount[j]) {
                    flag = false;
                    break;
                }

        	if (flag)
        		res.push_back(A[i]);
        }

        return res;
    }
};