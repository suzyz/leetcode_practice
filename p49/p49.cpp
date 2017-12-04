// Brutal force. O(N^2) (N is strs.size() and suppose the length of every word is smaller than N).

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       	vector<vector<string>> res;
       	vector<vector<int>> count;

       	for (int i = 0; i < strs.size(); ++i)
       	{
       		vector<int> cur(26,0);
       		for (int j = 0; j < strs[i].size(); ++j)
       			++cur[strs[i][j]-'a'];
       		
       		bool is_new = true;
       		for (int k = 0; k < res.size(); ++k)
       		{
       			bool is_same = true;
       			for (int j = 0; j < 26; ++j)
       				if (count[k][j] != cur[j])
       				{
       					is_same = false;
       					break;
       				}

       			if (is_same)
       			{
       				is_new = false;
       				res[k].push_back(strs[i]);
       				break;
       			}
       		}

       		if (is_new)
       		{
       			res.push_back(vector<string>(1,strs[i]));
       			count.push_back(cur);
       		}
       	}

       	return res;
    }
};
