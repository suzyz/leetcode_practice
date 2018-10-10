// Greedy. O(N) time.

class Solution {
public:

    bool checkValidString(string s) {
        int n = s.length();

        int lo = 0, hi = 0; //左括号的数量的上下界
        for (int i = 0; i < n; ++i)
        {
        	lo += (s[i] == '(' ? 1:-1);
        	hi += (s[i] != ')' ? 1:-1);
        	if (hi < 0) // 必须保持左括号的数量>=0
        		return false;
            
            lo = max(lo, 0); // 必须保持左括号的数量>=0
        }
        
        return lo == 0;
    }
};