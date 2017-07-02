import java.util.*;

public class p51 {
	public static List<String> convert(char[][] board)
	{
		List<String> res = new ArrayList<String>();
		for(int i=0;i<board.length;i++)
			res.add(new String(board[i]));
		return res;
	}

	public static void dfs(int cur,boolean[] busyCol,boolean[] busyDiag1,boolean[] busyDiag2,char[][] board,int n,List<List<String>> ans)
	{
		if(cur>=n)
		{
			ans.add(convert(board)); 
			return;
		}

		for(int j=0;j<n;j++)
			if(!busyCol[j])
			{
				int d1=cur+n-j,d2=cur+j;
				if(busyDiag1[d1] || busyDiag2[d2]) continue;

				board[cur][j]='Q';

				busyCol[j]=busyDiag1[d1]=busyDiag2[d2]=true;
				dfs(cur+1,busyCol,busyDiag1,busyDiag2,board,n,ans);

				board[cur][j]='.';
				busyCol[j]=busyDiag1[d1]=busyDiag2[d2]=false;		
			}
	}

    public static List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<List<String>>();
        char[][] board = new char[n][n];
        for(int i=0;i<n;i++)
        	Arrays.fill(board[i],'.');
        
       	dfs(0,new boolean[n],new boolean[2*n],new boolean[2*n],board,n,ans);
        
        return ans;
    }

    public static void main(String[] args) {
    	int n=4;
    	List<List<String>> ans = solveNQueens(n);
    	for(int i=0;i<ans.size();i++)
    	{
    		System.out.println();
    		for(int j=0;j<n;j++) System.out.println(ans.get(i).get(j));
    	}
    	System.out.println("num:"+ans.size()); 
    }
}
