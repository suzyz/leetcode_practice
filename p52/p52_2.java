import java.util.*;

public class p52_2 {

	public static int dfs(int cur,int colStatus,int diagStatus1,int diagStatus2,int n)
	{
		if(cur>=n)
			return 1;

		int sum=0,d1,d2;
		for(int j=0;j<n;j++)
			if(((1<<j)&colStatus)==0)
			{
				d1=cur+n-j;
				if((diagStatus1&(1<<d1))!=0) continue;
				d2=cur+j;
				if((diagStatus2&(1<<d2))!=0) continue;

				sum+=dfs(cur+1,colStatus|(1<<j),diagStatus1|(1<<d1),diagStatus2|(1<<d2),n);	
			}

		return sum;
	}

    public static int totalNQueens(int n) {
       	return dfs(0,0,0,0,n);
    }

    public static void main(String[] args) {
    	int n=4;
    	System.out.println("num:"+totalNQueens(n)); 
    }
}
