// Brutal BFS.
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int n = S.length();
        deque<string> qu;

        qu.push_back("");

        for (int i = 0; i < n; ++i)
        {
            vector<char> c(1, S[i]);
            if (S[i] >= 'a' && S[i] <= 'z')
                c.push_back(S[i]-'a'+'A');
            else 
                if (S[i] >= 'A' && S[i] <= 'Z')
                    c.push_back(S[i]-'A'+'a');

            int count = qu.size();
            while (count) {
                --count;

                string cur = qu.front();
                qu.pop_front();

                for (int j = 0; j < c.size(); ++j)
                    qu.push_back(cur + c[j]);
            }
        }

        vector<string> res(qu.begin(), qu.end());
        return res;
    }
};