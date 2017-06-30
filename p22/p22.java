import java.util.*;

public class p22 {
	public static void mygenerate(int m,int n,String now,List<String> ans)
	{
		if(m==0 && n==0)
		{
			ans.add(now);
			return;
		}
		if(m>0) mygenerate(m-1,n,now+"(",ans);
		if(n>m) mygenerate(m,n-1,now+")",ans);
	}

	public static List<String> generateParenthesis(int n)
	{
		List<String> ans = new ArrayList<String>();

		mygenerate(n,n,"",ans);

		return ans;
	}

	public static void mygenerate1(int cur,int n,int st,String now,List<String> ans)
	{
		if(cur>n)
		{
			if(st>0)
			{
				for(int i=0;i<st;i++)
					now = now+")";
			}
			ans.add(now);
			return;
		}

		if(st>0)
		{
			for(int i=1;i<=st;i++)
			{
				String tmp = new String(now);
				for(int j=0;j<i;j++)
					tmp = tmp+")";

				tmp = tmp+"(";
				mygenerate1(cur+1,n,st-i+1,tmp,ans);
			}
		}

		String tmp = new String(now);
		tmp = tmp + "(";
		mygenerate1(cur+1,n,st+1,tmp,ans);
	}

    public static List<String> generateParenthesis1(int n) {
        List<String> ans = new ArrayList<String>();

        if(n==0)
        	return ans;

        String s = new String();
        mygenerate1(1,n,0,s,ans);

        return ans;
    }

    public static void main(String[] args) {
    	List<String> ans = generateParenthesis(3);
    	for(int i=0;i<ans.size();i++)
    		System.out.println(ans.get(i));
    }
}