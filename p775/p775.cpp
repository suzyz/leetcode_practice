class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size(), i = 0;
        while (i < n) {
            if (A[i] != i) {
                if (A[i] != i+1 || i == n-1 || A[i+1] != i)
                    return false;
                
                i += 2;
            } else
                ++i;
        }
        
        return true;
    }
};