import java.util.*;

public class p67 {
    public static String addBinary(String a, String b) {
        StringBuffer ans = new StringBuffer();

        int i=a.length()-1,j=b.length()-1,rem=0;
        while(i>=0 || j>=0 || rem>0)
        {
            if(i>=0) rem+=(int)a.charAt(i)-'0';
            if(j>=0) rem+=(int)b.charAt(j)-'0';

            ans.append((char)(rem%2+'0'));

            rem/=2;
            i--;
            j--;
        }

        return ans.reverse().toString();
    }

    public static void main(String[] args) {
        String a = "11";
        String b = "1";

        System.out.println(addBinary(a,b));
    }
}
