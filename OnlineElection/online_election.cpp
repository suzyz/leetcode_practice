// Heap, binary search.
class TopVotedCandidate {
public:

	int n;
	vector<int> res, ts, d;
	unordered_map<int,int> votes, lastTime, pos;


		void up(int j) {
			int i = j/2;
				while (i >= 1) {
					if (votes[d[i]] < votes[d[j]] 
					|| (votes[d[i]] == votes[d[j]] && lastTime[d[i]] < lastTime[d[j]])) {
						
						pos[d[j]] = i;
						pos[d[i]] = j;

						int tmp = d[i];
						d[i] = d[j];
						d[j] = tmp;

						j = i;
						i = j/2;
					} else
						break;
				}
		}

		void down(int i) {
			int j = 2*i;
			while (j < d.size()) {
				int k = i;
				if (votes[d[j]] > votes[d[k]]
				|| (votes[d[j]] == votes[d[k]] && lastTime[d[j]] > lastTime[d[k]]))
					k = j;

				if (j+1 < d.size())
					if (votes[d[j+1]] > votes[d[k]]
					|| (votes[d[j+1]] == votes[d[k]] && lastTime[d[j+1]] > lastTime[d[k]]))
						k = j+1;

				if (k == i)
					break;

				pos[d[k]] = i;
				pos[d[i]] = k;

				int tmp = d[k];
				d[k] = d[i];
				d[i] = tmp;

				i = k;
				j = 2*i;
			}
		}

		void inc(int cur, int t) {
			if (votes[cur] == 0) {
				d.push_back(cur);
				pos[cur] = d.size()-1;
				votes[cur]++;
				lastTime[cur] = t;

				up(pos[cur]);

			} else {
				votes[cur]++;
				lastTime[cur] = t;

				int i = pos[cur]/2, j = pos[cur];
				if (i >= 1 && (votes[d[i]] < votes[d[j]]
					|| votes[d[i]] == votes[d[j]] && lastTime[d[i]] < lastTime[d[j]])) {
                    // printf("cur:%d\n",cur);
					up(pos[cur]);

				} else {
					i = pos[cur];
					j = 2*i;
					if (j < d.size() && (votes[i] < votes[j] 
						|| (votes[d[i]] == votes[d[j]] && lastTime[d[i]] < lastTime[d[j]]))) {

						down(pos[cur]);
					}
				}
			}
		}


    TopVotedCandidate(vector<int> persons, vector<int> times) {
        n = times.size();

        ts = times;
        d = vector<int>(1);
        res = vector<int>(n);

        res[0] = persons[0];
        inc(persons[0], times[0]);
        for (int i = 1; i < n; ++i){
        	int cur = persons[i];
        	inc(cur, times[i]);
        	res[i] = d[1];
            // printf("i %d: res[i] %d pos[cur]:%d\n", i, res[i],pos[cur]);
            
//             for (int j = 1; j < d.size(); j++)
//                 printf("%d:%d\n", j, d[j]);
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