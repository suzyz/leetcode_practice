// in place
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int i = 0;
        for (int j = 0; j < n; ++j)
            if (A[j]%2 == 0) {
                int tmp = A[j];
                A[j] = A[i];
                A[i] = tmp;

                i++;
            }
        
        return A;
    }
};