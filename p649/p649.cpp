class Solution {
public:
    string predictPartyVictory(string s) {
        while (s.length() > 0) {
        	int n = s.size();
        	queue<int> pos1, pos2;

        	for (int i = 0; i < n; ++i)
        		if (s[i] == 'R')
        			pos1.push(i);
        		else
        			pos2.push(i);

        	if (pos1.empty())
        		return "Dire";
        	if (pos2.empty())
        		return "Radiant";

        	vector<bool> ban(n);

        	for (int i = 0; i < n; ++i)
        		if (!ban[i]) {
        			if (s[i] == 'R' && !pos2.empty()) {
        				while (!pos2.empty() && pos2.front() < i) {
        					int tmp = pos2.front();
        					pos2.pop();

        					pos2.push(tmp+n);
        				}

        				int tmp = pos2.front()%n;
        				pos2.pop();
        				ban[tmp] = true;

	        		} else if (!pos1.empty()) {
	        			while (!pos1.empty() && pos1.front() < i) {
        					int tmp = pos1.front();
        					pos1.pop();

        					pos1.push(tmp+n);
        				}

        				int tmp = pos1.front()%n;
        				pos1.pop();
        				ban[tmp] = true;
	        		}
        		}

        	string t;
        	for (int i = 0; i < n; ++i)
        		if (!ban[i])
        			t += s[i];
	        
	        s = t;
        }

        return "";
    }
};