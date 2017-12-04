// Hash.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       	vector<vector<string>> res;
        unordered_map<long long,int> pos;
       	const char primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};

       	for (int i = 0; i < strs.size(); ++i)
       	{
       		long long hash_value = 1;
            for (int j = 0; j < strs[i].size(); ++j)
                hash_value *= primes[strs[i][j]-'a'];

            if (pos.count(hash_value) == 0)
            {
                pos[hash_value] = res.size();
                res.push_back(vector<string>());
            }

            res[pos[hash_value]].push_back(strs[i]);
       	}

       	return res;
    }
};
