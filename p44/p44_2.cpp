class Solution {
public:
    bool isMatch(string s, string p) {
        bool is_star = false;
        string::iterator a = s.begin(),b = p.begin(),star,last_a = s.begin();

        while (a!=s.end())
        {
            if (*a == *b || *b == '?')
            {
                ++a;
                ++b;
            }
            else
            if (*b == '*')
            {
                star = b;
                last_a = a;
                is_star = true;
                ++ b;
            }
            else
            if (is_star)
            {
                a = last_a+1;
                last_a = a;
                b = star+1;
            }
            else
                return false;
        }

        while (b!=p.end() && *b == '*')
            ++b;

        return  (b == p.end());
    }
};
