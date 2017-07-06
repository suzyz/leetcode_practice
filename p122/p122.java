public class p122 {
    public static int maxProfit(int[] prices) {
        int n=prices.length;
        if(n<2) return 0;
        int ans=0;

        for(int i=1;i<n;i++)
        {
        	if(prices[i]>prices[i-1])
                ans+=prices[i]-prices[i-1];
        }

        return ans;
    }

    public static void main(String[] args) {
    	int[] p = new int[100000];
        for(int i=0;i<100000;i++) p[i]=100000-i;
    	System.out.println("ans:"+maxProfit(p));
    }
}
