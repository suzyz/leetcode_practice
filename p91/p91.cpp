class Solution {
public:
    int numDecodings(string s) {     
        int n=s.length();
        if(n==0) return 0;

        int f[n+1];
        memset(f,0,sizeof(f));
        
        f[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]>='1' && s[i]<='9') f[i]+=f[i+1];
            if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))) f[i]+=f[i+2];
        }
        return f[0];
    }
};