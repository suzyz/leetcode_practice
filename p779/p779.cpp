class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1)
        	return 0;

        int pre = kthGrammar(N-1, (K+1)/2);
        if (((K&1) && pre == 0) || ((K&1) == 0 && pre == 1))
        	return 0;
        else
        	return 1;
    }
};