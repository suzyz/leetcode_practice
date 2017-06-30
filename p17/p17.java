import java.util.*;

public class p17 {
	
    static String[] dict = new String[]{" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    public static List<String> letterCombinations(String digits) { /* FIFO queue */
        int n=digits.length();
        List<String> res = new ArrayList<String>();
        if(n==0) return res;
        
        int[] dig = new int[n+1];
        for(int i=0;i<n;i++) dig[i]=digits.charAt(i)-48;

        res.add("");
        for(int i=0;i<n;i++)
        {
            String now = dict[dig[i]];
            List<String> tmp = new ArrayList<String>();
            for(int c=0;c<now.length();c++)
                for(int j=0;j<res.size();j++)
                    tmp.add(res.get(j).concat(now.substring(c,c+1)));
            res=tmp;
        }
        return res;
    }

    static int[] len = {1,0,3,3,3,3,3,4,3,4};
    static String[][] dict1 = {
        {" "," "," "," "},
        {" "," "," "," "},
        {"a","b","c"," "},
        {"d","e","f"," "},
        {"g","h","i"," "},
        {"j","k","l"," "},
        {"m","n","o"," "},
        {"p","q","r","s"},
        {"t","u","v"," "},
        {"w","x","y","z"},
        };
        
    public static List<String> letterCombinations1(String digits) { /* plain */
        int n=digits.length();
        if(n==0)
        {
            List<String> res = new ArrayList<String>();
            return res;
        }

        int[] dig = new int[n+1];
        int m=1;
        for(int i=0;i<n;i++)
        {
            dig[i]=(int)digits.charAt(i)-48;
        	m*=len[dig[i]];
        }
        List<String> res = new ArrayList<String>();
        for(int i=0;i<m;i++) res.add("");

        int flag=1;
        for(int i=0;i<n;i++)
        {
            System.out.println("i:"+i);
            int k=0,mark=0;
            for(int j=0;j<m;j++)
            {
                res.set(j,res.get(j).concat(dict1[dig[i]][mark]));
                k++;
                if(k==flag)
                {
                    k=0;
                    mark++;
                    if(mark==len[dig[i]]) mark=0;
                }
            }
            flag*=len[dig[i]];
        }

        return res;
    }

    public static void main(String[] args)
    {
    	String di= "23";
    	List<String> res = letterCombinations(di);
    	for(int i=0;i<res.size();i++)
    		System.out.println("i:"+i+" res[i]:"+res.get(i));
    }
}
