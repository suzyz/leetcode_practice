// O(N*logN).
class Solution {
public:
	struct mycmp
	{
		bool operator() (pair<int, string>& a, pair<int, string>& b) {
			if (a.first == b.first)
				return a.second > b.second;
			return a.first < b.first;
		}
	};
	
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (int i = 0; i < words.size(); ++i)
        	++freq[words[i]];

        priority_queue<pair<int, string>, vector<pair<int, string>>, mycmp> pq;
        for (unordered_map<string, int>::iterator it = freq.begin();
        	it != freq.end(); ++it)
        	pq.push(make_pair(it->second, it->first));

        vector<string> ans;
        for (int i = 0; i < k; ++i) {
        	ans.push_back(pq.top().second);
        	pq.pop();
    	}

    	return ans;
    }
};