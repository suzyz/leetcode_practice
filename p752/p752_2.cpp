// Bidirectional BFS.
class Solution {
public:
	vector<int> dir;
	unordered_set<string> bad, vis1, vis2;

    int openLock(vector<string>& deadends, string target) {
    	bad = unordered_set<string>(deadends.begin(), deadends.end());

    	string start = "0000";

    	if (bad.count(start))
    		return -1;

    	if (target == start)
    		return 0;

    	int steps = 0;

    	deque<string> qu1, qu2;
    	qu1.push_back(start);
    	qu2.push_back(target);
    	vis1.insert(start);
    	vis2.insert(target);

    	while (!qu1.empty()) {
    		++steps;

    		int size = qu1.size();

    		while (size) {
    			--size;

    			string cur = qu1.front();
    			qu1.pop_front();

    			for (int i = 0; i < 4; ++i) {
    				string tmp = cur;
	    			if (tmp[i] == '9')
	    				tmp[i] = '0';
	    			else
	    				++tmp[i];

	    			if (vis2.count(tmp))
	    				return steps;

	    			if (!bad.count(tmp) && !vis1.count(tmp)) {
	    				qu1.push_back(tmp);
	    				vis1.insert(tmp);
	    			}

	    			tmp = cur;
	    			if (tmp[i] == '0')
	    				tmp[i] = '9';
	    			else
	    				--tmp[i];

	    			if (vis2.count(tmp))
	    				return steps;

	    			if (!bad.count(tmp) && !vis1.count(tmp)) {
	    				qu1.push_back(tmp);
	    				vis1.insert(tmp);
	    			}
    			}
    		}

    		if (qu1.size() > qu2.size()) {
    			deque<string> tmp = qu1;
    			qu1 = qu2;
    			qu2 = tmp;

    			unordered_set<string> t = vis1;
    			vis1 = vis2;
    			vis2 = t;
    		}
    	}

    	return -1;
    }
};