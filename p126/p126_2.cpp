// Two-end BFS.

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.count(endWord) == 0)
        	return res;

        int n = beginWord.length(), head = 0;
        vector<pair<string,int>> qu;
        qu.push_back(make_pair(beginWord,-1));
        
        unordered_set<string> vis;

        while (head < qu.size())
        {
        	int cur_len_tail = qu.size();

        	while (head < cur_len_tail)
        	{
				string cur = qu[head].first;
	        	++head;

	        	string tmp = cur;
	        	for (int i = 0; i < n; ++i)
	        	{
	        		tmp = cur;
	        		for (int j = 'a'; j <= 'z'; ++j)
	        			if (j != cur[i])
	        			{
	        				tmp[i] = j;
	        				if (tmp == endWord)
	        				{
	        					vector<string> transformation(1,endWord);
	        					int pre = head-1;
	        					while (pre >= 0)
	        					{
	        						transformation.insert(transformation.begin(),qu[pre].first);
	        						pre = qu[pre].second;
	        					}
	        					
	        					res.push_back(transformation);

	        					continue;
	        				}

	        				if (vis.count(tmp) == 1 || dict.count(tmp) == 0)
	        					continue;

	        				qu.push_back(make_pair(tmp,head-1));
	        			}
	        	}
        	}

        	if (res.size() > 0)
        		break;

        	for (int i = cur_len_tail; i < qu.size(); ++i)
        		vis.insert(qu[i].first);
        }

        return res;
    }
};
