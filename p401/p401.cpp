class Solution {
public:
	int tot;
	int hour;

	vector<string> ans;

    vector<string> readBinaryWatch(int num) {
        tot = num;

        for (int i = max(0, num-6); i <= min(num, 4); ++i)
        {
        	vector<int> pos1(i+1);
        	dfs1(0, -1, i, pos1);
        }

        return ans;
    }

    void dfs1(int cur, int prePos, int num1, vector<int> &pos1) {
    	if (cur >= num1)
    	{
    		hour = 0;
    		for (int i = 0; i < num1; ++i)
	    		hour += 1<<pos1[i];

	    	if (hour >= 12)
	    		return;

	    	vector<int> pos2(tot-num1+1);
	    	dfs2(0, -1, tot - num1, pos2);

	   		return;
    	}

    	for (int i = prePos+1; i < 4; ++i)
    	{
    		pos1[cur] = i;

    		dfs1(cur+1, i, num1, pos1);
    	}
    }

    void dfs2(int cur, int prePos, int num2, vector<int> &pos2) {
    	if (cur >= num2)
    	{
    		int minute = 0;
    		for (int i = 0; i < num2; ++i)
	    		minute += 1<<pos2[i];

	    	if (minute < 60)
	    		storeAns(minute);

	   		return;
    	}

    	for (int i = prePos+1; i < 6; ++i)
    	{
    		pos2[cur] = i;

    		dfs2(cur+1, i, num2, pos2);
    	}
    }

    void storeAns(int minute) {
    	string s = to_string(hour) + ":"
    	 	+ to_string(minute/10) + to_string(minute%10);

    	ans.push_back(s);
    }
};