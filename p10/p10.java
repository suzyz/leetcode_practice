import java.util.*;

public class p10 {
    public static boolean isMatch(String s, String p) {
        if(s.length()==0 && p.length()==0) return true;
        if(p.length()==0) return false;

        boolean[][] f = new boolean[s.length()+2][p.length()+2];
        
        f[0][0]=true;
        for(int i=0;i<=s.length();i++)
        {
        	for(int j=1;j<=p.length();j++)
        	{

        		f[i][j]=false;
        		if(i>0 && s.charAt(i-1)==p.charAt(j-1) && f[i-1][j-1]) f[i][j]=true;
        		else
        		if(i>0 && p.charAt(j-1)=='.' && f[i-1][j-1]) f[i][j]=true;
        		else
        		if(p.charAt(j-1)=='*')
        		{
                    if(f[i][j-2]) //0
                    {
                        f[i][j]=true;
                        continue;
                    }
                    
                    if(i>0)
                        if(s.charAt(i-1)==p.charAt(j-2) || p.charAt(j-2)=='.')
                        {
                            f[i][j]|=f[i-1][j];// multiple
                            if(j>1)  f[i][j]|=f[i][j-1]; //1
                        }
        		}
        	}
        }
        return f[s.length()][p.length()];
    }

    public static void main(String[] args)
    {
    	String s = "aab";
    	String p = "a*c*b*";
    	System.out.println(isMatch(s,p));
    }
}
