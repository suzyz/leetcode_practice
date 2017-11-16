class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>> q;

       	for (int i = 0; i < n; ++i)
            ++freq[nums[i]];
       	
       	k = freq.size() < k ? freq.size():k;

        for (unordered_map<int,int>::iterator i = freq.begin(); i != freq.end(); ++i)
        {
            q.push(make_pair(i->second,i->first));
        }

       	vector<int> res;
       	for (int i = 0; i < k; ++i)
        {
            pair<int,int> tmp = q.top();
            q.pop();
       		res.push_back(tmp.second);
        }
       	
       	return res;
    }
};
