public class p121 {
    public int maxProfit(int[] prices) {
        int n=prices.length;
        if(n<2) return 0;
        int ans=0,minp=prices[0];
        for(int i=1;i<n;i++)
        {
            ans=prices[i]-minp>ans ? prices[i]-minp:ans;
            minp=prices[i]<minp ? prices[i]:minp;
        }
        return ans;
    }
}
