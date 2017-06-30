import java.util.*;
public class p69 {
	public static int mySqrt3(int x) { /* Newton */
    	long ans=x;
		while(ans*ans>x)
		{
			ans=(ans+x/ans)>>1;
		}
		return (int)ans;
	}
	public static int mySqrt2(int x) { /* plain binary search without using double */
    	if(x==0) return 0;
		if(x==1) return 1;
    	int l=1,r=x>>1;
		while(l<r)
		{
			if(l+1==r)
			{
				if(r>x/r) return l;
				else return r;
			}
			int mid = l+((r-l)>>1);
			if(mid>x/mid) r=mid-1;
			else
			if(mid==x/mid) l=r=mid;
			else
				l=mid;
		}
		return l;
	}
    public static int mySqrt1(int x) { /* plain binary search using double */
    	if(x==0) return 0;
		if(x==1) return 1;
    	int l=1,r=x>>1;
		while(l<r)
		{
			System.out.println("l:"+l+" r:"+r);
			if(l+1==r)
			{
				System.out.println(l*l+" "+(double)r*r);
				if((double)r*r>x+1e-10) return l;
				else return r;
			}
			double mid=(l+r)>>1;
			if(Math.abs(mid*mid-x)<1e-10)
			{
				l=(int)mid;
				r=l+1;
				if((double)r*r<=x) return r;
				if((double)l*l<=x) return l;
				return l-1;
			}
			else
			if(mid*mid<x) l=(int)mid;
			else r=(int)mid;
		}
		return l; 
    }
    public static void main(String[] args)
    {
		int x=2147483647;
		System.out.println(mySqrt3(x));
    }
}
