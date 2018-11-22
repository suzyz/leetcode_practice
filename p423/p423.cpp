class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(128), res(10);

        for (int i = 0; i < s.length(); ++i)
        	++count[s[i]];

        int tmp;
        if (count['z']) {
        	res[0] = tmp = count['z'];

        	count['e'] -= tmp;
        	count['r'] -= tmp;
        	count['o'] -= tmp;
        }

        if (count['w']) {
        	res[2] = tmp = count['w'];

        	count['t'] -= tmp;
        	count['o'] -= tmp;
        }

        if (count['u']) {
        	res[4] = tmp = count['u'];

        	count['f'] -= tmp;
        	count['o'] -= tmp;
        	count['r'] -= tmp;
        }

        if (count['f']) {
        	res[5] = tmp = count['f'];

        	count['i'] -= tmp;
        	count['v'] -= tmp;
        	count['e'] -= tmp;
        }

        if (count['x']) {
        	res[6] = tmp = count['x'];

        	count['s'] -= tmp;
        	count['i'] -= tmp;
        }

        if (count['v']) {
        	res[7] = tmp = count['v'];

        	count['s'] -= tmp;
        	count['e'] -= 2*tmp;
        	count['n'] -= tmp;
        }

        if (count['g']) {
        	res[8] = tmp = count['g'];

        	count['e'] -= tmp;
        	count['i'] -= tmp;
        	count['h'] -= tmp;
        	count['t'] -= tmp;
        }

        if (count['o']) {
        	res[1] = tmp = count['o'];

        	count['n'] -= tmp;
        	count['e'] -= tmp;
        }

        res[3] = count['t'];
        res[9] = count['i'];

        string ans;
        for (int i = 0; i < 10; ++i)
        	if (res[i] > 0)
        		ans += string(res[i], '0'+i);

        return ans;
    }
};