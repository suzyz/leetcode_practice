class Solution {
public:
	struct Scope
	{
		string name;

		int val;
		unordered_map<string, int> m;

		Scope(string s) { name = s; }
	};

    int evaluate(string expression) {
        int n = expression.length(), ans = 0;
        if (isdigit(expression[0])) {
        	for (int i = 0; i < n; ++i)
        		ans = 10 * ans += expression[i]-'0';
        	return ans;
        }

        stack<Scope> st;

        int i = 0;
        string lastName;

        while (i < n) {
        	if (s[i] == '(') {
        		st.push(Scope(lastName));
        		++i;

        		continue;
        	}

        	if (s[i] == ')') {
        		string 
        	}
        }

        return ans;
    }
};