class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size(), total, ans = 0;
        total = n*n;
        int ab[total+1] = {0}, cd[total+1] = {0};

        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ab[k] = A[i] + B[j];
                cd[k] = 0 - C[i] - D[j];
                k++;
            }
        }

        sort(ab,ab + total);
        sort(cd,cd + total);

        int i = 0, j = 0;
        while (i < total && j <total)
        {
            if (ab[i] == cd[j])
            {
                int p = i, q = j, count1 = 0, count2 = 0;

                while (p<total && ab[p] == ab[i])
                {
                    ++p;
                    ++count1;
                }
                while (q<total && cd[q] == cd[j])
                {
                    ++q;
                    ++count2;
                }
                ans += count1*count2;
                i = p;
                j = q;
            }
            else
            if (ab[i] > cd[j])
                ++j;
            else
                ++i;
        }
        return ans;
    }
};
