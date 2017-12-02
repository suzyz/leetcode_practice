class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n<2)
        	return 0;

        int maxl = 0;
        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                if (!st.empty() && s[st.top()] == '(')
                {
                    //
                    st.pop();
                    //maxl = max(i-1-cu)
                }
                else
                if (st.empty())
                {
                    st.push(i);
                    maxl = max(i,maxl);
                }
                else
                {
                    int cur = st.top();
                    st.pop();
                    maxl = max(maxl,i-1-cur);
                    st.push(i);
                }
            }
        }

        if (st.empty())
            return n;

        maxl = max(maxl,n-1-st.top());   
       	return maxl;
    }
};
