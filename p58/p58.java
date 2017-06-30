public class p58 {
    public int lengthOfLastWord(String s) {
        int i=s.length()-1,ans=0;
        while(i>=0 && s.charAt(i)==' ') i--;
        while(i>=0 && s.charAt(i)!=' '){ i--; ans++; }
        return ans;
    }
}