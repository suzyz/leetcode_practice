class Solution {
public:
    int helper(string &s) {
        int res = atoi(s.substr(0,2).c_str()) * 60 + atoi(s.substr(3).c_str());
        // cout << res << ":" << s.substr(0,2).c_str() << " " << s.substr(3).c_str() <<endl;
        return res;
    }
    
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        if (n > 24*60)
            return 0;
        
        set<int> s;
        for (int i = 0; i < n; ++i) {
            int cur = helper(timePoints[i]);
            if (s.count(cur))
                return 0;
            s.insert(cur);   
        }
        
        int ans = *s.begin() + 24*60 - *s.rbegin();
        set<int>::iterator it = s.begin();
        int last = *it;
        ++it;
        
        while (it != s.end()) {
            ans = min(*it - last, ans);
            last = *it;
            ++it;
        }
        
        return ans;
    }
};