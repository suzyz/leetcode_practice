class Solution {
public:

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        stack<int> st;

        int preTime = 0;
        for (int i = 0; i < logs.size(); ++i) {
        	int pos = logs[i].find(':');
        	int id = atoi(logs[i].substr(0, pos).c_str());

            pos = logs[i].find(':', pos+1);
            int curTime = atoi(logs[i].substr(pos+1).c_str());

            if (!st.empty())
                res[st.top()] += curTime - preTime;

            preTime = curTime;
            if (logs[i][pos-1] == 't')
                st.push(id);
            else {
                ++res[st.top()];
                st.pop();

                ++preTime;
            }
        }

        return res;
    }
};