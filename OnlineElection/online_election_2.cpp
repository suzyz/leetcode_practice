// binary search.
class TopVotedCandidate {
public:

	int n;
	vector<int> res, ts;
	unordered_map<int,int> votes;


    TopVotedCandidate(vector<int> persons, vector<int> times) {
        n = times.size();

        ts = times;
        res = vector<int>(n);

        int lead = persons[0];
        res[0] = lead;
        votes[lead] = 1;
        for (int i = 1; i < n; ++i) {
        	int cur = persons[i];
        	++votes[cur];
        	if (votes[cur] >= votes[lead]) {
        		lead = cur;
        	}
        	res[i] = lead;
        }
    }
    
    int q(int t) {
        if (t >= ts[n-1])
        	return res[n-1];
        if (t <= ts[0])
        	return res[0];

        int l = 0, r = n-1;
        while (l < r) {
        	int mid = l + ((r-l)>>1) + 1;
        	if (ts[mid] == t) {
        		l = r = mid;
        		break;
        	} else if (ts[mid] > t) {
        		r = mid-1;
        	} else {
        		l = mid;
        	}
        }

        return res[l];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */