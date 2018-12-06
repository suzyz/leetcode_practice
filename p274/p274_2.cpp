class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0)
            return 0;
        
        vector<int> count(n+1);
        for (int i = 0; i < n; ++i)
            ++count[min(n, citations[i])];

        int sum = 0;
        for (int i = n; i > 0; --i) {
            sum += count[i];
            if (sum >= i)
                return i;
        }

        return 0;
    }
};