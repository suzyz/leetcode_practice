public class p123_2 {
    public static int maxProfit(int[] prices) {
        int n=prices.length;
        if(n<2) return 0;
        int release1=0,release2=0,hold1=Integer.MIN_VALUE,hold2=Integer.MIN_VALUE;
        for(int i=0;i<n;i++)
        {
            release2=Math.max(release2,hold2+prices[i]);
            hold2=Math.max(hold2,release1-prices[i]);
            release1=Math.max(release1,hold1+prices[i]);
            hold1=Math.max(hold1,-prices[i]);
        }
        return release2;
    }

    public static void main(String[] args) {
        int[] p ={1,2,1,1,3};
        System.out.println("ans:"+maxProfit(p));
    }
}
