class Solution {
public:
    int calculate(string s) {
        int pred[260];
        pred['+'] = pred['-'] = 0;
        pred['*'] = pred['/'] = 1;
        pred['#'] = -1;
        s += '#';

        for (string::iterator it = s.begin(); it != s.end();)
            if (*it == ' ')
                it = s.erase(it);
            else
                ++it;

        stack<int> st_number;
        stack<char> st_operator;
        int n = s.length();
        for (int i = 0; i < n;)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int d = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9')
                {
                    d = 10*d + s[i]-'0';
                    ++i;
                }
                st_number.push(d);
            }
            else
            {
                while (st_operator.size() > 0 && pred[st_operator.top()] >= pred[s[i]])
                {
                    if (st_number.size() < 2)
                        return 0;
                    
                    int y = st_number.top(); st_number.pop();
                    int x = st_number.top(); st_number.pop();
                    char op = st_operator.top(); st_operator.pop();
                    switch (op)
                    {
                        case '+':
                            st_number.push(x+y);
                            break;
                        case '-':
                            st_number.push(x-y);
                            break;
                        case '*':
                            st_number.push(x*y);
                            break;
                        case '/':
                            if (y == 0)
                                return 0;
                            st_number.push(x/y);
                    }
                }
                st_operator.push(s[i]);

                ++i;
            }
        }

        return st_number.top();
    }
};
