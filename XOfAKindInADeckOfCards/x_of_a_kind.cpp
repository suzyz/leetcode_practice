class Solution {
public:
	int gcd(int a, int b) {
		if (a%b == 0)
			return b;
		return gcd(b, a%b);
	}
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size();
        unordered_map<int, int> count;

        for (int i = 0; i < n; ++i)
        	++count[deck[i]];

        int k = -1;

        for (unordered_map<int, int>::iterator it = count.begin();
        	it != count.end(); ++it) {
        	if (k == -1) {
        		k = it->second;
        	} else {
        		k = gcd(k, it->second);
        		if (k < 2)
        			return false;
        	}
        }

        return k >= 2;
    }
};