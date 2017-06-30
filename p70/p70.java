public class p70 {
    public int climbStairs(int n) {
        if(n<2) return 1;
        int a=1,b=1,c=2;
        n--;
        while(n>0)
        {
            c=a+b;
            a=b;
            b=c;
            n--;
        }
        return c;
    }
}
