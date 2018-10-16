// f[i] = f[i-1] + f[i-2] + 2*(f[i-3]+f[i-4]+...+f[0])
// So, f[i-1] = f[i-2] + f[i-3] + 2*(f[i-4]+f[i-5]+...+f[0])
// Now we can see f[i] = 2*f[i-1] + f[i-3].

class Solution {
public:
	long long f[1002];
	const int mo = 1e9 + 7;
    int numTilings(int N) {
        if (N == 0)
            return 0;

        f[0] = f[1] = 1;
        f[2] = 2;

        for (int i = 3; i <= N; ++i)
        	f[i] = (f[i-1]*2 + f[i-3])%mo;
        
        return f[N];
    }
};