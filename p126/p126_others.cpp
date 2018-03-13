
bool findLaddersHelper(unordered_set<string> &words1, unordered_set<string> &words2, unordered_set<string> &dict, unordered_map<string, vector<string> > &nexts, bool &words1IsBegin) {
	
	words1IsBegin = !words1IsBegin;
	if (words1.empty())
        return false;
	if (words1.size() > words2.size())
		return findLaddersHelper(words2, words1, dict, nexts, words1IsBegin);
		
	for (auto it = words1.begin(); it != words1.end(); ++it)
		dict.erase(*it);
	for (auto it = words2.begin(); it != words2.end(); ++it)
		dict.erase(*it);
		
    unordered_set<string> words3;
	bool reach = false;
    for (auto it = words1.begin(); it != words1.end(); ++it) {
		string word = *it;
		for (auto ch = word.begin(); ch != word.end(); ++ch) {
			char tmp = *ch;
            for (*ch = 'a'; *ch <= 'z'; ++(*ch))
				if (*ch != tmp)
					if (words2.find(word) != words2.end()) {
						reach = true;
						words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
					}
					else if (!reach && dict.find(word) != dict.end()) {
						words3.insert(word);
						words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                    }
			*ch = tmp;
        }
    }
    return reach || findLaddersHelper(words2, words3, dict, nexts, words1IsBegin);
}


void getPath(string beginWord,string &endWord,unordered_map<string, vector<string> > &nexts,vector<string> &path,vector<vector<string> > &paths) {
    
	if (beginWord == endWord){
		paths.push_back(path);
        return;
    }
	
		for (auto it = nexts[beginWord].begin(); it != nexts[beginWord].end(); ++it) {
			path.push_back(*it);
			getPath(*it, endWord, nexts, path, paths);
			path.pop_back();
		}
}
