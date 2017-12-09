// Brutal.
class Solution {
public:
    int goal, n;
    string s,t;

    vector<int> status;
    vector<string> res;
    stack<long long> st_number;
    stack<char> st_operator;

    int pred[260];    

    vector<string> addOperators(string num, int target) {
        if (num.length() == 0)
            return res;

        goal = target;
        s = num;
        n = num.length();
        s += '#';
        status = vector<int>(n,0);

        pred['+'] = pred['-'] = 0;
        pred['*'] = pred['/'] = 1;
        pred['#'] = -1;

        dfs(0);

        return res;
    }

    void dfs(int cur)
    {
        if (cur == n-1)
        {
            convert();
            if (check())
            {
                t.erase(t.end()-1);
                res.push_back(t);
            }
            return;
        }

        int start = 0;
        if (s[cur] == '0' && (cur == 0 || (cur>0 && status[cur-1] != 0)))
            start = 1;

        for (int i = 3; i >= start; --i)
        {
            status[cur] = i;
            dfs(cur+1);
        }
    }

    bool check()
    {
        if (!st_number.empty())
            st_number.pop();
        if (!st_operator.empty())
            st_operator.pop();

        for (int i = 0; i < t.length(); )
        {
            if (t[i] >= '0' && t[i] <= '9')
            {
                long long d = 0;
                while (i < t.length() && t[i] >= '0' && t[i] <= '9')
                {
                    d = 10*d + t[i]-'0';
                    ++i;
                }
                st_number.push(d);
            }
            else
            {
                while (st_operator.size() > 0 && pred[st_operator.top()] >= pred[t[i]])
                {
                    if (st_number.size() < 2)
                        return 0;
                    
                    long long y = st_number.top(); st_number.pop();
                    long long x = st_number.top(); st_number.pop();
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
                st_operator.push(t[i]);

                ++i;
            }
        }

        return (st_number.top() == goal);
    }

    void convert()
    {
        int sum = 1;
        t = s;
        for (int i = 0; i < n; ++i)
        {
            if (status[i] == 0)
                continue;

            if (status[i] == 1)
                t.insert(i+sum,1,'+');
            else
            if (status[i] == 2)
                t.insert(i+sum,1,'-');
            else
                t.insert(i+sum,1,'*');
            ++sum;
        }
    }
};
