// Brutal DFS. Surprised that it got AC, not TLE.
class Solution {
public:
	int n, lefts = 0, rights = 0;
	bool ans = false;
	string str;

	bool isValid() {
		if (lefts != rights)
			return false;

		stack<char> st;
		for (int i = 0; i < n; ++i)
			if (str[i] == '(')
				st.push('(');
			else if (str[i] == ')') {
				if (st.empty() || st.top() != '(')
					return false;
				st.pop();
			}
		
		return st.empty();
	}

	void dfs(int cur) {
		if (cur >= n) {
			if (isValid())
				ans =  true;

			return;
		}

		if (str[cur] == '(') {
			++lefts;
			dfs(cur+1);
			--lefts;
		} else
			if (str[cur] == ')') {
				++rights;
				if (rights > lefts) {
					--rights;
					return;
				}

				dfs(cur+1);
				--rights;
			} else {
				str[cur] = '(';
				++lefts;
				dfs(cur+1);

				if (ans)
					return;

				str[cur] = ')';
				--lefts;
				++rights;

				if (rights <= lefts) {
					dfs(cur+1);
				}

				if (ans)
					return;

				--rights;
				str[cur] = '*';

				dfs(cur+1);
			}
	}

    bool checkValidString(string s) {
        n = s.length();
        str = s;

        dfs(0);

        return ans;
    }
};