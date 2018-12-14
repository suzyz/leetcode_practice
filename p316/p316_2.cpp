// O(N). "Stack".
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        string res;

        vector<bool> used(130);
        vector<int> count(130);

        for (int i = 0; i < n; ++i)
            ++count[s[i]];

        for (int i = 0; i < n; ++i) {
            char c = s[i];

            if (!used[c]) {
                while (res.length() && res.back() > c && count[res.back()]) {
                    used[res.back()] = false;
                    res.pop_back();
                }

                used[c] = true;
                res.push_back(c);
            }

            --count[c];
        }

        return res;
    }
};