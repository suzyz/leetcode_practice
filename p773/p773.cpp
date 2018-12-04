class Solution {
public:
	const string target = "123450";
	const int dir[4][2] = {{0,1}, {0,-1}, {1,0},{-1,0}};

	deque<string> qu1, qu2;
	unordered_set<string> vis1, vis2;

    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for (int i = 0; i < 2; ++i)
        	for (int j = 0; j < 3; ++j)
        		start += (char)(board[i][j] + '0');

        if (start == target)
        	return 0;

        qu1.push_back(start);
        vis1.insert(start);

        qu2.push_back(target);
        vis2.insert(target);

        int steps = 0;
        while (!qu1.empty()) {
        	++steps;

        	int size = qu1.size();
        	while (size) {
        		--size;

        		string cur = qu1.front();
        		qu1.pop_front();

        		int pos = 0;
        		while (pos < 6 && cur[pos] != '0')
        			++pos;

        		int x = pos/3, y = pos%3;
        		for (int i = 0; i < 4; ++i) {
        			int tx = x + dir[i][0];
        			if (tx < 0 || tx > 1)
        				continue;
        			int ty = y + dir[i][1];
        			if (ty < 0 || ty > 2)
        				continue;

        			string tmp = cur;
        			tmp[pos] = tmp[tx*3 + ty];
        			tmp[tx*3 + ty] = '0';

        			if (vis2.count(tmp))
        				return steps;

        			if (!vis1.count(tmp)) {
        				qu1.push_back(tmp);
        				vis1.insert(tmp);
        			}
        		}
        	}

        	if (qu1.size() > qu2.size()) {
        		deque<string> tmp = qu1;
        		qu1 = qu2;
        		qu2 = tmp;

        		unordered_set<string> ts = vis1;
        		vis1 = vis2;
        		vis2 = ts;
        	}
        }

        return -1;
    }
};