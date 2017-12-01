class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n<2)
        	return 0;

        int ans = 0, len = 0;
        bool last = false;
        stack<char> st;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                    len += 2;
                    ans = max(ans,len);
                }
                else
                    len = 0;
            }
        }

       	return ans;
    }
};
