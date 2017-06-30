import java.util.*;

public class p50 {
    public static double myPow(double x, int n) {
        if(n==0) return 1;
        long m=n;
        if(n<0) m=-m;
        
        double ans=1;
        while(m>0)
        {
            if((m&1)>0) ans*=x;
            x=x*x;
            m>>=1;
        }
        if(n<0) return 1/ans;
        else
            return ans;
    }

    public static void main(String[] args)
    {
    	//System.out.println(myPow(0.00001,2147483647));
    	System.out.println(myPow(8.88023,3));
    	//System.out.println(myPow(2.00000,-2147483648));
    }
}