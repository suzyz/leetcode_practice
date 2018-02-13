class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n<2)
        	return 0;

        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                if (!st.empty() && s[st.top()] == '(')
                    st.pop();
                else
                    st.push(i);
            }
        }

        if (st.empty())
            return n;

        int maxl = 0;
        int last = n;
        while (!st.empty())
        {
            int cur = st.top();
            st.pop();

            maxl = max(maxl,last-1-cur);
            last = cur;
        }
        maxl = max(maxl,last);

       	return maxl;
    }
};
