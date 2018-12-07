class Solution {
public:
	const char mutations[4] = {'A','C','G','T'};

    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(),bank.end());

        if (!dict.count(end))
        	return -1;

        queue<string> qu;
        qu.push(start);

        dict.erase(start);

        int steps = 0;
        while (!qu.empty()) {
        	++steps;
        	
        	int levelSize = qu.size();
        	while (levelSize) {
        		--levelSize;

        		string cur = qu.front();
        		qu.pop();

        		for (int i = 0; i < cur.length(); ++i)
        			for (int j = 0; j < 4; ++j)
        				if (mutations[j] != cur[i]) {
        					string tmp = cur;
        					tmp[i] = mutations[j];

        					if (tmp == end)
        						return steps;

        					if (dict.count(tmp)) {
        						qu.push(tmp);
        						dict.erase(tmp);
        					}
        				}
        	}
        }

        return -1;
    }
};