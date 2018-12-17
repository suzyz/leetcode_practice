class Solution {
public:
	struct Node
	{
		int id, start, subLength;

		Node(int i, int s, int l) { id = i; start = s; subLength = l; }
	};

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        vector<Node> st;

        for (int i = 0; i < logs.size(); ++i) {
        	int pos = logs[i].find(':');
        	int id = atoi(logs[i].substr(0, pos).c_str());

        	if (logs[i][pos+1] == 's') {
        		pos += 7;

        		int start = atoi(logs[i].substr(pos).c_str());
        		st.push_back(Node(id, start, 0));
        	} else {
        		pos += 5;

        		int end = atoi(logs[i].substr(pos).c_str());
                
        		Node cur = st.back();
        		st.pop_back();
        
        		int curLen = end - cur.start + 1 - cur.subLength;
        		res[id] += curLen;

        		for (int j = 0; j < st.size(); ++j)
        			st[j].subLength += curLen;
        	}
        }

        return res;
    }
};