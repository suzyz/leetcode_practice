import java.util.*;

public class p372 {
	//1
	public static int powMod(int a,int b) /*  (a^b)%1337.  0<=b<=10 */
	{
		if(a>1337) a%=1337;
		int res=1;
		for(int i=0;i<b;i++)
			res=res*a%1337;

		return res;
	}
	public static int superPow0(int a, List<Integer> b) {
		if(b.size()==0) return 1;
		int k = b.get(b.size()-1);
		b.remove(b.size()-1);
		
		return powMod(superPow0(a,b),10)*powMod(a,k)%1337;
	}

	public static int superPow(int a, int[] b) {
		if(a==0) return 0;
		if(a>1337) return superPow(a%1337,b);
		if(b.length==0) return 1;

		int k = b[b.length-1];

		List<Integer> b1 = new ArrayList<Integer>();
		for(int i=0;i<b.length-1;i++)
			b1.add(b[i]);
		
		return powMod(superPow0(a,b1),10)*powMod(a,k)%1337;
	}
	//2
    public static int superPow1(int a, int[] b) {
        //convert b from decimal to binary. TLE
        int n = b.length;
        int[] c = new int[11*n/3];

        double now=0;
        for(int i=0;i<n;i++)
        	now=10*now+b[i];

        a%=1337;
        double tmp,ans=1;
        while(now>1-1e-10)
        {
        	tmp=now/2;
        	if(Math.abs(tmp-Math.floor(tmp))>1e-10)
        		ans=a*ans%1337;
        	
        	a=a*a%1337;
        	now=Math.floor(tmp+1e-10);
        }
        return (int)Math.round(ans);
    }

    public static void main(String[] args)
    {
    	int [] b = {2,0,0};
    	System.out.println(superPow(2147483647,b));
    }
}