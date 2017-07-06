public class p123 {
    public int maxProfit(int[] prices) {
        int n=prices.length;
        if(n<2) return 0;
        int ans=0,tmp,minCur,maxCur;
        int[] f = new int[n+2];

        tmp=0;
        maxCur=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
        	f[i]=maxCur-prices[i]>f[i+1] ? maxCur-prices[i]:f[i+1];
        	maxCur=prices[i]>maxCur ? prices[i]:maxCur;
        }

        ans=f[0]>0 ? f[0]:0;

        tmp=0;
        minCur=prices[0];
        for(int i=1;i<n;i++)
        {
        	tmp=prices[i]-minCur>tmp ? prices[i]-minCur:tmp;
        	minCur=prices[i]<minCur ? prices[i]:minCur;

        	ans=tmp+f[i+1]>ans ? tmp+f[i+1]:ans;
        }
        return ans;
    }
}
