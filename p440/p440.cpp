class Solution {
public:
    int findKthNumber(int n, int k) {
        vector<int> digits;
        int tmp = n;
        while (tmp) {
            digits.insert(digits.begin(), tmp%10);
            tmp /= 10;
        }
        
        int len = digits.size(), cur = 0;
        vector<int> res;
        for (int i = 0; i < len; ++i) {
            int st = 0;
            if (i == 0)
                st = 1;
            
            res.push_back(0);
            
            int sum = 0, pre = 0;
            for (int j = st; j <= 9; ++j) {
                res[i] = j;
                pre = sum;
                int count = beginWith(res, digits, 10*cur + j, n);
                sum += count;
                
                // printf("i:%d j:%d count:%d sum:%d 10*cur+j:%d\n", i, j, count,sum,10*cur+j);
                
                if (sum >= k) {
                    cur = 10 * cur + j;
                    k -= pre + 1;
                    break;
                }
            }
            
            if (k == 0)
                break;
        }
        
        int ans = 0;
        for (int i = 0; i < res.size(); ++i)
            ans = 10*ans + res[i];
        return ans;
    }
    
    int beginWith(vector<int>& st, vector<int>& digits, int cur, int n) {
        
        int sum = 1, w = 10, len = digits.size();
        if (st.size() == len)
            return 1;
        
        for (int i = st.size()+1; i < len; ++i) {
            sum += w; 
            w *= 10;
        }
        
        bool smaller = false, larger = false;
        for (int i = 0; i < st.size(); ++i)
            if (st[i] < digits[i]) {
                smaller = true;
                break;
            } else if (st[i] > digits[i]) {
                larger = true;
                break;
            }
        
        if (smaller)
            sum += w;
        else if (!larger){
            for (int i = st.size(); i < len; ++i)
                cur *= 10;
            
            sum += n-cur+1;
        }
        
        return sum;
    }
};