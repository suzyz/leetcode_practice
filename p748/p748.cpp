class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string res;
        bool found = false;
        
        vector<int> count1(26);
        for (int i = 0; i < licensePlate.length(); ++i) {
            char c = tolower(licensePlate[i]);
            if (islower(c))
                ++count1[c-'a'];
        }
        
        for (int i = 0; i < words.size(); ++i) {
            
            if (found && words[i].length() >= res.length())
                continue;
            
            vector<int> count2(26);
            for (int j = 0; j < words[i].length(); ++j)
                ++count2[words[i][j]-'a'];
            
            bool ok = true;
            for (int j = 0; j < 26; ++j)
                if (count1[j] > count2[j]) {
                    ok = false;
                    break;
                }
            
            if (ok) {
                found = true;
                res = words[i];
            }
        }
        
        return res;
    }
};