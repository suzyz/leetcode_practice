import java.util.*;

public class p52 {

	private static boolean[] busyCol = new boolean[100];
	private static boolean[] busyDiag1 = new boolean[200];
	private static boolean[] busyDiag2 = new boolean[200];

	public static int dfs(int cur,int n)
	{
		if(cur>=n)
			return 1;

		int sum=0;
		for(int j=0;j<n;j++)
			if(!busyCol[j])
			{
				int d1=cur+n-j,d2=cur+j;
				if(busyDiag1[d1] || busyDiag2[d2]) continue;

				busyCol[j]=busyDiag1[d1]=busyDiag2[d2]=true;
				sum+=dfs(cur+1,n);

				busyCol[j]=busyDiag1[d1]=busyDiag2[d2]=false;		
			}

		return sum;
	}

    public static int totalNQueens(int n) {
       	return dfs(0,n);
    }

    public static void main(String[] args) {
    	int n=4;
    	System.out.println("num:"+totalNQueens(n)); 
    }
}
