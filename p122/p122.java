public class p122 {
    public static int maxProfit(int[] prices) {
        int n=prices.length;
        if(n<2) return 0;
        int[] f = new int[n+1];

        for(int i=2;i<=n;i++)
        {
        	f[i]=f[i-1];
        	int minCur=prices[i-2];
        	for(int j=i-2;j>=0;j--)
        	{
        		f[i]=f[j]>f[i] ? f[j]:f[i];
        		f[i]=f[j]+prices[i-1]-minCur>f[i] ? f[j]+prices[i-1]-minCur:f[i];
				System.out.println("j:"+j+" minCur:"+minCur+" f[i]:"+f[i]);
				if(j==0 || f[j]==0) break;
        		minCur=prices[j-1]<minCur ? prices[j-1]:minCur;
        	}
        	System.out.println(f[i]);
        }

        return f[n];
    }

    public static void main(String[] args) {
    	int[] p={1,4,2};
    	System.out.println("ans:"+maxProfit(p));
    }
}
