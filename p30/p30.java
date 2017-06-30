public class p30 {
    public List<Integer> findSubstring(String s, String[] words) {
        int n=s.length();
        int m=0;
        for(int i=0;i<words.length;i++) m+=words[i].length();

        List<Integer> ans = new ArrayList<Integer>();
        if(n<m) return ans;

        for(int i=0;i<=n-m;i++)
        {
        	s.subString(i,i+m);
        }
    }
}
