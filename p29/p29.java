import java.util.*;

public class p29{
  public static int divide(int dividend, int divisor) {
    	if(dividend==0) return 0;
    	if(divisor==0) return Integer.MAX_VALUE;

    	long a=dividend,b=divisor;
    	a=Math.abs(a);
    	b=Math.abs(b);
    	if(a<b) return 0;
    	if(a==b)
    	{
    		if((divisor<0 && dividend>0) || (divisor>0 && dividend<0)) return -1;
    		else return 1;
    	}
        
        int i=0;
        long tmp=a;
        while((b<<i)<=a) i++;

        i--;
        long ans=0;
       	while(a>0 && i>=0)
       	{
       		a-=(b<<i);
       		ans+=((long)1<<i);
       		while(i>=0 && (b<<i)>a) i--;
       	}
       	if((divisor<0 && dividend>0) || (divisor>0 && dividend<0))
       		ans=-ans;

       	if(ans>Integer.MAX_VALUE || ans<Integer.MIN_VALUE)
       		return Integer.MAX_VALUE;
       	else
        	return (int)ans;
    }
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	int a=sc.nextInt();
    	int b=sc.nextInt();
    	System.out.println(divide(a,b));
    }
}