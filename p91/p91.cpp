class Solution {
public:
    int numDecodings(string s) {     
        int n=s.length();
        if(n==0) return 0;

        int f[n];
        memset(f,0,sizeof(f));
        int i=0;

        while(i<n && s[i]=='0') i++;

        if(i==n) return 0;

        f[i]=1;
        while(i<n-1)
        {
            i++;
            if(s[i]=='0') continue;

            f[i]=f[i-1];
            if(s[i-1]!='0' && (s[i-1]-'0')*10+s[i]-'0'<=26)
            {
                if(i>1)
                    f[i]+=f[i-2];
                else
                    f[i]++;
            }
        }

        return f[n-1];
    }
};