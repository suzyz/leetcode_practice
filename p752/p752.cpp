// Simple BFS.
class Solution {
public:
	vector<int> dir;
	unordered_set<string> s, vis;

    int openLock(vector<string>& deadends, string target) {
    	s = unordered_set<string>(deadends.begin(), deadends.end());

    	string start = "0000";

    	if (s.count(start))
    		return -1;

    	if (target == start)
    		return 0;

    	int ans = -1, steps = 0;

    	queue<string> qu;
    	qu.push(start);
    	vis.insert(start);

    	while (!qu.empty() && ans == -1) {
    		++steps;

    		int levelSize = qu.size();

    		while (levelSize && ans == -1) {
    			--levelSize;

				string cur = qu.front();
	    		qu.pop();

	    		for (int i = 0; i < 4; ++i){
	    			string tmp = cur;
	    			if (tmp[i] == '9')
	    				tmp[i] = '0';
	    			else
	    				++tmp[i];

	    			if (tmp == target) {
	    				ans = steps;
	    				break;
	    			}

	    			if (!s.count(tmp) && !vis.count(tmp)) {
	    				qu.push(tmp);
	    				vis.insert(tmp);
	    			}

	    			tmp = cur;
	    			if (tmp[i] == '0')
	    				tmp[i] = '9';
	    			else
	    				--tmp[i];

	    			if (tmp == target) {
	    				ans = steps;
	    				break;
	    			}

	    			if (!s.count(tmp) && !vis.count(tmp)) {
	    				qu.push(tmp);
	    				vis.insert(tmp);
	    			}
	    		}
    		}
    	}

    	return ans;
    }
};