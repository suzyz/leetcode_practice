class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if (k == n)
        	return "0";

        vector<char> st;
        for (int i = 0; i < n; ++i)
        {
        	while (!st.empty() && st.back() > num[i] && k > 0)
        	{
                st.pop_back();
                --k;
            }	
            
            st.push_back(num[i]);
        }

        // remove redundant numbers from the tail

        while (k > 0)
        {
            st.pop_back();
            --k;
        }

        // remove leading zeroes
        int i = 0;
        while (i < st.size()-1 && st[i] == '0')
            ++i;
        
        string ans(st.begin() + i, st.end());
        
        return ans;
    }
};