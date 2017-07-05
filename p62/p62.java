public class p62 {
    public int uniquePaths(int m, int n) {
        if(m>n) return uniquePaths(n,m);
        int[] f = new int[m+1];
        Arrays.fill(f,1);
        for(int j=1;j<n;j++)
        	for(int i=2;i<m;i++)
        		f[i]+=f[i-1];
        return f[m];
    }
}