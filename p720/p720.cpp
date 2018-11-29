class Solution {
public:
    string longestWord(vector<string>& words) {
        int n = words.size();
        string ans;
        
        if (n == 0)
        	return ans;

        sort(words.begin(),words.end());

        unordered_set<string> dict;

        for (int i = 0; i < n; ++i) {
        	int len = words[i].length();
        	if (len == 1 || dict.count(words[i].substr(0, len-1))) {
        		if (len > ans.length()) 
        			ans = words[i];

        		dict.insert(words[i]);
        	}
        }

        return ans;
    }
};