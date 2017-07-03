import java.util.*;

public class p60 {
    public String getPermutation(int n, int k) {
        if(n==1) return "1";
        int[] factorial = new int[n];
        factorial[0]=factorial[1]=1;
 		for(int i=2;i<n;i++)
 			factorial[i]=factorial[i-1]*i;

 		List<Integer> nums = new ArrayList<Integer>();
 		for(int i=0;i<n;i++) nums.add(i);

 		k--;
 		int idx=0;
 		char[] s = new char[n];
 		for(int i=n-1;i>=0;i--)
 		{
 			idx=k/factorial[i];
 			s[n-1-i]=(char)(nums.get(idx)+'1');
 			nums.remove(idx);
 			k%=factorial[i];
 		}
 		return new String(s);
    }
}
